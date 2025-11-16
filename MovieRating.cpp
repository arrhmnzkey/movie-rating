#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

//sub-program untuk menambahkan film
void TambahFilm(string nama[], string genre[], float rating[], int &jumlah) {
    if (jumlah >= MAX) {
        cout << "Data sudah penuh!\n";
        return;
    }

    cout << "Masukkan nama film   : ";
    cin.ignore();
    getline(cin, nama[jumlah]);
    cout << "Masukkan genre film  : ";
    getline(cin, genre[jumlah]);
    cout << "Masukkan rating film : ";
    cin >> rating[jumlah];

    jumlah++;
    cout << "Film berhasil ditambahkan!\n";
}