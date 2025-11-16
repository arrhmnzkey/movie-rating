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