#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer; // Forward declaration to resolve dependency issue

class Car {
    int position;
    vector<Observer *> observerList; // List of observers

public:
    int getPosition() {
        return position; // Returns the car's current position
    }

    void setPosition(int newPosition) {
        position = newPosition; // Updates the car's position
        notify(); // Notifies all observers about the change
    }

    void attach(Observer *obs) {
        observerList.push_back(obs); // Adds an observer to the list
    }

    void detach(Observer *obs) {
        observerList.erase(remove(observerList.begin(), observerList.end(), obs), observerList.end()); // Removes an observer from the list
    }

    void notify(); // Function to notify all observers about a position change
};

class Observer {
    Car *_car; // Pointer to the observed Car object

public:
    Observer(Car *car) {
        _car = car;
        _car->attach(this); // Attaches this observer to the car
    }

    virtual void update() = 0; // Pure virtual function that must be implemented by derived classes

protected:
    Car *getCar() {
        return _car; // Returns the car object associated with this observer
    }
};

void Car::notify() {
    for (size_t i = 0; i < observerList.size(); ++i) {
        observerList[i]->update(); // Calls the update method of each observer
    }
}

// LeftObserver class that detects when the car is on the left side
class LeftObserver : public Observer {
public:
    LeftObserver(Car *car) : Observer(car) {} // Calls base class constructor

    void update() override { // `override` ensures this function overrides the base class method
        int pos = getCar()->getPosition(); // `getCar()->getPosition()` gets the car's position
        if (pos < 0) {
            cout << "Left side" << endl;
        }
    }
};

// RightObserver class that detects when the car is on the right side
class RightObserver : public Observer {
public:
    RightObserver(Car *car) : Observer(car) {} // Calls base class constructor

    void update() override {
        int pos = getCar()->getPosition();
        if (pos > 0) {
            cout << "Right side" << endl;
        }
    }
};

// MiddleObserver class that detects when the car is in the middle
class MiddleObserver : public Observer {
public:
    MiddleObserver(Car *car) : Observer(car) {} // Calls base class constructor

    void update() override {
        int pos = getCar()->getPosition();
        if (pos == 0) {
            cout << "Middle side" << endl;
        }
    }
};

int main() {
    Car *car = new Car(); // Creates a Car object dynamically
    LeftObserver leftObserver(car); // Observer to detect left position
    RightObserver rightObserver(car); // Observer to detect right position
    MiddleObserver middleObserver(car); // Observer to detect middle position

    cout << "Hit 'l' for left, 'r' for right, 'c' for center, and 'b' to exit." << endl;

    char pressedButton;
    bool breakLoop = false;

    while (!breakLoop) {
        cin >> pressedButton;

        switch (pressedButton) {
        case 'l': 
            car->setPosition(-1); // Move car to left
            break;
        case 'c': 
            car->setPosition(0); // Move car to center
            break;
        case 'r': 
            car->setPosition(1); // Move car to right
            break;
        case 'b': 
            breakLoop = true; // Exit loop
            break;
        default:
            cout << "Please drive carefully!" << endl;
            break;
        }
    }

    cout << "Byee ..." << endl;
    delete car; // Free allocated memory
    return 0;
}