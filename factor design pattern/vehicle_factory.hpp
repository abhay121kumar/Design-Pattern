#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include<iostream>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

class VehicleFactory{
    public:
        static Vehicle *getVehicle(string vehicleType);//
        //when we make a function static what happend is that 
        // i can access the function without the object of the class
        // so if i did not have to make this function as static then 
        // i have to create the object of the vehicleFactory class
        // create an object this the class & then access this functionality
};

#endif