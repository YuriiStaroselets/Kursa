#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstdio>


using namespace std;

class User {
public:
    int admin;
    string login;
    string password;

    void newUser(string log, string pass, int adm) {

    }
};


istream& operator>>(istream& input, User& x)
{
    input >> x.login;
    input >> x.password;
    input >> x.admin;
    return input;
}
vector<User> Users;
User currentUser;

void createAdmin() {
    string newadmin, temp;
    cout << "---New Admin---" << endl;
    cout << "Enter login:";
    cin >> temp;
    newadmin += temp + " ";
    cout << "Enter password:";
    cin >> temp;
    newadmin += temp + " 1";
    ofstream out("Users.txt");
    out << newadmin;
    out.close();
}

void readUsers() {
    ifstream UserList;
    UserList.open("Users.txt");
    if (!UserList) {
        cout << "No users exist. Please create new admin user!" << endl;
        UserList.close();
        createAdmin();
        readUsers();
    }
    else {
        User tempUser;
        while (UserList >> tempUser) {
            Users.push_back(tempUser);
        }
    }
}

User* checkAuth(User check) {
    for (auto& User : Users) {
        if (User.login == check.login) {
            if (User.password == check.password) {
                return &User;
            }
        }
    }
    return NULL;
}

void Authorization() {
    do {
        User checkUser;
        User* checkedUser;
        cout << "Please Authorize in the system!" << endl;
        cout << "Enter login:";
        cin >> checkUser.login;
        cout << "Enter password:";
        cin >> checkUser.password;
        checkedUser = checkAuth(checkUser);
        if (checkedUser != NULL) {
            currentUser = *checkedUser;
            cout << "Congratulations! You are authorized!" << endl;
            break;
        }
        else {
            cout << "Wrong login/password or user doesn`t exist!" << endl;
        }
    } while (true);
}



class Musician_s {
public:
    string m_Name;
    string m_BD;
    string m_NameCountry;
    string m_MusicInstryment;
    string m_Placein—ompetition;
};
istream& operator>>(istream& input, Musician_s& x)
{
    input >> x.m_Name;
    input >> x.m_BD;
    input >> x.m_NameCountry;
    input >> x.m_MusicInstryment;
    input >> x.m_Placein—ompetition;
    return input;
}
vector<Musician_s> g_Musicians;


void musician()
{
    struct Musician_s Musician;
    char szName[64] = { 0 };
    char szBD[64] = { 0 };
    char szNameCountry[64] = { 0 };
    char szMusicInstryment[64] = { 0 };
    char szPlacein—ompetition[64] = { 0 };
    cout << "Input in format: Name/Birthday/Country/Music Instrument/Place in —ompetition " << endl;
    scanf("%s %s %s %s %s", szName, &szBD,
        &szNameCountry, &szMusicInstryment, &szPlacein—ompetition);

    Musician.m_Name = std::string(szName);
    Musician.m_BD = std::string(szBD);
    Musician.m_NameCountry = std::string(szNameCountry);
    Musician.m_MusicInstryment = std::string(szMusicInstryment);
    Musician.m_Placein—ompetition = std::string(szPlacein—ompetition);
    g_Musicians.push_back(Musician);


}

void rem_new_l(char* s)
{
    size_t l = strlen(s);
    if (s[l - 1] == '\n') s[l - 1] = '\0';
}



void show_all(int day = 0)
{
    cout << std::endl << std::endl;
    vector<struct Musician_s>::iterator it;
    cout << std::endl << "Name\tBD\tCountry\tInstrument\tPlace" << std::endl;
    for (it = g_Musicians.begin(); it != g_Musicians.end(); ++it)
    {
        if (day == 0)
        {
            cout << it->m_Name
                << '\t' << it->m_BD
                << '\t' << it->m_NameCountry
                << '\t' << it->m_MusicInstryment
                << '\t' << it->m_Placein—ompetition
                << std::endl;
        }
    }
}


void add_from_file()
{
    char szName[64] = { 0 };
    char szBD[64] = { 0 };
    char szNameCountry[64] = { 0 };
    char szMusicInstryment[64] = { 0 };
    char szPlacein—ompetition[64] = { 0 };
    char szLine[128] = { 0 };
    cout << "File: ";
    fflush(stdin);
    fgets(szName,64, stdin);
    rem_new_l(szName);
    FILE* fIn = fopen(szName, "r");
    while (fgets(szLine, 128, fIn))
    {
        struct Musician_s Musician;
        sscanf(szLine, "%s %s %s %s %s", szName, &szBD,
            &szNameCountry, &szMusicInstryment, &szPlacein—ompetition);
        Musician.m_Name = std::string(szName);
        Musician.m_BD = std::string(szBD);
        Musician.m_NameCountry = std::string(szNameCountry);
        Musician.m_MusicInstryment = std::string(szMusicInstryment);
        Musician.m_Placein—ompetition = std::string(szPlacein—ompetition);
        g_Musicians.push_back(Musician);

    }
    fclose(fIn);
}


void save_to_file()
{
    char szName[64] = { 0 };
    char szBD[64] = { 0 };
    char szNameCountry[64] = { 0 };
    char szMusicInstryment[64] = { 0 };
    char szPlacein—ompetition[64] = { 0 };
    vector<struct Musician_s>::iterator it;

    cout << "File: ";
    fflush(stdin);
    fgets(szName,64, stdin);
    rem_new_l(szName);
    FILE* fOut = fopen(szName, "w");
    for (it = g_Musicians.begin(); it != g_Musicians.end(); ++it)
    {
        fprintf(fOut, "%s %s %s %s %s\n", it->m_Name.c_str(), it->m_BD.c_str(),
            it->m_NameCountry.c_str(), it->m_MusicInstryment.c_str(), it->m_Placein—ompetition.c_str());
    }
    fclose(fOut);
}




int main()
{
     //readUsers();
     //Authorization();
   //add_from_file();
    musician();
    //show_all();
    save_to_file();
    return 0;
};