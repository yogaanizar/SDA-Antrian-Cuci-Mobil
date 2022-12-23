#include "main.h"

void createNode (address *p){
	*p = (address)malloc(sizeof(dataMobil));
	if(p != NULL){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
	}else{
		printf("Gagal Alokasi\n");
	}
	
}

bool isEmpty(address p){
	
	if(p == NULL){
		return true;
	}else{
		return false;
	}
}

void insertCar(address *p, address pnew, waktuCuci *serviceTimeQueueP){
	address temp;
	temp = *p;
	if(pnew->waktuDatangMobil.jam < 7){
		if(isEmpty(*p) || !isEmpty(*p)){
		pnew->startCuci.jam = 7;
		pnew->startCuci.menit = 0;
		}pnew->endCuci.menit = pnew->startCuci.menit + waktuJeda(pnew);
		pnew->endCuci.jam = pnew->startCuci.jam;
		waktuGanti(&pnew);
		updateRemainingServiceTime(pnew, &(*serviceTimeQueueP));
		*p = pnew;	
}
	else if (isEmpty(*p)){
		pnew->startCuci.jam = pnew->waktuDatangMobil.jam;
		pnew->startCuci.menit = pnew->waktuDatangMobil.menit;
		pnew->endCuci.menit = pnew->startCuci.menit + waktuJeda(pnew);
		pnew->endCuci.jam = pnew->startCuci.jam;
		waktuGanti(&pnew);
		updateRemainingServiceTime(pnew, &(*serviceTimeQueueP));
		*p = pnew;
	}
	else{
		while ((temp)->next != NULL){
			temp = temp->next;
		}
		insertStartServiceTime(&pnew,temp);
		if (pnew->startCuci.menit >= 60){
			pnew->startCuci.jam = pnew->startCuci.jam + 1;
			pnew->startCuci.menit = pnew->startCuci.menit - 60;
		}
		pnew->endCuci.menit = pnew->startCuci.menit + waktuJeda(pnew);
		pnew->endCuci.jam = pnew->startCuci.jam;
		waktuGanti(&pnew);
		updateRemainingServiceTime(pnew, &(*serviceTimeQueueP));
		temp->next = pnew;
	}
}

void tampilQueue(address p, char queueMobil){
	if (isEmpty(p)){
		printf("antrian kosong di tempat cuci %c\n", queueMobil);
	}
	else {
		printf("Berikut Antrian Cuci Mobil %c\n", queueMobil);
		while (p != NULL){
			printf("Jenis Mobil		: %s\n", p->jenisMobil);
			printf("Plat Nomor		: %s\n", p->noPolisi);
			printf("Waktu Kedatangan	: %d:%d\n", p->waktuDatangMobil.jam, p->waktuDatangMobil.menit);
			printf("Waktu cuci dimulai	: %d:%d\n", p->startCuci.jam, p->startCuci.menit);
			printf("Waktu cuci berakhir	: %d:%d\n\n", p->endCuci.jam, p->endCuci.menit);
			p = p->next;	
		}
	}
}


void Isi_Node (address *p , char nilai[],char PlatNo[], waktu WaktuDatang){
	
	if(isEmpty(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		(*p)->next = NULL;
		strcpy((*p)->jenisMobil, nilai);
		strcpy((*p)->noPolisi, PlatNo);
		//(*p)->noPolisi = noPolisi;
		(*p)->waktuDatangMobil.jam = WaktuDatang.jam;
		if (WaktuDatang.menit == 60){
			(*p)->waktuDatangMobil.jam = (*p)->waktuDatangMobil.jam + 1;
			WaktuDatang.menit = 0;
		}
		(*p)->waktuDatangMobil.menit = WaktuDatang.menit;
		(*p)->startCuci.jam = 0;
		(*p)->startCuci.menit = 0;
		(*p)->endCuci.jam = 0;
		(*p)->endCuci.menit = 0;
	}
}


bool checkDecisionQueue(address p, address q){
	address A, B;
	A = p;
	B = q;
	if (isEmpty(p)){
		return true;
	}
	else if (isEmpty(q)){
		return false;
	}
	else if (!isEmpty(p) && !isEmpty(q)){
		while ((A)->next != NULL){
			A = A->next;
		}
		while ((B)->next != NULL){
			B = B->next;
		}
		if (A->endCuci.jam < B->endCuci.jam){
			return true;
		}
		else if (A->endCuci.jam > B->endCuci.jam){
			return false;
		}
		else if (A->endCuci.jam == B->endCuci.jam){
			if (A->endCuci.menit < B->endCuci.menit){
				return true;
			}
			else if (A->endCuci.menit > B->endCuci.menit){
				return false;
			}
			else {
				return true;
			}
		}
	}
}

bool changeDecisionStatusService(address p, waktu waktuDatang){
	address temp;
	temp = p;
	if (temp == NULL){
		return false;
	}
	else {
		if (temp->endCuci.jam < waktuDatang.jam){
			return true;
		}
		else if (temp->endCuci.jam > waktuDatang.jam){
			return false;
		}
		else if (temp->endCuci.jam == waktuDatang.jam){
			if (temp->endCuci.menit < waktuDatang.menit){
				return true;
			}
			else if (temp->endCuci.menit > waktuDatang.menit){
				return false;
			}
			else {
				return true;
			}
		}
	}
}

void displayCurrentStatus(address p, char queueMobil){
	if (isEmpty(p)){
		printf("antrian kosong di tempat cuci %c\n", queueMobil);
	}
	else {
		printf("Mobil yang sedang di cuci memiliki data sebagai berikut\n");
		printf("Jenis Mobil		: %s\n", p->jenisMobil);
		printf("Plat Nomor		: %s\n", p->noPolisi);
		printf("Waktu Kedatangan	: %d:%d\n", p->waktuDatangMobil.jam, p->waktuDatangMobil.menit);
		printf("Waktu cuci dimulai	: %d:%d\n", p->startCuci.jam, p->startCuci.menit);
		printf("Waktu cuci berakhir	: %d:%d\n\n", p->endCuci.jam, p->endCuci.menit);
	}
}


