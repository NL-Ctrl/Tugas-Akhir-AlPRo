#include <iostream>
#include <string>
#include "data.h"

using namespace std;

const int MAX_TUGAS = 100;

// Fungsi menentukan kuadran menggunakan Pointer & if-else
void tentukanKuadran(Tugas* t) {
    bool mendesak = (t->sisaHari <= 3); // Batas mendesak: 3 hari

    if (t->penting && mendesak) {
        t->kuadran = Q1_KERJAKAN;
    } else if (t->penting && !mendesak) {
        t->kuadran = Q2_JADWALKAN;
    } else if (!t->penting && mendesak) {
        t->kuadran = Q3_DELEGASIKAN;
    } else {
        t->kuadran = Q4_ELIMINASI;
    }
}

// Fungsi Input menggunakan Pointer ke Array & Pointer ke jumlah
void tambahTugas(Tugas* daftar, int* jumlah) {
    if (*jumlah >= MAX_TUGAS) {
        cout << "Daftar tugas sudah penuh!\n";
        return;
    }

    Tugas* t = &daftar[*jumlah]; // Pointer menunjuk slot array kosong
    cin.ignore(); // Membersihkan sisa enter dari menu

    cout << "\n--- Tambah Tugas Baru ---\n";
    cout << "Nama Tugas       : ";
    getline(cin, t->namaTugas);
    cout << "Mata Kuliah      : ";
    getline(cin, t->mataKuliah);
    cout << "Sisa Hari (angka): ";
    cin >> t->sisaHari;

    int pilihPenting;
    cout << "Apakah Penting? (1 = Ya, 0 = Tidak): ";
    cin >> pilihPenting;
    t->penting = (pilihPenting == 1);

    cout << "Estimasi Pengerjaan (jam): ";
    cin >> t->info.estimasiJam;

    t->status = BELUM_SELESAI;
    tentukanKuadran(t); // Otomatis klasifikasi kuadran

    (*jumlah)++; // Tambah total tugas lewat pointer
    cout << ">> Tugas berhasil ditambahkan!\n";
}

// Fungsi Output daftar tugas
void tampilkanTugas(Tugas* daftar, int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada tugas yang tersimpan.\n";
        return;
    }

    cout << "\n=== DAFTAR TUGAS MAHASISWA ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". [" << daftar[i].mataKuliah << "] " << daftar[i].namaTugas << "\n";
        cout << "   Deadline: " << daftar[i].sisaHari << " hari lagi | Kuadran: Q" << daftar[i].kuadran;
        cout << " | Estimasi: " << daftar[i].info.estimasiJam << " jam\n";
    }
}

int main() {
    Tugas daftarTugas[MAX_TUGAS]; // Array utama
    int jumlahTugas = 0;
    int pilihan;

    do {
        cout << "\n==============================\n";
        cout << "  DEADLINE TUGAS SORTER (CLI) \n";
        cout << "==============================\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Daftar Tugas\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahTugas(daftarTugas, &jumlahTugas);
                break;
            case 2:
                tampilkanTugas(daftarTugas, jumlahTugas);
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}