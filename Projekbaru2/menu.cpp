#include "main.h"
int harga;

void simpanFileA(address *p){
	address temp;
	temp = *p;
	while(temp->next !=NULL){
		temp = temp->next;
	}
	FILE *RiwayatA;
	RiwayatA = fopen("riwayatA.txt","a+");
	fflush(stdin);
	fprintf(RiwayatA,"%s \t %s \t %d:%d \t   %d:%d \t\t %d:%d \t\t %d\n",temp->jenisMobil,temp->noPolisi,temp->waktuDatangMobil.jam,temp->waktuDatangMobil.menit,temp->startCuci.jam,temp->startCuci.menit,temp->endCuci.jam,temp->endCuci.menit,harga);
	fclose(RiwayatA);
}

void simpanFileB(address *p){
	address temp;
	temp = *p;
	while(temp->next !=NULL){
		temp = temp->next;
	}
	FILE *RiwayatB;
	fflush(stdin);
	RiwayatB = fopen("riwayatB.txt","a+");
	fprintf(RiwayatB,"%s \t %s \t %d:%d \t   %d:%d \t\t %d:%d \t\t %d \n",temp->jenisMobil,temp->noPolisi,temp->waktuDatangMobil.jam,temp->waktuDatangMobil.menit,temp->startCuci.jam,temp->startCuci.menit,temp->endCuci.jam,temp->endCuci.menit);
	fclose(RiwayatB);
}

	void menu(){
	waktu waktuDatang;
	waktu preTimeCome;
	preTimeCome.jam = 00;
	preTimeCome.menit = 00;
	waktuCuci serviceTimeA;
	waktuCuci serviceTimeB;
	defaultServiceTime(&serviceTimeA);
	defaultServiceTime(&serviceTimeB);
	dataMobil *a, *b, *tempA, *tempB;
	a = NULL;
	b = NULL;
	tempA = NULL;
	tempB = NULL;
	char car[1];
	char serviceCarName[2] = {'A', 'B'};
	char noPolisi[10];
	int pilih, uang, kembalian, sisa = 0;
	bool verifikasiTime, exit, checkCar, outProgram = false;
	
	
	
	while (!exit){
		system("cls");
//		warnateks(GREEN);
		printf("=======================================================================================================================\n");
		printf("|\t        #       # # # # #  # # # # #  #       #    #           #      #       # # # # #  #       #            |\n");
		printf("|\t      #   #     #          #       #   #     #      #         #     #   #     #          #       #            |\n");
		printf("|\t    ## # # ##   # # # # #  #       #    # # #        #   #   #    ## # # ##   # # # # #  # # # # #            |\n");
		printf("|\t   #         #  #       #  #       #      #           # # # #    #         #          #  #       #            |\n");
		printf("|\t   #         #  # # # # #  # # # # #      #            #   #     #         #  # # # # #  #       #            |\n");
		printf("|\t                                                                                                              |\n");
		printf("|\t\t\t\t\t   # # # # #       #       # # # # #                                          |\n");
		printf("|\t\t\t\t\t   #             #   #     #       #                                          |\n");
		printf("|\t\t\t\t\t   #           ## # # ##   #   # # #                                          |\n");
		printf("|\t\t\t\t\t   #          #         #  #     #                                            |\n");
		printf("|\t\t\t\t\t   # # # # #  #         #  #       #                                          |\n");
		printf("|                                                                                                                     |\n");
		printf("|\t\t  #           #  # # # # #  #          # # # # #  # # # # #  #         #  # # # # #                   |\n");
		printf("|\t\t   #         #   #          #          #          #       #  # #     # #  #                           |\n");
		printf("|\t\t    #   #   #    # # # # #  #          #          #       #  #   # #   #  # # # # #                   |\n");
		printf("|\t\t     # # # #     #          #          #          #       #  #         #  #                           |\n");
		printf("|\t\t      #   #      # # # # #  # # # # #  # # # # #  # # # # #  #         #  # # # # #                   |\n");
		printf("=======================================================================================================================\n");
		printf("|\t\t\t\t\t  |<>|     MENU PILIHAN     |<>|                                              |\n");
		printf("|\t\t\t\t\t  ==============================                                              |\n");
		printf("|\t\t\t\t\t  |1.| Menambah Mobil          |                                              |\n");
		printf("|\t\t\t\t\t  |2.| Menampilkan Antrian     |                                              |\n");
		printf("|\t\t\t\t\t  |3.| Status Pencucian        |                                              |\n");
		printf("|\t\t\t\t\t  |4.| Cara Penggunaan program |                                              |\n");
		printf("|\t\t\t\t\t  |5.| Histori Antrian         |                                              |\n");
		printf("|\t\t\t\t\t  |6.| Exit                    |                                              |\n");
	    printf("=======================================================================================================================\n");
		printf("| Pilih :  ");scanf("%d",&pilih);
		printf("|------------------------------------------------|\n");
		switch (pilih){
			case 1 :outProgram = false;
					while (outProgram == false){
						system("cls");
						printf("=======================================================================================================================\n");
		                printf("|\t        #       # # # # #  # # # # #  #       #    #           #      #       # # # # #  #       #            |\n");
		                printf("|\t      #   #     #          #       #   #     #      #         #     #   #     #          #       #            |\n");
		                printf("|\t    ## # # ##   # # # # #  #       #    # # #        #   #   #    ## # # ##   # # # # #  # # # # #            |\n");
		                printf("|\t   #         #  #       #  #       #      #           # # # #    #         #          #  #       #            |\n");
		                printf("|\t   #         #  # # # # #  # # # # #      #            #   #     #         #  # # # # #  #       #            |\n");
		                printf("|\t                                                                                                              |\n");
		                printf("|\t\t\t\t\t   # # # # #       #       # # # # #                                          |\n");
	                 	printf("|\t\t\t\t\t   #             #   #     #       #                                          |\n");
		                printf("|\t\t\t\t\t   #           ## # # ##   #   # # #                                          |\n");
		                printf("|\t\t\t\t\t   #          #         #  #     #                                            |\n");
		                printf("|\t\t\t\t\t   # # # # #  #         #  #       #                                          |\n");
		                printf("|                                                                                                                     |\n");
		                printf("|\t\t  #           #  # # # # #  #          # # # # #  # # # # #  #         #  # # # # #                   |\n");
		                printf("|\t\t   #         #   #          #          #          #       #  # #     # #  #                           |\n");
		                printf("|\t\t    #   #   #    # # # # #  #          #          #       #  #   # #   #  # # # # #                   |\n");
	                	printf("|\t\t     # # # #     #          #          #          #       #  #         #  #                           |\n");
		                printf("|\t\t      #   #      # # # # #  # # # # #  # # # # #  # # # # #  #         #  # # # # #                   |\n");
		                printf("=======================================================================================================================\n");
						printf("|\t\t\t\t\t  |<>| TENTUKAN PILIHANMU |<>|                                                 |\n");
						printf("|\t\t\t\t\t  ============================                                                 |\n");
						printf("|\t\t\t\t\t  |A.| Rp 50.000             |                                                 |\n");
						printf("|\t\t\t\t\t  |B.| Rp 100.000            |                                                 |\n");      
						printf("|\t\t\t\t\t  |C.| Rp 150.000            |                                                 |\n");
						printf("|\t\t\t\t    =======================================                                            |\n");
						pilihjenis :
						printf("|\t\t\t\t     Silahkan Masukan jenis mobil    (A/B/C)  : ");
						scanf("%s", &car);
						checkCar = false;
						while (checkCar  == false){
							if (strcmp(car, "A") == 00 || (strcmp(car, "a") == 00)){
								harga = 50000;
								checkCar = true;
							}
							else if (strcmp(car, "B") == 00 || (strcmp(car, "b") == 00)){
								harga = 100000;
								checkCar = true;
							}
							else if (strcmp(car, "C") == 00 || (strcmp(car, "c") == 00)){
								harga = 150000;
								checkCar = true;
							}
							else {
								goto pilihjenis;
							}
						}
						printf("Masukan Plat nomor mobil anda (ex : 547) : "); scanf(" %s", &noPolisi);
						bebas:
						printf("Silahkan Masukan waktu kedatangan mobil! \n");
						printf("Masukan Jam kedatangan mobil : "); scanf("%d", &waktuDatang.jam);
						printf("Masukan Menit kedatangan mobil : "); scanf("%d", &waktuDatang.menit);
						verifikasiTime = false;
						while (verifikasiTime == false){
							if (waktuValid(waktuDatang) == true){
								if (cekWaktuDatang(waktuDatang) == true){
									if (remainingServiceTime(a, b, serviceTimeA, serviceTimeB) == true){
										if (checkTimeComeToPrevTimeCome(waktuDatang, preTimeCome) == true){
											verifikasiTime = true;
										}
										else {
											printf("Ulangi pengisian karena waktu yang dimasukan tidak valid\n");
											goto bebas;
										}
									}
									else{
										printf("Semua Tempat pencucian hari ini telah Penuh !, Kembali lagi esok hari");
										outProgram = true;
										getch();
										break;
									}
								}
								else{
									printf("Ulangi pengisian karena waktu yang dimasukan tidak valid\n");
									goto bebas;
								}
							}
							else{
								printf("Ulangi pengisian karena waktu yang dimasukan tidak valid\n");
								goto bebas;
							}
						}
						printf(" untuk no polisi      : %s\n", &noPolisi);
						printf("dengan biaya sebesar  : %d\n", harga);
						kurangduid:
						printf("silahkan masukan hartamu : "); scanf("%d", &uang);
						sisa = sisa + uang;
						kembalian = sisa - harga;
						if (sisa < harga){
							printf("hartamu kurang : %d\n", -kembalian);
							goto kurangduid;
						}else if (sisa >= harga){
							printf("ini sisa hartamu : %d\n", kembalian);
						}sisa = 0;
						if (!isEmpty(a) || !isEmpty(b)){
							if (changeDecisionStatusService(a, waktuDatang) == true && changeDecisionStatusService(b, waktuDatang) == true){
								updateStatusService(&a, waktuDatang);
								updateStatusService(&b, waktuDatang);
							}
							else if (checkDecisionQueue(a, b) == true || changeDecisionStatusService(a, waktuDatang) == true){
									if (changeDecisionStatusService(a, waktuDatang) == true){
										updateStatusService(&a, waktuDatang);
									}
							}
							else {
								if (changeDecisionStatusService(b, waktuDatang) == true){
									updateStatusService(&b, waktuDatang);
								}	
							}
						}
						if (outProgram == true){
							break;
						}
						else{
							preTimeCome.jam = waktuDatang.jam;
							preTimeCome.menit = waktuDatang.menit;
							dataMobil *newCar;
							createNode(&newCar);
							Isi_Node(&newCar, car, noPolisi, waktuDatang);
							if (checkDecisionQueue(a, b) == true){
								insertCar(&a, newCar, &serviceTimeA);
								simpanFileA(&a);
							}
							else {
								insertCar(&b, newCar, &serviceTimeB);
								simpanFileB(&b);
							}
							printf("Penambahan mobil kedalam antrian berhasil!");
							getch();
							outProgram = true;
						}
					}
					break;
			case 2 :tampilQueue(a, serviceCarName[0]);
					printf("\n\n");
					tampilQueue(b, serviceCarName[1]);
					getch();
					break;
			case 3 :displayCurrentStatus(a, serviceCarName[0]);
					printf("\n\n");
					displayCurrentStatus(b, serviceCarName[1]);
					getch();
					break;
			case 4 :info();
					getch();
					break;
			case 5 :printf ("======== History AGOY CAR WASH ========\n\n\n");
					printf("Tempat Pencucian A\n");
					historiA();
					printf("\n");
					printf("Tempat Pencucian B\n");
					historiB();
					getch();
					break;
			case 6 :exit = true;
		}
	}
}

void info(){
	system("CLS");
	FILE *finfo;
		
		char text[200];
		if ((finfo = fopen ("info.txt", "rt")) == NULL) {
			printf ("Error! Opening File");
			exit(1);
		}
		
		else {
			while (fgets(text, sizeof(text), finfo) != NULL) {
				printf ("%s", text);
			}
			printf ("\n");
			
		}
}



void historiA(){
	char fileRiwayat[100];
	FILE *RiwayatA;
	RiwayatA = fopen("riwayatA.txt","r");
					
	rewind(RiwayatA);

		printf ("----------------------------------------------------------------------------\n");
		printf ("| Tipe Mobil | No Plat | Waktu Datang | Mulai Cuci | Selesai Cuci | harga |\n");
		printf ("----------------------------------------------------------------------------\n");
	fflush(stdin);
	while((fgets(fileRiwayat,sizeof(fileRiwayat),RiwayatA))!=NULL){
		printf("%s\t\n",fileRiwayat);
		fflush(stdin);
	}
	fclose(RiwayatA);
}

void historiB(){
	char fileRiwayat[100];
	FILE *RiwayatB;
	RiwayatB = fopen("riwayatB.txt","r");
					
	rewind(RiwayatB);

		printf ("-------------------------------------------------------------------\n");
		printf ("| Tipe Mobil | No Plat | Waktu Datang | Mulai Cuci | Selesai Cuci |\n");
		printf ("-------------------------------------------------------------------\n");
	fflush(stdin);
	while((fgets(fileRiwayat,sizeof(fileRiwayat),RiwayatB))!=NULL){
		printf("%s\t\n",fileRiwayat);
		fflush(stdin);
	}
	fclose(RiwayatB);
}
