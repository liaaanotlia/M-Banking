#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

// Struct
struct Nasabah {
    string nama;
    int nomor_rekening;
    int saldo;
};

// Prototipe Function
void daftar_nasabah(vector<Nasabah>& nasabah_list);
void menabung(vector<Nasabah>& nasabah_list, stack<string>& riwayat_transaksi);
void penarikan(vector<Nasabah>& nasabah_list, stack<string>& riwayat_transaksi);
void cetak_daftar_nasabah(vector<Nasabah>& nasabah_list);
void cari_nasabah(vector<Nasabah>& nasabah_list);
void bubble_sort(vector<Nasabah>& nasabah_list);
void proses_antrian(queue<string>& antrian_transaksi);

// Program Utama
int main() {
    vector<Nasabah> nasabah_list;
    stack<string> riwayat_transaksi;
    queue<string> antrian_transaksi;
    int pilihan;

    do {
        cout << "======================" << endl;
        cout << "   Menu Transaksi" << endl;
        cout << "======================" << endl;
        cout << "1. Pendaftaran Nasabah" << endl;
        cout << "2. Menabung" << endl;
        cout << "3. Penarikan" << endl;
        cout << "4. Cetak Daftar Nasabah" << endl;
        cout << "5. Cari Nasabah" << endl;
        cout << "6. Proses Antrian Transaksi" << endl;
        cout << "7. Keluar" << endl;
        cout << "======================" << endl;
        cout << "Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                daftar_nasabah(nasabah_list);
                break;
            case 2:
                menabung(nasabah_list, riwayat_transaksi);
                break;
            case 3:
                penarikan(nasabah_list, riwayat_transaksi);
                break;
            case 4:
                cetak_daftar_nasabah(nasabah_list);
                break;
            case 5:
                cari_nasabah(nasabah_list);
                break;
            case 6:
                proses_antrian(antrian_transaksi);
                break;
            case 7:
                cout << "Terima Kasih Telah Bertransaksi Disini ..... " << endl;
                break;
            default:
                cout << "Pilihan Tidak Valid" << endl;
                break;
        }
    } while (pilihan != 7);

    return 0;
}

// Implementasi Function
void daftar_nasabah(vector<Nasabah>& nasabah_list) {
    Nasabah nasabah;
    cout << "Masukkan Nama Nasabah : ";
    cin.ignore();
    getline(cin, nasabah.nama);
    cout << "Masukkan Nomor Rekening Nasabah : ";
    cin >> nasabah.nomor_rekening;
    cout << "Masukkan Saldo Nasabah : ";
    cin >> nasabah.saldo;

    nasabah_list.push_back(nasabah);
    cout << "Pendaftaran Nasabah Berhasil" << endl;
}

void menabung(vector<Nasabah>& nasabah_list, stack<string>& riwayat_transaksi) {
    int nomor_rekening;
    int jumlah_tabungan;

    cout << "Masukkan Nomor Rekening Nasabah : ";
    cin >> nomor_rekening;

    auto it = find_if(nasabah_list.begin(), nasabah_list.end(), [nomor_rekening](const Nasabah& nasabah) {
        return nasabah.nomor_rekening == nomor_rekening;
    });

    if (it != nasabah_list.end()) {
        cout << "Masukkan Jumlah Tabungan : ";
        cin >> jumlah_tabungan;
        it->saldo += jumlah_tabungan;

        // Tambahkan transaksi ke dalam riwayat
        riwayat_transaksi.push("Menabung (Nomor Rekening: " + to_string(nomor_rekening) + ")");
        cout << "Menabung Berhasil" << endl;
    } else {
        cout << "Nasabah Tidak Ditemukan" << endl;
    }
}

void penarikan(vector<Nasabah>& nasabah_list, stack<string>& riwayat_transaksi) {
    int nomor_rekening;
    int jumlah_penarikan;

    cout << "Masukkan Nomor Rekening Nasabah : ";
    cin >> nomor_rekening;

    auto it = find_if(nasabah_list.begin(), nasabah_list.end(), [nomor_rekening](const Nasabah& nasabah) {
        return nasabah.nomor_rekening == nomor_rekening;
    });

    if (it != nasabah_list.end()) {
        cout << "Masukkan Jumlah Penarikan : ";
        cin >> jumlah_penarikan;

        if (it->saldo >= jumlah_penarikan) {
            it->saldo -= jumlah_penarikan;

            // Tambahkan transaksi ke dalam riwayat
            riwayat_transaksi.push("Penarikan (Nomor Rekening: " + to_string(nomor_rekening) + ")");
            cout << "Penarikan Berhasil" << endl;
        } else {
            cout << "Saldo Tidak Cukup" << endl;
        }
    } else {
        cout << "Nasabah Tidak Ditemukan" << endl;
    }
}

void cetak_daftar_nasabah(vector<Nasabah>& nasabah_list) {
    cout << "No. " << "| " << "Nama Nasabah " << "| " << "Nomor Rekening " << "| " << "Saldo " << endl;
    cout << "---------------------------------------------------------" << endl;

    for (size_t i = 0; i < nasabah_list.size(); i++) {
        cout << i + 1 << ". " << nasabah_list[i].nama << " | " << nasabah_list[i].nomor_rekening << " | " << nasabah_list[i].saldo << endl;
    }
}

void cari_nasabah(vector<Nasabah>& nasabah_list) {
    int nomor_rekening;

    cout << "Masukkan Nomor Rekening Nasabah yang ingin Anda Cari : ";
    cin >> nomor_rekening;

    auto it = find_if(nasabah_list.begin(), nasabah_list.end(), [nomor_rekening](const Nasabah& nasabah) {
        return nasabah.nomor_rekening == nomor_rekening;
    });

    if (it != nasabah_list.end()) {
        cout << "Nasabah Ditemukan" << endl;
        cout << "Nama Nasabah : " << it->nama << endl;
        cout << "Nomor Rekening : " << it->nomor_rekening << endl;
        cout << "Saldo : " << it->saldo << endl;
    } else {
        cout << "Nasabah Tidak Ditemukan" << endl;
    }
}

void bubble_sort(vector<Nasabah>& nasabah_list) {
    for (size_t i = 0; i < nasabah_list.size() - 1; i++) {
        for (size_t j = 0; j < nasabah_list.size() - i - 1; j++) {
            if (nasabah_list[j].nomor_rekening > nasabah_list[j + 1].nomor_rekening) {
                swap(nasabah_list[j], nasabah_list[j + 1]);
            }
        }
    }
}

void proses_antrian(queue<string>& antrian_transaksi) {
    while (!antrian_transaksi.empty()) {
        cout << "Mengproses transaksi: " << antrian_transaksi.front() << endl;
        antrian_transaksi.pop();
    }
    cout << "Proses antrian transaksi selesai." << endl;
}
