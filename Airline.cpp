//Rytham Dawar
//Student ID: 921313627

#include <iostream>
using namespace std;
#include "Airline.h"

Airline::Airline(int nA321, int nB777, int nB787):nAirplanes(nA321+nB777+nB787){
	airplaneList = new Airplane*[nAirplanes];
			int i = 0;
			for(int j = 0; j < nA321; j++){
			airplaneList[i] = new Airplane(10);
			cout << "Airplane " << i+1 << " maximum load " << airplaneList[i]->maxLoad() << endl;
			i++;
		}

		for(int j = nA321; j < (nB777 + nA321); j++){
			airplaneList[i] = new Airplane(32);
			cout << "Airplane " << i+1 << " maximum load " << airplaneList[i]->maxLoad() << endl;
			i++;
		}

		for(int j = (nB777 + nA321); j < nAirplanes; j++){
			airplaneList[i] = new Airplane(40);
			cout << "Airplane " << i+1 << " maximum load " << airplaneList[i]->maxLoad() << endl;
			i++;
		}
	}
Airline::~Airline(void){
		for(int i = 0; i < nAirplanes; i++){
			cout << "deallocating airplane " << i+1 << endl;
			delete airplaneList[i];
		}
		delete airplaneList;
	}
void Airline::addShipment(int size){

	if(size < 0){
			throw invalid_argument("must be positive");
		}else{
			for(int i = 0; i < nAirplanes; i++){
				if(airplaneList[i]->addContainers(size)){
				cout << size << " containers added to airplane " << (i + 1) << endl;
				return;
				}
			}
			cout << " could not fit " << size << " containers" << endl;
		}

}
void Airline::printSummary(void) const{
	cout << "Summary:" << endl;
	for(int i = 0; i < nAirplanes; i++){
		if(airplaneList[i]->currentLoad() != 0){
		cout << "airplane " << i+1 << " " << airplaneList[i]->currentLoad() << "/" << airplaneList[i]->maxLoad() << endl;
		}
	}
}
