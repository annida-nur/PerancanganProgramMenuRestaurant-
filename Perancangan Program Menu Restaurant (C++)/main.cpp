#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <fstream>

using namespace std;

void clear()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(_APPLE_)
    system("clear");
#endif
}
//prosedur pengurutan termahal s/d termurah
void mahalmurah(int arr[],string b[]) {
    int i,j,temp1;
    string temp2;

    for (i=1;i<15;i++){
        j=i;
            while (j>0 && arr[j-1]>arr[j]){
                temp1=arr[j];
                temp2=b[j];
                arr[j]=arr[j-1];
                b[j]=b[j-1];
                arr[j-1]=temp1;
                b[j-1]=temp2;
                j--;
            }
        }
    cout<<"     HARGA   \t\t ||           MENU"<<endl;
    for(j=15;j>0;j--)
        cout<<" Rp "<<arr[j-1]<<" 000,00-,\t\t || "<<b[j-1]<<endl;
}
//prosedur pengurutan termurah s/d termahal
void murahmahal(int arr[],string b[]) {
    int i,j,temp1;
    string temp2;

    for (i=1;i<15;i++){
        j=i;
            while (j>0 && arr[j-1]<arr[j]){
                temp1=arr[j];       //untuk harganya
                temp2=b[j];         //untuk menunya
                arr[j]=arr[j-1];
                b[j]=b[j-1];
                arr[j-1]=temp1;
                b[j-1]=temp2;
                j--;
            }
        }
    cout<<"     HARGA   \t\t ||           MENU"<<endl;
    for(j=15;j>0;j--)
        cout<<" Rp "<<arr[j-1]<<" 000,00-,\t\t || "<<b[j-1]<<endl;
}
//prosedur untuk menampilkan seluruh menu
void menu(string menu[],int harga[])
{
    cout<<"     HARGA   \t\t ||           MENU"<<endl;
    for(int i=0;i<15;i++)
        cout<<" Rp "<<harga[i]<<" 000,00-,\t\t || "<<menu[i]<<endl;
}
//prosedur text menu tiap kategori
void kategori(string kategori)
{
    cout<<"\t\t\t--------------------------------------------";
    cout<<"\n\t\t\t||========== MENU ANEKA "<<kategori<<" ==========||";
    cout<<"\n\t\t\t|| 1. CARI MENU                           ||";
    cout<<"\n\t\t\t|| 2. SELURUH MENU "<<"\t\t\t  ||";
    cout<<"\n\t\t\t|| 3. MENU HARGA TERTINGGI s/d TERENDAH   ||";
    cout<<"\n\t\t\t|| 4. MENU HARGA TERENDAH s/d TERTINGGI   ||";
    cout<<"\n\t\t\t|| 5. KEMBALI KE MENU UTAMA               ||"<<endl;
    cout<<"\t\t\t--------------------------------------------";
    cout<<"\nMasukan Pilihan : ";
}
//prosedur untuk keluar program
void keluar()
{
    clear();
    cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t||      TERIMAKASIH TELAH MENGGUNAKAN LAYANAN KAMI     ||"<<endl;
    cout<<"\t\t\t|| UNTUK PEMESANAN DAPAT DILAKUKAN DI MEJA RESEPSIONIS ||"<<endl;
    cout<<"\t\t\t||                                                     ||"<<endl;
    cout<<"\t\t\t||      KENYAMANAN PELANGGAN ADALAH PRIORITAS KAMI     ||"<<endl;
    cout<<"\t\t\t||         SAMPAI JUMPA DI KUNJUNGAN LAIN WAKTU        ||"<<endl;
    cout<<"\t\t\t||            SEMOGA HARI MU MENYENANGKAN :)           ||"<<endl;
    cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}
//prosedur untuk menulanjutan di setiap menu yang dipilih
void menulanjutan(string a)
{
    cout<<"\n\n||   MENU  || 1.KEMBALI KE MENU "<<a<<" || 2.KEMBALI KE MENU UTAMA || 3.KELUAR ||"<<endl;
    cout<<"\n|| Pilihan || : ";
}
//prosedur pencarian menu
void pencarianmenu(char cari[])
{
    int size=80;

    cout<<"\nMenu yang dicari : ";
    cin.ignore();cin.getline(cari,size);
    cari[0]=toupper(cari[0]);
    for(int i=1;i<size;i++){
        if(cari[i-1]==' ')
            cari[i]= toupper(cari[i]);
        else
            cari[i]= tolower(cari[i]);
    }
}
//fungsi untuk pencarian di tiap kategori dengan sequential search
int sequential_search(string data[], string data_dicari)
{
    int posisi, i, ketemu;

    if(15<=0)
        posisi=1;
    else{
        ketemu=0;
        i=0;
        while((i<=15-1) && !ketemu){
            if (data[i]==data_dicari){
                posisi=i;
                ketemu=1;
            }//end of if conditional
            else{
                i++;
            }//end of else

            if(!ketemu){
                posisi = -1;
            }
        }//end of while conditional
    }//end of else

    return posisi;
}
//fungsi utama
int main()
{
    //Deklarasi menu aneka indomie dan harganya
    string indomie[]={"Indomie Telur","Indomie Tongkol Balado","Indomie Telur Kornet","Indomie Kornet","Indomie Telur Kornet Keju",
                "Indomie Saus Keju","Indomie Tektek Si Mamang","Indomie Saus Telur Asin","Indomie Telur Sambal Matah","Indomie Khas Medan",
                "Indomie Sadis Mampus(Lvl 1-5)","Indomie Telur Nuklir(Lvl 1-5)","Indomie Telur Sambal Hitam","Indomie Telur Sambal Terasi",
                "Indomie Chili (Chicken/Beef)"};
    int hargaIndomie[]={11,20,17,17,19,19,18,18,18,18,15,17,17,17,23};

    //Deklarasi menu aneka nasi dan harganya
    string nasi[]={"Nasi Kulit + Telur Sambal Konslet","Nasi Telur + Ayam Penyet Sambal Matah","Nasi Bakso + Telur Sambal Domba",
                    "Nasi Bakso + Telur Saus Mushroom","Nasi Bakar + Bakso Cocolan","Nasi Bakso + Telur Sambal Matah","Nasi Tanggal Tua + 2 Telur",
                    "Nasi Tongkol Balado + Telur","Nasi Sosis Mentega Blackpepper","Nasi Telur + Chili(Chicken/Beef)","Nasi Telur + Rending",
                    "Nasi Wagyu Slice Saus Mentega + Telur","Nasi Wagyu Slice Saus Mushroom + Telur","Nasi Wagyu Slice Sambal Konslet + Telur",
                    "Nasi Wagyu Slice Sambal Domba + Telur"};
    int hargaNasi[]={23,25,26,26,22,26,16,25,28,29,27,37,37,37,37};

    //Deklarasi menu aneka dessert dan harganya
    string dessert[]={"Pisang Bakar Brownsugar","Pisang Bakar Coklat","Pisang Bakar Milo","Pisang Bakar Susu Keju","Pisang Bakar Greeantea",
                "Pisang Bakar Ice Cream Vanilla","Roti Telur","Roti Susu Coklat","Roti Nuttela+Greentea","Roti Nuttela","Roti Butter Special Keju",
                "Roti Taro","Roti Banana Powder","Alpukat +Greentea Kerok","Alpulkat+Milo Kerok","Orange Blaster"};
    int hargaDessert[]={17,17,17,18,18,21,15,17,23,20,23,19,19,30,30};

    //Deklarasi menu aneka extra dan harganya
    string extra[]={"Nasi Putih","Topping Telur","Topping Saos Blackpepper","Topping Smoked Beef","Topping Sambal (Konslet/Matath/Domba)","Topping Kornet","Topping Telur Kornet",
                "Topping Milo","Topping Greentea","Topping Brownsugar","Topping Ice Cream Vanilla","Topping Lychee(3buah)","Topping Langan(3buah)","Cireng Pedas Manis","Sosis Bakar+ Telur Saus Blackpepper","Topping Keju Parut","Topping Kulit"};
    int hargaExtra[]={5,5,8,4,5,8,9,5,9,4,8,8,8,27,35,10,14};

    //Deklarasi menu aneka minuman dan harganya
    string minuman[]={"Americano Coffe","Gatot Kaca Cold Brew Coffe","Susu Manga",
                "Susu Tiramisu","Susu Mint","Ice Lychee","Ice Jeruk","Ice Anggur","Taro Latte","Banana Latte","Greentea Frappe","Mocha Frappe",
                "Caramel Frappe","Java Chips Frappe","Avocado Frappe"};
    int hargaMinuman[]={19,28,16,16,16,15,15,15,15,15,27,27,27,27,27};

    int menu1;
    int pilihmenu;
    int pilihan;
    int size=80;
    char carimenu[size];

    menuutama:
    cout<<"\t\t----------------------------------------------------"<<endl;
    cout<<"\t\t||               SELAMAT DATANG                   ||"<<endl;
    cout<<"\t\t||               WARUNG AMBYARR                   ||"<<endl;
    cout<<"\t\t|| WARUNG YANG MEMBUAT HIDUP MU GAK MAKIN AMBYARR ||"<<endl;
    cout<<"\t\t----------------------------------------------------"<<endl;
    cout<<"\n\t\t\t--------------------------";
    cout<<"\n\t\t\t||===== MENU UTAMA =====||";
    cout<<"\n\t\t\t|| 1. ANEKA INDOMIE     ||";
    cout<<"\n\t\t\t|| 2. ANEKA NASI        ||";
    cout<<"\n\t\t\t|| 3. ANEKA DESSERT     ||";
    cout<<"\n\t\t\t|| 4. ANEKA EXTRA       ||";
    cout<<"\n\t\t\t|| 5. ANEKA MINUMAN     ||";
    cout<<"\n\t\t\t|| 6. KELUAR            ||";
    cout<<"\n\t\t\t--------------------------"<<endl;
    cout<<"\nMasukan pilihan menu : ";cin>>pilihmenu;

    if(pilihmenu==1)
    {
        clear();
        menuindomie:
        string kategori1="INDOMIE";
        kategori(kategori1);cin>>menu1;

        fstream file;
        file.open("Referensi Menu Tambahan Indomie.txt",ios::app);

        switch(menu1)
        {
        case 1:
            {
                clear();
                cout<<"\n\t\t=========PENCARIAN MENU ANEKA INDOMIE=========\n"<<endl;
                pencarianmenu(carimenu);
                int posisi=sequential_search(indomie,carimenu);
                cout<<"Hasil Pencarian Menu : "<<endl;
                if(posisi != -1)
                {
                    cout<<"\n     HARGA   \t\t ||           MENU"<<endl;
                    cout<<" Rp "<<hargaIndomie[posisi]<<" 000,00-,\t\t || "<<indomie[posisi]<<endl;
                }else{
                    file<<"-> "<<carimenu<<endl;
                    cout<<"\nMenu "<<carimenu<<" tidak ada di menu aneka indomie"<<endl;
                }

                menulanjutan(kategori1);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuindomie;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 2:
            {
                clear();
                cout<<"\n\t===DAFTAR SELURUH MENU ANEKA INDOMIE===\n"<<endl;
                menu(indomie,hargaIndomie);menulanjutan(kategori1);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuindomie;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 3:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU INDOMIE HARGA TERTINGGI s/d TERENDAH===\n"<<endl;
                mahalmurah(hargaIndomie,indomie);menulanjutan(kategori1);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuindomie;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 4:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU INDOMIE HARGA TERENDAH s/d TERTINGGI===\n"<<endl;
                murahmahal(hargaIndomie,indomie);menulanjutan(kategori1);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuindomie;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 5:
            clear();
            goto menuutama;break;
        default :
            clear();
            cout<<"Maaf. Pilihan yang anda masukan tidak tersedia."<<endl;
            goto menuindomie;break;
        }
    }

    else if(pilihmenu==2)
    {
        clear();
        menunasi:
        string kategori2=" NASI  ";
        kategori(kategori2);cin>>menu1;

        fstream file;
        file.open("Referensi Menu Tambahan Nasi.txt",ios::app);

        switch(menu1)
        {
        case 1:
            {
                clear();
                cout<<"\n\t\t=========PENCARIAN MENU ANEKA NASI=========\n"<<endl;
                pencarianmenu(carimenu);
                int posisi=sequential_search(nasi,carimenu);
                cout<<"Hasil Pencarian Menu : "<<endl;
                if(posisi != -1)
                {
                    cout<<"\n     HARGA   \t\t ||           MENU"<<endl;
                    cout<<" Rp "<<hargaNasi[posisi]<<" 000,00-,\t\t || "<<nasi[posisi]<<endl;
                }else{
                    file<<"-> "<<carimenu<<endl;
                    cout<<"\nMenu "<<carimenu<<" tidak ada di menu aneka nasi"<<endl;
                }

                menulanjutan(kategori2);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menunasi;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 2:
            {
                clear();
                cout<<"\n\t===DAFTAR SELURUH MENU ANEKA NASI===\n"<<endl;
                menu(nasi,hargaNasi);menulanjutan(kategori2);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menunasi;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 3:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU NASI HARGA TERTINGGI s/d TERENDAH===\n"<<endl;
                mahalmurah(hargaNasi,nasi);menulanjutan(kategori2);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menunasi;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 4:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU NASI HARGA TERENDAH s/d TERTINGGI===\n"<<endl;
                murahmahal(hargaNasi,nasi);menulanjutan(kategori2);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menunasi;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 5:
            clear();
            goto menuutama;break;
        default :
            clear();
            cout<<"Maaf. Pilihan yang anda masukan tidak tersedia."<<endl;
            goto menunasi;break;
        }
    }

    else if(pilihmenu==3)
    {
        clear();
        menudessert:
        string kategori3="DESSERT";
        kategori(kategori3);cin>>menu1;

        fstream file;
        file.open("Referensi Menu Tambahan Dessert.txt",ios::app);

        switch(menu1)
        {
        case 1:
            {
                clear();
                cout<<"\n\t\t=========PENCARIAN MENU ANEKA DESSERT=========\n"<<endl;
                pencarianmenu(carimenu);
                int posisi=sequential_search(dessert,carimenu);
                cout<<"Hasil Pencarian Menu : "<<endl;
                if(posisi != -1)
                {
                    cout<<"\n     HARGA   \t\t ||           MENU"<<endl;
                    cout<<" Rp "<<hargaDessert[posisi]<<" 000,00-,\t\t || "<<dessert[posisi]<<endl;
                }else{
                    file<<"-> "<<carimenu<<endl;
                    cout<<"\nMenu "<<carimenu<<" tidak ada di menu aneka dessert"<<endl;
                }


                menulanjutan(kategori3);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menudessert;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 2:
            {
                clear();
                cout<<"\n\t===DAFTAR SELURUH MENU ANEKA DESSERT===\n"<<endl;
                menu(dessert,hargaDessert);menulanjutan(kategori3);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menudessert;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 3:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU DESSERT HARGA TERTINGGI s/d TERENDAH===\n"<<endl;
                mahalmurah(hargaDessert,dessert);menulanjutan(kategori3);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menudessert;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 4:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU DESSERT HARGA TERENDAH s/d TERTINGGI===\n"<<endl;
                murahmahal(hargaDessert,dessert);menulanjutan(kategori3);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menudessert;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 5:
            clear();
            goto menuutama;break;
        default :
            clear();
            cout<<"Maaf. Pilihan yang anda masukan tidak tersedia."<<endl;
            goto menudessert;break;
        }
    }

    else if(pilihmenu==4)
    {
        clear();
        menuextra:
        string kategori4=" EXTRA ";
        kategori(kategori4);cin>>menu1;

        fstream file;
        file.open("Referensi Menu Tambahan Extra.txt",ios::app);

        switch(menu1)
        {
        case 1:
            {
                clear();
                cout<<"\n\t\t=========PENCARIAN MENU ANEKA EXTRA=========\n"<<endl;
                pencarianmenu(carimenu);
                int posisi=sequential_search(extra,carimenu);
                cout<<"Hasil Pencarian Menu : "<<endl;
                if(posisi != -1)
                {
                    cout<<"\n     HARGA   \t\t ||           MENU"<<endl;
                    cout<<" Rp "<<hargaExtra[posisi]<<" 000,00-,\t\t || "<<extra[posisi]<<endl;
                }else{
                    file<<"-> "<<carimenu<<endl;
                    cout<<"\nMenu "<<carimenu<<" tidak ada di menu aneka extra"<<endl;
                }

                menulanjutan(kategori4);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuextra;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 2:
            {
                clear();
                cout<<"\n\t===DAFTAR SELURUH MENU ANEKA EXTRA===\n"<<endl;
                menu(extra,hargaExtra);menulanjutan(kategori4);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuextra;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 3:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU EXTRA HARGA TERTINGGI s/d TERENDAH===\n"<<endl;
                mahalmurah(hargaExtra,extra);menulanjutan(kategori4);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuextra;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 4:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU EXTRA HARGA TERENDAH s/d TERTINGGI===\n"<<endl;
                murahmahal(hargaExtra,extra);menulanjutan(kategori4);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuextra;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 5:
            clear();
            goto menuutama;break;
        default :
            clear();
            cout<<"Maaf. Pilihan yang anda masukan tidak tersedia."<<endl;
            goto menuextra;break;
        }
    }

    else if(pilihmenu==5)
    {
        clear();
        menuminuman:
        string kategori5="MINUMAN";
        kategori(kategori5);cin>>menu1;

        fstream file;
        file.open("Referensi Menu Tambahan Minuman.txt",ios::app);

        switch(menu1)
        {
        case 1:
            {
                clear();
                cout<<"\n\t\t=========PENCARIAN MENU ANEKA MINUMAN=========\n"<<endl;
                pencarianmenu(carimenu);
                int posisi=sequential_search(minuman,carimenu);
                cout<<"Hasil Pencarian Menu : "<<endl;
                if(posisi != -1)
                {
                    cout<<"\n     HARGA   \t\t ||           MENU"<<endl;
                    cout<<" Rp "<<hargaMinuman[posisi]<<" 000,00-,\t\t || "<<minuman[posisi]<<endl;
                }else{
                    file<<"-> "<<carimenu<<endl;
                    cout<<"\nMenu "<<carimenu<<" tidak ada di menu aneka minuman"<<endl;
                }

                menulanjutan(kategori5);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuminuman;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 2:
            {
                clear();
                cout<<"\n\t===DAFTAR SELURUH MENU ANEKA MINUMAN===\n"<<endl;
                menu(minuman,hargaMinuman);menulanjutan(kategori5);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuminuman;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 3:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU MINUMAN HARGA TERTINGGI s/d TERENDAH===\n"<<endl;
                mahalmurah(hargaMinuman,minuman);menulanjutan(kategori5);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuminuman;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 4:
            {
                clear();
                cout<<"\n\t===DAFTAR MENU MINUMAN HARGA TERENDAH s/d TERTINGGI===\n"<<endl;
                murahmahal(hargaMinuman,minuman);menulanjutan(kategori5);cin>>pilihan;
                if(pilihan==1){
                    clear();
                    goto menuminuman;
                }else if(pilihan==2){
                    clear();
                    goto menuutama;
                }else{
                    keluar();
                    return 0;}
            }break;

        case 5:
            clear();
            goto menuutama;break;
        default :
            clear();
            cout<<"Maaf. Pilihan yang anda masukan tidak tersedia."<<endl;
            goto menuminuman;break;
        }
    }

    else if(pilihmenu==6){
        keluar();
        return 0;
    } else{
        clear();
        cout<<"\nMOHON MAAF PILIHAN MENU YANG ANDA PILIH TIDAK TERSEDIA"<<endl;
        cout<<"\n\nMENU :\t1.KEMBALI KE MENU UTAMA\t\t2.KELUAR"<<endl;
        cout<<"Pilihan  : ";cin>>pilihan;
        if(pilihan==1){
            clear();
            goto menuutama;
        }else{
            keluar();
            return 0;}
    }

    return 0;
}
