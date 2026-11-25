#ifndef DATA_H
#define DATA_H

#include <string>
using namespace std;

// 1. ENUM: Kategori Kuadran & Status
enum Kuadran {
    Q1_KERJAKAN = 1,
    Q2_JADWALKAN = 2,
    Q3_DELEGASIKAN = 3,
    Q4_ELIMINASI = 4
};

enum Status {
    BELUM_SELESAI = 0,
    SELESAI = 1
};

// 2. UNION: Hemat memori (hanya 1 data aktif dalam satu waktu)
union InfoTambahan {
    int estimasiJam;   // Dipakai saat tugas BELUM_SELESAI
    float nilaiAkhir;  // Dipakai saat tugas SELESAI
};

// 3. STRUCT: Wadah utama satu tugas
struct Tugas {
    string namaTugas;
    string mataKuliah;
    int sisaHari;
    bool penting;
    Kuadran kuadran;
    Status status;
    InfoTambahan info;
};

#endif