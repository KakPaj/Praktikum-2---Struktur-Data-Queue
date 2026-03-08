#include <iostream>
#include <fstream>
using namespace std;

struct Customer;
struct Service;
int tutup = 0;

struct Customer
{
    string nama, gender, telepon, alamat, umur, kosong;
    Customer *next;
    Customer *prev;
    Service *headServ;
};

struct Service
{
    string tipeMobil, merekMobil, kendala, namaMontir, tanggal, kosong;
    string doneServ;
    Customer *dataCust;
    Service *allnext;
    Service *next;
    Service *allprev;
    Service *prev;
};

Customer *headCust = NULL;
Customer *tailCust = NULL;
Service *servHistory = NULL;
Service *tailHistory = NULL;
string nama;

void updateServ() // Function untuk menambahkan data service ke file Service2.txt
{ // Function untuk menambahkan data ke file Service2.txt
    ofstream fileServ("Service2.txt", ios::trunc);
    Service* serv = servHistory;
    while(serv != NULL)
    {
        if (serv -> dataCust != NULL) 
        {
            fileServ << serv -> dataCust -> nama << endl
                     << serv -> tipeMobil << endl
                     << serv -> merekMobil << endl
                     << serv -> kendala << endl
                     << serv -> namaMontir << endl
                     << serv -> tanggal << endl
                     << serv -> doneServ << endl
                     << serv -> kosong << endl;
        }
        serv = serv -> allnext;
    }
    fileServ.close();
}

void custHistory() // Function untuk menampilkan riwayat service customer berdasarkan input namanya
{
    system("cls");
    Customer* that = headCust;
    string inNama;
    cout << "====== Riwayat Service Anda ======" << endl
         << "Masukkan Nama: ";
    cin >> inNama;
    cout << endl << "====== Services ======" << endl;
    bool found = false;
    while (that != NULL)
    {
        if(that -> nama == inNama)
        {
            found = true;
            Service *serv = that -> headServ;
            while (serv != NULL)
            {
                cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                     << "Merek Mobil: " << serv -> merekMobil << endl
                     << "Kendala: " << serv -> kendala << endl
                     << "Nama Montir: " << serv -> namaMontir << endl
                     << "Tanggal Masuk: " << serv -> tanggal << endl
                     << "Nama Customer: " << that -> nama << endl
                     << "Nomor Telepon Customer: " << that -> telepon << endl;
                if (serv -> doneServ == "0") cout << "== Service Belum Selesai ==" << endl << "=============================" << endl;
                else cout << "== Service Sudah Selesai ==" << endl << "=============================" << endl;
                
                serv = serv -> next;
            } 
        }
        that = that -> next;
    }
    if (!found) cout << "Riwayat tidak ditemukan." << endl;
    system("pause");
}

void custBaru() // Function untuk menambahkan data customer baru
{
    system("cls");
    Service *servBaru = new Service();
    cout << "====== Input Data Customer ======" << endl;
    cout << "Nama Customer: ";
    getline(cin, nama);
    Customer *that = headCust;
    while (that != NULL)
    {
        if (that -> nama == nama)
            break;
        that = that -> next;
    }
    if (that == NULL)
    {
        Customer *custBaru = new Customer();

        cout << "Nomor Telepon: ";
        getline(cin, custBaru -> telepon);
        cout << "Alamat: ";
        getline(cin, custBaru -> alamat);
        cout << "Umur: ";
        getline(cin, custBaru -> umur);
        cout << "Gender: ";
        getline(cin, custBaru -> gender);
        if (headCust == NULL)
        {
            custBaru -> next = NULL;
            custBaru -> prev = NULL;
            custBaru -> headServ = NULL;
            headCust = tailCust = custBaru;
        }
        else
        {
            custBaru -> prev = tailCust;
            custBaru -> next;
            custBaru -> headServ = NULL;
            tailCust = custBaru;
        }
        custBaru -> headServ = servBaru;
        servBaru -> dataCust = custBaru;
        ofstream fileCust("Customer2.txt", ios::app);
        fileCust << nama << endl
                 << custBaru -> telepon << endl
                 << custBaru -> alamat << endl
                 << custBaru -> umur << endl
                 << custBaru -> gender << endl << endl;
        fileCust.close();
        cout << endl << "Pelanggan baru telah terdaftar" << endl;
        system("pause");
    }
    else
    {
        servBaru -> next = that -> headServ;
        that -> headServ = servBaru;
        servBaru -> dataCust = that;
        cout << endl << "Pelanggan sudah terdaftar sebelumnya" << endl;
        system("pause");
    }
}

void dataBaru() // Function untuk total data (servuce & customer) baru
{
    system("cls");
    Service *servBaru = new Service();
    cout << "====== Input Data Service ======" << endl;
    cout << "Tipe Mobil: ";
    getline(cin, servBaru -> tipeMobil);
    cout << "Merek Mobil: ";
    getline(cin, servBaru -> merekMobil);
    cout << "Kendala: ";
    getline(cin, servBaru -> kendala);
    cout << "Nama Montir | Suby | Farhan | Dimas | Aldo |: ";
    getline(cin, servBaru -> namaMontir);
    cout << "Tanggal Masuk Bengkel: ";
    getline(cin, servBaru -> tanggal);
    cout << "Nama Customer: ";
    getline(cin, nama);
    Customer *that = headCust;
    while (that != NULL)
    {
        if (that -> nama == nama)
            break;
        that = that -> next;
    }
    if (that == NULL)
    {
        Customer *custBaru = new Customer();
        
        custBaru -> nama = nama;
        cout << "Nomor Telepon: ";
        getline(cin, custBaru -> telepon);
        cout << "Alamat: ";
        getline(cin, custBaru -> alamat);
        cout << "Umur: ";
        getline(cin, custBaru -> umur);
        cout << "Gender: ";
        getline(cin, custBaru -> gender);
        if (headCust == NULL)
        {
            custBaru -> next = NULL;
            custBaru -> prev = NULL;
            custBaru -> headServ = NULL;
            headCust = tailCust = custBaru;
        }
        else
        {
            custBaru -> prev = tailCust;
            custBaru -> next;
            custBaru -> headServ = NULL;
            tailCust = custBaru;
        }
        custBaru -> headServ = servBaru;
        servBaru -> dataCust = custBaru;
        ofstream fileCust("Customer2.txt", ios::app);
        fileCust << nama << endl
                 << custBaru -> telepon << endl
                 << custBaru -> alamat << endl
                 << custBaru -> umur << endl
                 << custBaru -> gender << endl << endl;
        fileCust.close();
        cout << endl << "*Pelanggan baru telah terdaftar dan servis berhasil dicatat*" << endl;
        system("pause");
    }
    else
    {
        servBaru -> next = that -> headServ;
        that -> headServ = servBaru;
        servBaru -> dataCust = that;

        cout << endl << "*Pelanggan sudah terdaftar sebelumnya dan servis berhasil dicatat*" << endl;
        system("pause");
    }
    servBaru -> doneServ = "0";
    servBaru -> allnext = NULL;
    if (servHistory == NULL) 
    {
        servHistory = servBaru;
        tailHistory = servBaru;
    } 
    else 
    {
        tailHistory -> allnext = servBaru;
        servBaru -> allprev = tailHistory;
        tailHistory = servBaru;
    }
    updateServ();
}

void finishJob() // Function untuk menuntaskan service salah satu montir
{
    system("cls");
    string montirAktif[20]; 
    int jumlahMontir = 0;
    Service *serv = servHistory;
    while(serv != NULL)
    {
        if (serv -> doneServ == "0")
        {
            bool ada = false;
            for (int i = 0; i < jumlahMontir; i++)
            {
                if (montirAktif[i] == serv -> namaMontir)
                {
                    ada = true;
                    break;
                }
                
            }

            if(!ada)
            {
                montirAktif[jumlahMontir] = serv -> namaMontir;
                jumlahMontir++;
            }
        }
        serv = serv -> allnext;
    }
    if(jumlahMontir == 0)
    {
        cout << "====== Finish Job ======" << endl
             << "Tidak ada antrian servis yang pending saat ini." << endl;
        system("pause");
        return;
    }
    cout << "====== Finish Job ======" << endl
         << "Pilih Montir: " << endl;

    for (int i = 0; i < jumlahMontir; i++)
    {
        cout << i + 1 << ". " << montirAktif[i] << endl;
    }
    cout << "Pilihan: ";
    int pil;
    cin >> pil;
    if (pil < 1 || pil > jumlahMontir) 
    {
        cout << "Pilihan tidak valid!" << endl;
        system("pause");
        return;
    }
    string targetMontir = montirAktif[pil - 1];
    Service *servN = servHistory;
    bool adaIn = false;
    while (servN != NULL)
    {
        if (servN -> namaMontir == targetMontir && servN -> doneServ == "0")
        {
            adaIn = true;
            cout << endl << "====== Service ======" << endl
                 << "Tipe Mobil: " << servN -> tipeMobil << endl
                 << "Merek Mobil: " << servN -> merekMobil << endl
                 << "Kendala: " << servN -> kendala << endl
                 << "Nama Montir: " << servN -> namaMontir << endl
                 << "Tanggal Masuk: " << servN -> tanggal << endl
                 << "Nama Customer: " << servN -> dataCust -> nama << endl
                 << "Nomor Telepon Customer: " << servN -> dataCust -> telepon << endl
                 << "-----------------------------" << endl;

            cout << "Apakah servis ini sudah selesai? (Y/N): ";
            string jawaban;
            cin >> jawaban;

            if (jawaban == "y" || jawaban == "Y")
            {
                servN -> doneServ = "1";
                updateServ();
                cout << "Servis berhasil diselesaikan!" << endl;
            }
            else {
                cout << "Servis dibatalkan / belum diselesaikan." << endl;
            }
            break;
        }
        servN = servN -> allnext;
    }
    if (!adaIn) cout << endl << "Tidak ada antrian pekerjaan untuk montir " << targetMontir << "." << endl;
    system("pause");
}

void allServ() // Function untuk menampilkan semua service yang belum dituntaskan
{
    system("cls");
    Service *serv = servHistory;
    bool ada = false;
    cout << "====== All Services ======" << endl;
    while (serv != NULL)
    {
        if (serv -> doneServ == "0")
        {
            cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                 << "Merek Mobil: " << serv -> merekMobil << endl
                 << "Kendala: " << serv -> kendala << endl
                 << "Nama Montir: " << serv -> namaMontir << endl
                 << "Nama Customer: " << serv -> dataCust -> nama << endl
                 << "Nomor Telepon Customer: " << serv -> dataCust -> telepon << endl;
            serv -> doneServ;
            cout << "-----------------------------" << endl;  
            ada = true;
        }
        serv = serv -> allnext;
    }
    if(!ada)
    {
        cout << "Tidak service saat ini" << endl;
        cout << "-----------------------------" << endl;        
    }
    system("pause");
}

void queueServ() // Function untuk menampilkan antrian service
{
    system("cls");
    Service *serv = servHistory;
    bool antri = false;
    cout << "====== Service Queue ======" << endl;
    while (serv != NULL)
    {
        if(serv -> doneServ == "0")
        {
            cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                 << "Merek Mobil: " << serv -> merekMobil << endl
                 << "Kendala: " << serv -> kendala << endl
                 << "Nama Montir: " << serv -> namaMontir << endl
                 << "Nama Customer: " << serv -> dataCust -> nama << endl
                 << "Nomor Telepon Customer: " << serv -> dataCust -> telepon << endl
                 << "-----------------------------" << endl;
            antri = true;
        }
        serv = serv -> allnext;
    }
    if (!antri)
    {
        cout << "Tidak ada antrian service saat ini" << endl;
        cout << "-----------------------------" << endl;
    }
    system("pause");
}

void mechanicHistory() // Function untuk menampilkan riwayat tiap-tiap montir
{
    system("cls");
    string montirAktif[20];
    int jumlahMontir = 0;
    Service *serv = servHistory;
    while(serv != NULL)
    {
        bool ada = false;
        for (int i = 0; i < jumlahMontir; i++)
        {
            if (montirAktif[i] == serv -> namaMontir)
            {
                ada = true;
                break;
            }
        }
        if(!ada && serv -> namaMontir != "") 
        {
            montirAktif[jumlahMontir] = serv -> namaMontir;
            jumlahMontir++;
        }
        serv = serv -> allnext;
    }
    if (jumlahMontir == 0) 
    {
        cout << "====== Mechanic's Job History ======" << endl
             << "Belum ada riwayat kerja satupun di bengkel ini." << endl;
        system("pause");
        return;
    }
    cout << "====== Mechanic's Job History ======" << endl
         << "Pilih Menu: " << endl << endl;
    for (int i = 0; i < jumlahMontir; i++) 
    {
        cout << i + 1 << ". " << montirAktif[i] << endl;
    }
    cout << "Pilihan: ";
    int pil;
    cin >> pil;

    if (pil >= 1 && pil <= jumlahMontir) 
    {
        string targetMontir = montirAktif[pil - 1];
        cout << endl << "====== " << targetMontir << "'s Job History ======" << endl;

        bool ada = false;
        Service* serv = tailHistory;

        while (serv != NULL)
        {
            if (serv -> namaMontir == targetMontir)
            {
                ada = true;
                cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                     << "Merek Mobil: " << serv -> merekMobil << endl
                     << "Kendala: " << serv -> kendala << endl
                     << "Tanggal Masuk: " << serv -> tanggal << endl
                     << "Nama Customer: " << serv -> dataCust -> nama << endl 
                     << "-----------------------------" << endl;
            }
            serv = serv -> allprev;
        }

        if (!ada) cout << "Tidak ada pekerjaan." << endl;
        system("pause");
    }
    else if (pil == jumlahMontir + 1)
    {
        return;
    }
    else 
    {
        cout << "Pilihan tidak valid!" << endl;
        system("pause");
    }
}

void serviceMenu() // Function untuk menampilkan UI dari Service
{  
    int pil;
    while (pil != 5)
    {
        system("cls");
        cout << "====== Welcome to Lognuts, admin ======" << endl
             << "Pilih Menu: " << endl << endl
             << "1. Semua Service Singkat" << endl
             << "2. Service Baru" << endl
             << "3. Selesaikan Pekerjaan" << endl
             << "4. Riwayat Kerja" << endl 
             << "5. Keluar" << endl << endl
             << "Pilihan: ";
        cin >> pil;
        cin.ignore();
        if(pil == 1)
        {
            allServ();
        }
        else if(pil == 2)
        {
            dataBaru();
        }
        else if(pil == 3)
        {
            finishJob();
        }
        else if(pil == 4)
        {
            mechanicHistory();
        }
        else if(pil == 5)
        {
            return;
        } 
    }
}

void adminMenu() // Function untuk menampilkan UI dari Admin
{
    int pil;
    while (pil != 3)
    {
        system("cls");
        cout << "====== Welcome to Lognuts, admin ======" << endl
             << "Pilih Menu: " << endl << endl
             << "1. Service" << endl
             << "2. Pelanggan Baru" << endl 
             << "3. Keluar" << endl << endl
             << "Pilihan: ";
        cin >> pil;
        cin.ignore();
        if (pil == 1)
        {
            serviceMenu();
        }
        else if (pil == 2)
        {
            custBaru();
        }
    }
}

void Menu() // Function untuk menampilkan UI dari Menu
{
    string pil;
    system("cls");
    cout << "====== Welcome to Lognuts ======" << endl
         << "Pilih Menu! " << endl << endl
         << "1. Antrian Service" << endl
         << "2. Riwayat Service" << endl
         << "3. Keluar" << endl << endl
         << "Pilihan: ";
    cin >> pil;
    cin.ignore();
    if (pil == "1")
    {
        queueServ();
    }
    else if (pil == "2")
    {
        custHistory();
    }
    else if (pil == "3")
    {
        cout << endl << "====== Thank you for using Lognuts! ======";
        tutup = 1;
    }
    else if (pil == "adminacces8008")
    {
        adminMenu();
    }
}

int main() // And ofcourse, the main
{
    ifstream fileCust("Customer2.txt");
    string namaCust;
    while (getline(fileCust, namaCust)) 
    {
        if (namaCust == "") continue;
        Customer *custBaru = new Customer();
        custBaru -> nama = namaCust;       
        getline(fileCust, custBaru -> telepon);
        getline(fileCust, custBaru -> alamat);
        getline(fileCust, custBaru -> umur);
        getline(fileCust, custBaru -> gender);
        getline(fileCust, custBaru -> kosong);
        custBaru -> headServ = NULL;
        custBaru -> next = NULL;
        custBaru -> prev = NULL;
        if (headCust == NULL)
        {
            headCust = tailCust = custBaru;
        }
        else
        {
            tailCust -> next = custBaru;
            custBaru -> prev = tailCust;
            tailCust = custBaru;
        }
    }
    fileCust.close();

    ifstream fileServ("Service2.txt");
    string namaCustServ;
    while (getline(fileServ, namaCustServ)) 
    {
        if (namaCustServ == "") continue;
        Service *servBaru = new Service();
        getline(fileServ, servBaru -> tipeMobil);
        getline(fileServ, servBaru -> merekMobil);
        getline(fileServ, servBaru -> kendala);
        getline(fileServ, servBaru -> namaMontir);
        getline(fileServ, servBaru -> tanggal);
        getline(fileServ, servBaru -> doneServ);
        getline(fileServ, servBaru -> kosong);        
        servBaru -> allnext = NULL;
        servBaru -> next = NULL;
        servBaru -> prev = NULL;
        Customer* that = headCust;
        while(that != NULL)
        {
            if (that -> nama == namaCustServ)
                break;
            that = that -> next;
        }
        if (that != NULL)
        {
            servBaru -> next = that -> headServ;
            that -> headServ = servBaru;
            servBaru -> dataCust = that;
        }
        if (servHistory == NULL)
        {
            servHistory = servBaru;
            tailHistory = servBaru; 
        }
        else
        {
            tailHistory -> allnext = servBaru;
            servBaru -> allprev = tailHistory;
            tailHistory = servBaru;
        }
    }
    fileServ.close();
    while (tutup != 1)
    {
        Menu();
    }
    return 0;
}