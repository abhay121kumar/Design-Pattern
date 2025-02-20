#include<iostream>
#include "car.hpp"
#include "bike.hpp"

using namespace std;

int main(){
    string vehicleType; //this is out client
    cin>>vehicleType;
    Vehicle *vehicle;
    if(vehicleType == "car"){
        vehicle = new Car();
    }else if(vehicleType == "bike"){
        vehicle = new Bike();
    }
    vehicle -> createVehicle(); // call the function createVehicle
    return 0;
}

