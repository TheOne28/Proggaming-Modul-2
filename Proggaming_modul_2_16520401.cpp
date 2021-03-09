#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
using ld = long double;
using ll = long long;

//Fungsi Operasi Hitung
void hitung(){
    while(!cin.eof()){
        string angka1, angka2;
        ld a, b, ans;
        char operasi;

        //Menerima masukan awal dan mengecek lanjut tidak
        cout << "Masukkan angka pertama: " << endl;
        cin >> angka1;
        if(angka1 == "END"){
            break;
        }

        //Pengolahan masukan apabila masih lanjut
        else{
            cout << "Masukkan angka kedua: " << endl;
            cin >> angka2;
            cout << "Masukkan operasi: " << endl;
            cin >> operasi;

            //Konversi string menjadi ld dan operasi hitung 
            a = stold(angka1);
            b = stold(angka2);

            if(operasi == 43){
            ans = a + b;
            }
            else if(operasi == 47){
                ans = a / b;
            }
            else if(operasi == 42){
                ans = a * b;
            }
            else if(operasi == 94){
                ans = pow(a, b);
            }
            else if(operasi == 45){
                ans = a -b ;
            }
            cout << "Hasil: " <<ans << endl;
        }
    }
}

// Fungsi Integral
void integral(){
    ll pangkat, partisi;
    //Vektor untuk menyimpan semua koefisien
    vector<ld>koefisien;
    ld a, b;

    //Menerima masukan
    cout << "Masukkan pangkat yang diinginkan: \n";
    cin >> pangkat;
    for(int i = 0; i <= pangkat; i ++){
        ld koe;
        cout <<"Koefisien x^"<< pangkat - i << ": ";
        cin >> koe;
        koefisien.push_back(koe);
    }
    cout << "Masukkan batas pengintegralan dengan diberi spasi: \n";
    cin >> a >> b;

    cout << "Masukkan banyak partisi: \n";
    cin >> partisi;

    ld luas = 0;
    ll suku = 0;

    while(suku < partisi){
        ld bag_x = a + (suku * (b-a) / partisi);
        ld bag_x_2 = a + ((suku + 1) * (b-a) /partisi);

        ld l1 = 0, l2 = 0;

        for(int i = 0; i <= pangkat; i ++){
            l1 += (pow(bag_x, (pangkat - i)) * koefisien[i]);
            l2 += (pow(bag_x_2, (pangkat - i)) * koefisien[i]);
        }
        luas += ((l1 + l2) * (bag_x_2 - bag_x))/2;
        suku ++;
    }
    cout << "Nilai Integral Tentu: " << luas << endl;
    
    /*
    Contoh penerapan -> Uji test case paling sederhana 3x^2 + 2x + 1
    */
}

int main(){
    //Output awal tentang manual dan petunjuk kalkulator
    cout << "Program Kalkulator Sederhana \n";
    cout << "Cara Penggunaan Kalkulator\n";
    cout << "1. Penulisan desimal menggunakan . tanpa spasi\n";
    cout << "2. Penulisan operasi hitung dan integral mengikuti petunjuk lebih lanjut\n";
    cout << "3. Ada 2 mode yang tersedia, operasi hitung dan integral\nSilahkan tulis huruf yang mewakili mode yang diinginkan\n\n";

    //Pemilihan mode
    cout << "Silahkan pilih mode kalkulator\nA. Operasi Hitung\nB. Integral Tentu\nMode: ";
    char mode;
    cin >> mode;
    if(mode == 'A'){
        cout <<"Silahkan masukkan angka pertama, kedua, dan lambang operasi.\nApabila ingin berhenti ketikkan END di angka pertama.\n";
        hitung();
    }

    else if(mode == 'B'){
        cout << "Silahkan masukkan derajat pangkat yang diinginkan.\nDilanjutkan memasukkan koefisien fungsi dari pangkat tertinggi (fungsi hanya fungsi pangkat).\nKemudian masukkan batas pengintegralan dan banyak partisi\n";
        integral();
    }
    
    cout << "Program Selesai" << endl; 
}