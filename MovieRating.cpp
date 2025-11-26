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

    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nInput film ke-" << (i + 1) << endl;
        cout << "Masukkan nama film   : ";
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

//sub-program untuk mengurutkan rating
void UrutkanRating(string nama[], string genre[], float rating[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (rating[j] < rating[j + 1]) {
                swap(rating[j], rating[j + 1]);
                swap(nama[j], nama[j + 1]);
                swap(genre[j], genre[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan rating (tinggi → rendah).\n";
}

// Fungsi untuk mengubah seluruh huruf dalam string menjadi lowercase
string toLower(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        teks[i] = tolower(teks[i]);
    }
    return teks;
}

//sub-program untuk mencari nama film
int CariFilm(const string nama[], int jumlah, string targetNama) {
    targetNama = toLower(targetNama);  

    for (int i = 0; i < jumlah; i++) {
        if (toLower(nama[i]) == targetNama) {
            return i;   
        }
    }
    return -1; // tidak ditemukan
}

void TampilKategori(const string nama[], const float rating[], int jumlah) {
    if (jumlah == 0) {
        cout << "===============================================================\n";
        cout << "            BELUM ADA DATA FILM TERSEDIA\n";
        cout << "===============================================================\n";
        return;
    }

    cout << "\n===============================================================\n";
    cout << "               KATEGORI RATING FILM\n";
    cout << "===============================================================\n";

    cout << left 
         << setw(5)  << "No"
         << setw(30) << "Nama Film"
         << setw(12) << "Rating"
         << "Kategori" << endl;

    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < jumlah; i++) {
        string kategori;
        if (rating[i] >= 8.0) kategori = "Sangat Tinggi";
        else if (rating[i] >= 6.0) kategori = "Tinggi";
        else if (rating[i] >= 4.0) kategori = "Sedang";
        else kategori = "Rendah";

        cout << left
             << setw(5)  << i + 1
             << setw(30) << nama[i]
             << setw(12) << rating[i]
             << kategori << endl;
    }
    cout << "===============================================================\n";
}

//sub-program menghapus data film
void HapusFilm(string nama[], string genre[], float rating[], int &jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data untuk dihapus.\n";
        return;
    }

    cin.ignore();
    string target;
    cout << "Masukkan nama film yang ingin dihapus: ";
    getline(cin, target);

    int pos = CariFilm(nama, jumlah, target);
    if (pos == -1) {
        cout << "Film tidak ditemukan.\n";
        return;
    }

    for (int i = pos; i < jumlah - 1; i++) {
        nama[i] = nama[i + 1];
        genre[i] = genre[i + 1];
        rating[i] = rating[i + 1];
    }
    jumlah--;
    cout << "Film \"" << target << "\" berhasil dihapus!\n";
}

//Main Program
int main() {
    string nama[MAX];
    string genre[MAX];
    float rating[MAX];
    int jumlah = 10;  // karena kita menambah 10 data awal

    // ================== DATA FILM AWAL ==================
    nama[0] = "Inception";        genre[0] = "Sci-Fi";     rating[0] = 9.0;
    nama[1] = "Moana";            genre[1] = "Animation";  rating[1] = 7.2;
    nama[2] = "Interstellar";     genre[2] = "Sci-Fi";     rating[2] = 8.6;
    nama[3] = "Frozen";           genre[3] = "Animation";  rating[3] = 5.0;
    nama[4] = "Spider-Man";       genre[4] = "Action";     rating[4] = 6.4;
    nama[5] = "Horror Night";     genre[5] = "Horror";     rating[5] = 3.5;
    nama[6] = "Teen Romance";     genre[6] = "Romance";    rating[6] = 4.2;
    nama[7] = "Titanic";          genre[7] = "Romance";    rating[7] = 7.8;
    nama[8] = "Inside Out";       genre[8] = "Animation";  rating[8] = 8.1;
    nama[9] = "Bad Comedy";       genre[9] = "Comedy";     rating[9] = 2.4;
    // ====================================================

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
            case 3: UrutkanRating(nama, genre, rating, jumlah);
                    TampilkanFilm(nama, genre, rating, jumlah); break;
            case 4: {
                cin.ignore();
                string target;
                cout << "Masukkan nama film yang akan dicari: ";
                getline(cin, target);
                int idx = CariFilm(nama, jumlah, target);
                if (idx != -1)
                    cout << "Film ditemukan: " << nama[idx]
                            << " (" << genre[idx] << ") - "
                            << rating[idx] << endl;
                else
                    cout << "Film tidak ditemukan.\n";
                break;
            }
            case 5: TampilKategori(nama, rating, jumlah); break;
            case 6: HapusFilm(nama, genre, rating, jumlah); break;
            case 7: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);

    return 0;
}