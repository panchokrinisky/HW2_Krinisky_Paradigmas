#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

#pragma once
using namespace std;

class Time {
    private:
        int hr;
        int min;
        int sec;
        string stage;

        void start(int h, int m, int s, string etapa);
        bool validate_hour(int h);
        bool validate_min(int m);
        bool validate_sec(int s);
        bool validate_stage(string etapa);

    public:
        Time();
        Time(int h);
        Time(int h, int m);
        Time(int h, int m, int s);
        Time(int h, int m, int s, string stage);

        void set_hour(int h);
        void set_min(int m);
        void set_sec(int s);
        void set_stage(string etapa);

        void get_hour(void);
        void get_min(void);
        void get_sec(void);
        void get_stage(void);
        void get_time(void);
        void get_full_time(void);
};
