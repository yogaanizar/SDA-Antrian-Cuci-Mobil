#ifndef waktu_H
#define waktu_H
void defaultServiceTime(waktuCuci *serviceTimeQueue);
/*	fungsi	: Berfungsi untuk mengatur waktu antrian agar kembali ke awal */
void insertStartServiceTime(address *p, address q);
/*	fungsi	: Berfungsi untuk memasukan waktu start service dari setiap mobil 
			  yang dimana tergantung antara waktu terakhir mobil masuk atau waktu kedatangan mobil tersebut */		  
void updateRemainingServiceTime(address a, waktuCuci *serviceTimeQueue);
/*	fungsi	: Berfungsi untuk mengupdate waktu yang tersisa untuk mencuci mobil di setiap antrian */
bool checkTimeComeToPrevTimeCome(waktu waktuDatang, waktu prevTimeCome);
/*	fungsi	: Berfungsi untuk mengetahui apakah waktu kedatangan mobil yang baru kurang dari waktu kedatangan mobil sebelumnnya datang */			  
bool waktuValid(waktu WaktuDatang);
/*	fungsi	: Berfungsi untuk memverifikasi waktu yang diinput apakah sesuai dengan aturan jam dan menit yang sudah ditentukan atau tidak */
void waktuGanti(address *p);
/*	fungsi	: Berfungsi untuk menghitung waktu. misalkan jika menit melebihi 60 maka jam akan ditambah 1 */
int waktuJeda(address p);
/*	fungsi	: Berfungsi untuk menentukan durasi pencucian mobil sesuai tipe mobil */
bool remainingServiceTime(address p, address q, waktuCuci serviceTimeQueueA, waktuCuci serviceTimeQueueB);
/*	fungsi	: Berfungsi untuk mengetahui apakah waktu kedatanagn mobil yang baru masih bisa masuk kedalam 
			  antrian berdasarkan sisa waktu tempat cuci mobil */
bool cekWaktuDatang(waktu WaktuDatang);
/*	fungsi	: Bertujuan untuk mengecek waktu kedatangan mobil apakah sesuai jam operasional atau tidak */			
#endif
