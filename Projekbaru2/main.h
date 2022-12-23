#ifndef main_H
#define main_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>



typedef struct tlistNama{
	const char *nama;
	tlistNama *next;
}listNama;

typedef struct tjenisMobil{
	const char *nama;
	tlistNama *p;
}jenisMobil;

typedef struct{
	int menit;
	int jam;
}waktu;

typedef struct{
	waktu masuk;
	waktu keluar;
}waktuCuci;

//typedef int *pchar;
typedef struct tQueueCar *address;
typedef struct tQueueCar{
	char jenisMobil[10];
	char noPolisi[10];
	waktu waktuDatangMobil;
	waktu startCuci;
	waktu endCuci;
	address next;
}dataMobil;

#include "waktu.h"
#include "mobil.h"
#include "menu.h"

#endif
