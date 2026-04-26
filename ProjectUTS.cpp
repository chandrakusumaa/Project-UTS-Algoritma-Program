#include<iostream>
#include<string>
using namespace std;

struct node { //membuat struktur node
    string judul;
    string genre;
    string artis;
    double durasi;
    node* next;
    node* prev;
};

node* head = NULL; // global node head
node* current = NULL; // global node current

void insert(node*& head, node* baru) { // fungsi input data lagu yg baru
    if (head == NULL) { // kalau list lagu kosong
        head = baru;
        baru->next = baru;
        baru->prev = baru;
    } else {
        node* tail = head->prev; // kalau list lagu terisi

        tail->next = baru;
        baru->prev = tail;
        baru->next = head;
        head->prev = baru;
    }
}

void inputlagu(node*& head, int jumlah){ //fungsi input lagu
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
       
        cout << "Data lagu ke-" << i+1 << endl;
        node* baru = new node; //membuat node baru

        cout << "Judul lagu : ";// memasukan data lagu
        getline(cin, baru->judul);
        cout << "Genre lagu : ";
        getline(cin, baru->genre);
        cout << "Artis : ";
        getline(cin, baru->artis);
        cout << "Durasi lagu : ";
        cin >> baru->durasi;
        cin.ignore();

        insert(head,baru);// memanggil fungsi insert
    }

    cout << "\nLagu berhasil ditambahkan\n";

}
  
void tampilkan() {
    if (head == NULL) { //apakah ada data lagu atau tidak
        cout << "Tidak ada lagu\n";
        return;
    }
    node* temp = head; 
    int no = 1;
    do{ //pengulangan program untuk menampilkan seluruh data
        cout << "Lagu Ke-:\n" << no++;
        cout << "Judul  : " << temp->judul << endl;
        cout << "Artis  : " << temp->artis << endl;
        cout << "Genre  : " << temp->genre << endl;
        cout << "Durasi : " << temp->durasi << endl;
        temp = temp->next;

    }while(temp != head);
    
}

void hapusLagu() { //fungsi hapus lagu
    if (head == NULL) {
        cout << "Tidak ada lagu\n";
        return;
    }

    string dicari;
    cout << "Masukkan judul lagu: ";
    cin.ignore();
    getline(cin, dicari);

    node* temp = head;
    bool ditemukan = false;

    do {
        if (temp->judul == dicari) { //mengecek data lagu
            ditemukan = true; // jika data lagu ditemukan

            // jika hanya 1 node
            if (temp->next == temp) {
                head = NULL;
                current = NULL;
            } 
            else {
                //  update head jika yang dihapus head
                if (temp == head) {
                    head = head->next;
                }

                //  update current jika yang dihapus sedang diputar
                if (temp == current) {
                    current = temp->next;
                }

                //  sambung ulang node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "Lagu berhasil dihapus\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    // jika tidak ditemukan
    if (!ditemukan) {
        cout << "Lagu tidak ditemukan\n";
    }
}

namespace pemutaran{

void tampilkan(node* lagu){
    cout << "Memutar Lagu\n";
    cout << "Judul  : " << lagu->judul << endl;
    cout << "Artis  : " << lagu->artis << endl;
}

void playLagu() {
    if (head == NULL) { //jika list lagu kosong
        cout << "Tidak ada lagu!\n";
        return;
    }

    if (current == NULL) { //jika tidak ada lagu yang sedang diputar
        current = head;
    }

    tampilkan(current);

}

void playnext(){
    if (head == NULL) { //jika list lagu kosong
        cout << "Tidak ada lagu\n";
        return;
    }

    if (current == NULL) { //jika tidak ada lagu yang sedang diputar
        current = head;
    }else{
        current = current->next; //memutar lagu selanjutnya
    }

    tampilkan(current);

}

void playprev(){
    if (head == NULL) { //jika list lagu kosong
        cout << "Tidak ada lagu\n";
        return;
    }

    if (current == NULL) { //jika tidak ada lagu yang sedang diputar
        current = head;
    }else{
        current = current->prev;//memutar lagu sebelumnya
    }

    tampilkan(current);

}
}

namespace filterlagu{
bool filterGenre (node *n, string genre) {
    return n->genre == genre;
}


bool filterArtis (node *n, string artis) {
    return n->artis == artis;
}

void filterSong(bool (*kriteria)(node*, string), string value) {
    if (head == NULL) {
        cout << "Tidak ada lagu\n";
        return;
    }

    node* temp = head;
    bool ditemukan = false;

    do {
        if (kriteria(temp, value)) {
            cout << "\nJudul  : " << temp->judul << endl;
            cout << "Artis  : " << temp->artis << endl;
            cout << "Genre  : " << temp->genre << endl;
            cout << "Durasi : " << temp->durasi << endl;
            ditemukan = true;
        }
        temp = temp->next;
    } while (temp != head);

    if (!ditemukan) {
        cout << "Tidak ditemukan lagu\n";
    }
}
}