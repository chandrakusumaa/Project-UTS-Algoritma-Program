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

node* head = NULL;
node* current = NULL;

void inputlagu(int jumlah){
    
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

       if (head == NULL) { //jika data masih kosong
            head = baru;
            baru->next = baru;
            baru->prev = baru;
        } else { //jika sudah ada data
            node* tail = head->prev;

            tail->next = baru;
            baru->prev = tail;
            baru->next = head;
            head->prev = baru;
        }
    }

    cout << "\nLagu berhasil ditambahkan!\n";

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

void hapusLagu() {
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
        if (temp->judul == dicari) {
            ditemukan = true;

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

void playLagu() {
    if (head == NULL) { //jika list lagu kosong
        cout << "Tidak ada lagu!\n";
        return;
    }

    if (current == NULL) { //jika tidak ada lagu yang sedang diputar
        current = head;
    }

    cout << "Memutar Lagu\n";
    cout << "Judul  : " << current->judul << endl;
    cout << "Artis  : " << current->artis << endl;

}