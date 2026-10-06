# <h1 align="center">Laporan Praktikum Modul 3 ABSTRACT DATA TYPE (ADT) </h1>

<p align="center">Muhammad Farrel Argiyanto - 109082500018</p>

## Dasar Teori

Abstract Data Type (ADT) merupakan tipe data yang terdiri dari sebuah tipe dan sekumpulan operasi dasar atau primitif yang dapat digunakan terhadap tipe tersebut. ADT digunakan untuk mendefinisikan data beserta operasi yang dapat dilakukan tanpa harus menjelaskan detail implementasinya. Dalam ADT juga dapat terdapat aturan atau batasan tertentu yang harus dipenuhi oleh data tersebut. 

Dalam implementasinya, ADT dapat menggunakan tipe data bentukan seperti `struct` pada C++. Operasi atau primitif pada ADT dapat dibuat dalam bentuk fungsi maupun prosedur. Beberapa jenis primitif yang terdapat pada ADT yaitu konstruktor atau kreator untuk membentuk nilai, selector untuk mengakses komponen, prosedur untuk mengubah nilai komponen, validator untuk memeriksa data, serta operasi baca dan tulis. 
ADT dapat diterapkan dengan memisahkan bagian spesifikasi dan implementasi program. Bagian spesifikasi berisi definisi tipe serta deklarasi fungsi atau prosedur dan biasanya ditempatkan pada file header `.h`. Sementara itu, realisasi fungsi dan prosedur ditulis pada file `.cpp`. Program utama atau `main.cpp` kemudian menggunakan fungsi dan tipe yang telah didefinisikan melalui interface tersebut. Pemisahan ini membuat program menjadi lebih terstruktur dan modular. 

Contoh penerapan ADT pada modul adalah ADT `mahasiswa` yang memiliki atribut `nim`, `nilai1`, dan `nilai2`. ADT tersebut memiliki prosedur untuk memasukkan data mahasiswa dan fungsi untuk menghitung nilai rata-rata. Modul juga menunjukkan bahwa deklarasi tipe dan fungsi dapat dipisahkan ke dalam file header, sedangkan implementasi fungsi diletakkan pada file `.cpp` dan digunakan melalui `main.cpp`. 

Dengan demikian, konsep ADT membantu mengelompokkan data dan operasi yang berkaitan sehingga program lebih terorganisasi. Penerapan ADT juga dapat digunakan untuk membuat program yang lebih modular karena bagian deklarasi, implementasi, dan program utama dapat dipisahkan sesuai fungsinya.

## Guided

### 1. ADT Mahasiswa
##### mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```
##### mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m)
{
    cout << "Input NIM = ";
    cin >> (m).nim;
    cout << "Input Nilai 1 = ";
    cin >> (m).nilai1;
    cout << "Input Nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m)
{
    return (m.nilai1 + m.nilai2) / 2;
}
```
##### main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata = " << rata2(mhs);
    return 0;
}

```

Program ini menerapkan konsep Abstract Data Type (ADT) Mahasiswa dengan memisahkan deklarasi struktur dan fungsi ke dalam file mahasiswa.h, implementasi fungsi ke mahasiswa.cpp, dan program utama ke main.cpp. ADT mahasiswa memiliki data nim, nilai1, dan nilai2. Fungsi inputMhs() digunakan untuk memasukkan data mahasiswa, sedangkan fungsi rata2() digunakan untuk menghitung nilai rata-rata dari dua nilai yang dimasukkan. Pemisahan file tersebut membuat program lebih terstruktur dan sesuai dengan konsep ADT.

## Unguided


### 1. Program Data Mahasiswa (menghitung nilai akhir)

Buat program yang dapat menyimpan data mahasiswa maksimal 10 data ke dalam sebuah array dengan field nama, NIM, UTS, UAS, tugas, dan nilai akhir. Nilai akhir diperoleh dari fungsi dengan rumus `0.3*uts + 0.4*uas + 0.3*tugas`.

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
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

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/Farrel-13/Laporan_Praktikum03/master/output/output01.png)

Program menggunakan struct Mahasiswa untuk menyimpan data mahasiswa dalam array dengan kapasitas maksimal 10 data. Setiap mahasiswa memiliki nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Fungsi hitungNilaiAkhir() digunakan untuk menghitung nilai akhir berdasarkan bobot yang telah ditentukan.

### 2. Buatlah ADT pelajaran sebagai berikut

##### pelajaran.h

```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```
##### pelajaran.cpp

```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;
pelajaran create_pelajaran(string namaMapel, string kodeMapel)
{
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "Nama Pelajaran: " << pel.namaMapel << endl;
    cout << "Kode Pelajaran: " << pel.kodeMapel << endl;
}
```
##### main.cpp

```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";

    pelajaran pel = create_pelajaran(namaMapel, kodeMapel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/Farrel-13/Laporan_Praktikum03/master/output/output02.png)

Program menerapkan konsep ADT pelajaran dengan memisahkan deklarasi tipe dan fungsi pada pelajaran.h, implementasi pada pelajaran.cpp, dan penggunaan ADT pada main.cpp. Fungsi create_pelajaran() digunakan untuk membuat data pelajaran, sedangkan prosedur tampil_pelajaran() digunakan untuk menampilkan nama dan kode mata pelajaran.

### 3. Array 2D dan Pointer Buat program dengan dua buah array 2D integer berukuran 3×3 dan dua buah pointer integer. Program memiliki fungsi atau prosedur untuk menampilkan isi array 2D dan fungsi atau prosedur untuk menukarkan isi dari dua array 2D pada posisi tertentu. Selain itu, program juga menukarkan isi dari variabel yang ditunjuk oleh dua pointer.


```C++
#include <iostream>
using namespace std;

void tampil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukar(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *pA = &A[0][0];
    int *pB = &B[0][0];

    cout << "Array A sebelum ditukar:" << endl;
    tampil(A);

    cout << "\nArray B sebelum ditukar:" << endl;
    tampil(B);

    tukar(A, B, 1, 1);

    cout << "\nArray A setelah pertukaran:" << endl;
    tampil(A);

    cout << "\nArray B setelah pertukaran:" << endl;
    tampil(B);

    tukarPointer(pA, pB);

    cout << "\nSetelah pertukaran pointer:" << endl;
    cout << "A[0][0] = " << A[0][0] << endl;
    cout << "B[0][0] = " << B[0][0] << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 1](https://raw.githubusercontent.com/Farrel-13/Laporan_Praktikum03/master/output/output03.png)

Program menggunakan dua array 2D berukuran 3×3 dan dua pointer bertipe integer. Prosedur tampilArray() digunakan untuk menampilkan isi array, sedangkan tukarArray() digunakan untuk menukar nilai pada posisi tertentu dari kedua array. Fungsi tukarPointer() digunakan untuk menukar nilai yang ditunjuk oleh dua pointer menggunakan operator dereference.

## Kesimpulan

Berdasarkan praktikum Modul 3 tentang Abstract Data Type (ADT), dapat disimpulkan bahwa ADT digunakan untuk mengelompokkan data dan operasi yang berkaitan sehingga program menjadi lebih terstruktur dan modular. Pada Guided, konsep ADT diterapkan dengan memisahkan deklarasi struct dan fungsi pada file .h, implementasi pada .cpp, serta program utama pada main.cpp.     Modul 03 STUKDAT Pada tiga latihan, konsep tersebut diterapkan melalui penyimpanan data mahasiswa dan perhitungan nilai akhir menggunakan fungsi, pembuatan ADT pelajaran dengan fungsi pembentuk dan prosedur penampil, serta penggunaan array 2D dan pointer untuk menampilkan dan menukar data. Dengan praktikum ini, konsep ADT, fungsi, prosedur, array, dan pointer dapat diterapkan untuk membuat program C++ yang lebih terorganisasi sesuai materi Modul 3.

## Referensi

[1] Sofa, M. M. F., & Prasetya, R. I. (2025). Sistem Manajemen Nilai Mahasiswa Berbasis Konsol Menggunakan C++: Pendekatan Prosedural Tipe Data Abstrak. Jurnal Aplikasi Teknologi dan Komputasi (JATEKOM), 1(4), 38–48. https://www.journals.arces.org/jatekom/article/view/191