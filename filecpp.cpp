#include <iostream>
#include <fstream>
using namespace std;

struct nilai {
    float Mtk;
    float BIn;
    float Big;
    float IPA;
};

struct siswa {
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai;
};

float nilaiAkhir(nilai n) {
    return (n.Mtk * 0.4) + (n.IPA * 0.3) + (n.BIn * 0.2) + (n.Big * 0.2);
}

void tambahDataSiswa() {
    ofstream file("siswa.txt", ios::app);
    siswa s;
    cin.ignore();
    cout << "\nMasukkan Nama: ";
    getline(cin, s.nama);
    cout << "Masukkan NISN: ";
    getline(cin, s.NISN);
    cout << "Masukkan Jurusan: ";
    getline(cin, s.jurusan);
    cout << "Nilai Matematika: ";
    cin >> s.Nilai.Mtk;
    cout << "Nilai Bahasa Indonesia: ";
    cin >> s.Nilai.BIn;
    cout << "Nilai Bahasa Inggris: ";
    cin >> s.Nilai.Big;
    cout << "Nilai IPA: ";
    cin >> s.Nilai.IPA;
    file << s.nama << endl
         << s.NISN << endl
         << s.jurusan << endl
         << s.Nilai.Mtk << " " << s.Nilai.BIn << " " << s.Nilai.Big << " " << s.Nilai.IPA << endl;
    file.close();
    cout << "Data berhasil disimpan\n";
}

void tampilDataSiswa() {
    ifstream file("siswa.txt");
    if (!file.is_open()) {
        cout << "File belum ada atau belum ada data.\n";
        return;
    }
    siswa s;
    cout << "\n===== DATA SISWA =====\n";
    while (getline(file, s.nama)) {
        getline(file, s.NISN);
        getline(file, s.jurusan);
        file >> s.Nilai.Mtk >> s.Nilai.BIn >> s.Nilai.Big >> s.Nilai.IPA;
        file.ignore();
        cout << "Nama     : " << s.nama << endl;
        cout << "NISN     : " << s.NISN << endl;
        cout << "Jurusan  : " << s.jurusan << endl;
        cout << "Nilai Akhir : " << nilaiAkhir(s.Nilai) << endl;
        cout << "------------------------\n";
    }
    file.close();
}


int main() {
    int pilih;
    do {
        cout << "\n===== MENU DATA SISWA =====\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Data Siswa\n";
        cout << "3. Cari Siswa Berdasarkan NISN\n";
        cout << "4. Tampilkan Ranking\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilih;
        switch (pilih) {
            case 1: tambahDataSiswa(); 
                break;
            case 2: tampilDataSiswa(); 
                break;
            case 3: cariSiswa(); 
                break;
            case 4: ranking(); 
                break;
            case 5: cout << "Keluar dari program...\n";
                break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
    return 0;
}

