#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;

//sub-program untuk menambahkan film
void TambahFilm(string nama[], string genre[], float rating[], int &jumlah) {
    if (jumlah >= MAX) {
        cout << "Data sudah penuh!\n";
        return;
    }

    int n;

    cout << "Berapa data film yang ingin dimasukkan? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nInput film ke-" << (i + 1) << endl;
        cout << "Masukkan nama film   : ";
        cin.ignore();
        getline(cin, nama[jumlah]);
        cout << "Masukkan genre film  : ";
        getline(cin, genre[jumlah]);
        cout << "Masukkan rating film : ";
        cin >> rating[jumlah];
        cin.ignore(); 

        jumlah++; 
    }
    cout << "\n>> " << n << " data film berhasil ditambahkan!\n";
}

//sub-program untuk menampilkan film
void TampilkanFilm(const string nama[], const string genre[], const float rating[], int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data film.\n";
        return;
    }

    cout << "\n==================== DAFTAR FILM ====================\n";
    cout << left
         << setw(5)  << "No"
         << setw(25) << "Nama Film"
         << setw(15) << "Genre"
         << setw(10) << "Rating"
         << endl;
    cout << "------------------------------------------------------\n";
    for (int i = 0; i < jumlah; i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(25) << nama[i]
             << setw(15) << genre[i]
             << setw(10) << rating[i]
             << endl;
    }
    cout << "======================================================\n";
}



int main() {
    string nama[MAX];
    string genre[MAX];
    float rating[MAX];
    int jumlah = 0;
    int pilihan;

    do {
        cout << "\n=== MENU FILM FAVORIT ===\n";
        cout << "1. Tambah Film\n";
        cout << "2. Tampilkan Semua Film\n";
        cout << "3. Urutkan Berdasarkan Rating\n";
        cout << "4. Cari Film\n";
        cout << "5. Tampilkan Kategori Rating\n";
        cout << "6. Hapus Film\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: TambahFilm(nama, genre, rating, jumlah); break;
            case 2: TampilkanFilm(nama, genre, rating, jumlah); break;
            
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);

    return 0;
}