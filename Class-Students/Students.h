#ifndef Students_h
#define Students_h
#include <string>

using namespace std;

class Students {
    private:
        string student_name;
        string student_surname;
        int student_age;
        char group_number[8];
    
    public:
        void dataInput();
        void dataOutput();
};

#endif
