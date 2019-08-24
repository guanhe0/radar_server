#ifndef RADAR_INC_PERSON_INFO
#define RADAR_INC_PERSON_INFO 
#include "btype.h"

#define PERSON_NAME_LEN_MAX 64
#define PERSON_PASSWD_LEN_MAX   256
#define PERSON_EMAIL_LEN_MAX    256
#define PERSON_PHONENUMBER_LEN  16
class Location{
    public:
    float longitude;
    float latitude;
};

class Point{
    public:
    float x;
    float y;
};
class PersonInfo{
    public:
    char name[PERSON_NAME_LEN_MAX]; 
    int age;
    int valic_support;
    int total_support;
    char passwd[PERSON_PASSWD_LEN_MAX];
    char email[PERSON_EMAIL_LEN_MAX];
    char phonenumber[PERSON_PHONENUMBER_LEN];
    double userid;
};
class Target{
    public:
    double timestamp;
    Location loc;
    int type;
    int status;
};

class PersonMoveStatus{
    public:
    int rate;
    int start;
};
#endif
