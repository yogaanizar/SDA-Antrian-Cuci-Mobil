#ifndef kedua_H
#define kedua_H
void tampilQueue(address p, char queueMobil);
/*	fungsi	: Berfungsi untuk menampilkan antrian mobil */
void createNode (address *p);
/*	fungsi	: Berfungsi untuk membuat node baru */
void insertCar(address *p, address pnew, waktuCuci *serviceTimeQueueP);
/*	fungsi	: Berfungsi untuk menambahkan mobil ke antrian */
void Isi_Node (address *p , char nilai[],char PlatNo[], waktu WaktuDatang);
/*	fungsi	: Bertujuan untuk mengisi node dengan data yang user input */
bool isEmpty(address p);
/*	fungsi	: Bertujuan untuk mengecek apakah antrian kosong atau tidak */  
bool checkDecisionQueue(address a, address b);
/*	fungsi	: Berfungsi untuk menentukan mobil yang baru akan di masukan kedalam antrian yang mana, apakah itu a atau b */
void displayCurrentStatus(address p, char queueMobil);
/*	fungsi	: Berfungsi untuk menampilkan data mobil yang sedang di cuci */
bool changeDecisionStatusService(address p, waktu waktuDatang); 
/*	fungsi	: Berfungsi untuk menentukan apakah mobil yang sedang dicuci telah selesai berdasarkan waktu kedatangan mobil yang baru */
void updateStatusService(address *p, waktu waktuDatang);
/*	fungsi	: Berfungsi untuk menghapus node mobil yang telah selesai dicuci 
			  dari antrian tersebut (belum selesai: dan memindahkan node tersebut ke pointer lain) */
		  
#endif
