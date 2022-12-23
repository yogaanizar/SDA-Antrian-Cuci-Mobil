#include "main.h"

int waktuJeda(address p){
	if (strcmp(p->jenisMobil, "A") == 0 || strcmp(p->jenisMobil, "a") == 0){
		return 30;
	}
	if (strcmp(p->jenisMobil, "B") == 0 || strcmp(p->jenisMobil, "b") == 0){
		return 45;
	}
	if (strcmp(p->jenisMobil, "C") == 0 || strcmp(p->jenisMobil, "c") == 0){
		return 75;
	}
}

void waktuGanti(address *p){
	if ((*p)->endCuci.menit >= 60){
		while ((*p)->endCuci.menit >= 60){
			(*p)->endCuci.menit = (*p)->endCuci.menit - 60;
			(*p)->endCuci.jam = (*p)->endCuci.jam + 1;
		}
	}
}

bool waktuValid(waktu WaktuDatang){
	if (WaktuDatang.jam > 0 && WaktuDatang.jam < 24){
		
		if (WaktuDatang.menit >= 0 && WaktuDatang.menit <= 60){
			if(WaktuDatang.jam >= 12 && WaktuDatang.jam <13 || WaktuDatang.jam >=17){
				return false;
			}
			else{
			return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool simulateCurrentRemainingServiceTime(waktuCuci serviceTimeQueueP){
	serviceTimeQueueP.masuk.menit = serviceTimeQueueP.masuk.menit + 30;
	if (serviceTimeQueueP.masuk.menit >= 60){
		serviceTimeQueueP.masuk.jam = serviceTimeQueueP.masuk.jam + 1;
		serviceTimeQueueP.masuk.menit = serviceTimeQueueP.masuk.menit - 60;
	}
	if (serviceTimeQueueP.masuk.jam > serviceTimeQueueP.keluar.jam){
		return false;
	}
	else if (serviceTimeQueueP.masuk.jam == serviceTimeQueueP.keluar.jam){
		return false;
	}
	else {
		return true;
	}
}

bool remainingServiceTime(address p, address q, waktuCuci serviceTimeQueueA, waktuCuci serviceTimeQueueB){
	if (checkDecisionQueue(p, q) == true){
  		if (simulateCurrentRemainingServiceTime(serviceTimeQueueA) == false){
   			return false;
  		}
  		else {
   			return true;
  		}
 	}
 	else{
  		if (simulateCurrentRemainingServiceTime(serviceTimeQueueB) == false){
   			return false;
  		}
  		else {
   			return true;
  		}
 	}
}

void defaultServiceTime(waktuCuci *serviceTimeQueue){
	(*serviceTimeQueue).masuk.jam = 07;
	(*serviceTimeQueue).masuk.menit = 00;
	(*serviceTimeQueue).keluar.jam = 17;
	(*serviceTimeQueue).keluar.menit = 00;
}

bool cekWaktuDatang(waktu WaktuDatang){
	if (WaktuDatang.jam >= 0 && WaktuDatang.jam < 17){
		return true;
	}
	else {
		return false;
	}
}

void updateRemainingServiceTime(address a, waktuCuci *serviceTimeQueue){
	(*serviceTimeQueue).masuk.jam = a->endCuci.jam;
	(*serviceTimeQueue).masuk.menit = a->endCuci.menit;
}

void updateStatusService(address *p, waktu waktuDatang){
	do{
		address temp;
		temp = *p;
		if (temp->endCuci.jam < waktuDatang.jam){
			*p = temp->next;
			temp->next = NULL;
			free(temp);
		}
		else if (temp->endCuci.jam > waktuDatang.jam){
			continue;
		}
		else if (temp->endCuci.jam == waktuDatang.jam){
			if (temp->endCuci.menit < waktuDatang.menit){
				*p = temp->next;
				temp->next = NULL;
				free(temp);
			}
			else if (temp->endCuci.menit > waktuDatang.menit){
				continue;
			}
			else {
				*p = temp->next;
				temp->next = NULL;
				free(temp);
			}
		}
	}while (changeDecisionStatusService(*p, waktuDatang) == true);
}

void insertStartServiceTime(address *p, address q){
	
    if ((*p)->waktuDatangMobil.jam < 7){
		(*p)->startCuci.jam = (*p)->waktuDatangMobil.jam;
		(*p)->startCuci.menit = (*p)->waktuDatangMobil.menit + 5;
	}
	else if ((*p)->waktuDatangMobil.jam > q->endCuci.jam){
		(*p)->startCuci.jam = (*p)->waktuDatangMobil.jam;
		(*p)->startCuci.menit = (*p)->waktuDatangMobil.menit + 5;
	}
	else if ((*p)->waktuDatangMobil.jam < q->endCuci.jam){
		(*p)->startCuci.jam = q->endCuci.jam;
		(*p)->startCuci.menit = q->endCuci.menit + 5;
		if((*p)->startCuci.jam >=12 && (*p)->startCuci.jam <13){
			(*p)->startCuci.jam = 13; 
			(*p)->startCuci.menit = 0 + 5;
		}
	}
	else if ((*p)->waktuDatangMobil.jam < q->endCuci.jam){
		(*p)->startCuci.jam = q->endCuci.jam;
		(*p)->startCuci.menit = q->endCuci.menit + 5;
	}
	else if ((*p)->waktuDatangMobil.jam == q->endCuci.jam){
		if ((*p)->waktuDatangMobil.menit > q->endCuci.menit){
			(*p)->startCuci.jam = (*p)->waktuDatangMobil.jam;
			(*p)->startCuci.menit = (*p)->waktuDatangMobil.menit + 5;
		}
		else if ((*p)->waktuDatangMobil.menit < q->endCuci.menit){
			(*p)->startCuci.jam = q->endCuci.jam;
			(*p)->startCuci.menit = q->endCuci.menit + 5;
		}
		else {
			(*p)->startCuci.jam = (*p)->waktuDatangMobil.jam;
			(*p)->startCuci.menit = (*p)->waktuDatangMobil.menit + 5;
		}
	}
}

bool checkTimeComeToPrevTimeCome(waktu waktuDatang, waktu prevTimeCome){
	if (waktuDatang.jam > prevTimeCome.jam){
		return true;
	}
	else if (waktuDatang.jam < prevTimeCome.jam){
		return false;
	}
	else if (waktuDatang.jam == prevTimeCome.jam){
		if (waktuDatang.menit > prevTimeCome.menit){
			return true;
		}
		else if (waktuDatang.menit < prevTimeCome.menit){
			return false;
		}
		else {
			return true;
		}
	}
}


