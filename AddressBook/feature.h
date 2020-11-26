//
// Created by FHang on 2020/8/4.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef ADDRESSBOOK_FEATURE_H
#define ADDRESSBOOK_FEATURE_H

#define MAX 1000

struct s_ContactPerson
{
    string m_Name;
    int m_Sex = 1;
    int m_Age = 0;
    string m_phone;
    string m_Address;
};

struct s_AddressBook
{
    s_ContactPerson personArr[MAX];
    int m_Size = 0; //通讯录的联系人数
};

void showAddressBookMenu();

void addPerson(s_AddressBook *s_ABS);

void showPerson(s_AddressBook *s_ABS);

int findPersonByDeletOrModify(s_AddressBook *s_ABS, string enterName);

void deletPerson(s_AddressBook *s_ABS, int personIndex, string enterName);

string tipEnterInfo(string enterName);

void tipReturnInfo(int returnNum);

void findPerson(s_AddressBook *s_ABS);

void showModifyContactMenu();

int modifyPerson(s_AddressBook *s_ABS);

void cleanPerson(s_AddressBook *s_ABS);

void exitAddressBook();

#endif //ADDRESSBOOK_FEATURE_H
