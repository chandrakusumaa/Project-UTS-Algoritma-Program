#include<iostream>
#include<string>
using namespace std;

struct lagu{
    string judul;
    string genre;
    string artis;
    double durasi;
};

void inputlagu(lagu *l, int jumlah){
    for(int i = 0; i < jumlah; i++){
        cout << "Data lagu ke-" << i+1 << endl;
        cin.ignore();
        cout << "Judul lagu : ";
        getline(cin, l[i].judul);
        cout << "Genre lagu : ";
        getline(cin, l[i].genre);
        cout << "Artis : ";
        getline(cin, l[i].artis);
        cout << "Durasi lagu : ";
        cin >> l[i].durasi;
    }
}

inline void tampilkanlagu (lagu *l, int jumlah){ // fungsi inline ini untuk menampilkan seluruh data dari seluruh lagu
    for (int i = 0; i < jumlah; i++){
    cout << "\n Data lagu Ke-" << i+1 << endl;
    cout << "Judul lagu = " << l[i].judul << endl;
    cout << "Genre lagu = " << l[i].genre << endl;
    cout << "Artis = " << l[i].artis << endl;
    cout << "Durasi lagu = " << l[i].durasi << endl;
    cout << "nyoba push" << endl;
    }
}

void hapuslagu(lagu *l, int jumlah){ //fungsi ini untuk menghapus lagu
    string dicari;
    cout << "Judul lagu = ";
    cin.ignore();
    getline(cin, dicari);

    bool ditemukan = false;

    for(int i = 0; i <jumlah; i++){
        if(l[i].judul == dicari){ // bagian ini untuk mencari judul yg ingin di hapus
            ditemukan = true;

    }
if(!ditemukan){ // menapilkan jika judul tidak ditemukan
    cout << "Lagu Tidak Ditemukan" << endl;
};
}
}

