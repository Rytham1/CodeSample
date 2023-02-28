//Rytham Dawar
//Student ID: 921313627

#include <iostream>
using namespace std;
#include "Airplane.h"

Airplane::Airplane(int n):maxContainers(n){
	numContainers = 0;
}

int Airplane::maxLoad(void) const{
	return maxContainers;
}

int Airplane::currentLoad(void) const{
	return numContainers;
}

bool Airplane::addContainers(int n){
		if((n + currentLoad()) <= maxLoad()){
			numContainers = n + numContainers;
			return true;
		}else{
			return false;
		}
}

/* another alternative for add is
add n to currentLoad and update current Load
subtract n from maxLoad and update maxLoad
if the add works properly, return true, else return false and don't update anything
*/
