#ifndef logger_h
#define logger_h

#include<string>
#include<mutex>

using namespace std;

class Logger{
    static int ctr;
    static Logger *loggerInstance; //  this is our single instance & called by all user
    static mutex mtx;
    Logger();// making the constructor private
    Logger(const Logger &);
    Logger operator = (const Logger &);

    public:
    static Logger* getLogger();// i made this function as static so that it belongs to class it self not to 
    //particular object of the class , it going to return pointer to logger it self 
    void Log(string msg);
}

#endif