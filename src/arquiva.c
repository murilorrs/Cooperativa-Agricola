#include <stdio.h>
#include "../include/arquiva.h"

int globalID;

void arquivar(int ID){
	globalID = ID;
	printf("ID salvo: %d", globalID);

	
}