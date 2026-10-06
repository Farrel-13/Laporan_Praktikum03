
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float nilai_akhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mahasiswa[10];
    int jumlah;

    cout << "Jumlah mahasiswa: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mahasiswa[i].nama;
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;

        mahasiswa[i].nilaiAkhir = nilai_akhir(
            mahasiswa[i].uts,
            mahasiswa[i].uas,
            mahasiswa[i].tugas
        );
    }

    cout << "\nData Mahasiswa\n";
    for (int i = 0; i < jumlah; i++) {
        cout << mahasiswa[i].nama << " "
             << mahasiswa[i].nim << " "
             << mahasiswa[i].nilaiAkhir << endl;
    }

    return 0;
}