#ifndef vehicle_hpp
#define vehicle_hpp

class Vehicle{
    public:
    virtual void createVehicle() = 0;// this function is pure virtual function
    //  that means any class that inheriate from vehical will have to implement this particular function that is 
    //createVehical
};

#endif