#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>

const int MAX = 80;

class String {
    private:
        char * cadena;
    public:
        String();
        String(char *);
        ~String();
        String(const String &);
        String operator= (const String &);
        bool mismoLargo(String);
        bool operator== (String);
        bool operator< (String);
        String operator+ (String);
        void scan();
        void print();
};



#endif // STRING_H_INCLUDED
