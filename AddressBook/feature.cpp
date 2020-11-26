//
// Created by FHang on 2020/8/4.
//

#include "feature.h"

//��ʾͨѶ¼�˵�
void showAddressBookMenu()
{
    cout << endl;
    cout << "-------- Address Book --------" << endl;
    cout << "\t1. �����ϵ��" << endl;
    cout << "\t2. ��ʾ��ϵ��" << endl;
    cout << "\t3. ɾ����ϵ��" << endl;
    cout << "\t4. ������ϵ��" << endl;
    cout << "\t5. �޸���ϵ��" << endl;
    cout << "\t6. �����ϵ��" << endl;
    cout << "\t0. �˳�ͨѶ¼" << endl;
}

//�����ϵ��
void addPerson(s_AddressBook *s_ABS)
{
    if (s_ABS->m_Size == MAX)
    {
        cout << "Address Book is Full !";
        return;
    }
    else
    {
        //Enter address book contactperson info : name
        string enterName;
        cout << "Enter name: ";
        cin >> enterName;
        s_ABS->personArr[s_ABS->m_Size].m_Name = enterName;

        //Enter address book contactperson info : sex
        int enterSex = 0;
        while (true)
        {
            cout << "Enter sex(1-Man / 2-Women / default 1): ";
            cin >> enterSex;
            if (enterSex == 1 || enterSex == 2)
            {
                s_ABS->personArr[s_ABS->m_Size].m_Sex = enterSex;
                break;
            }
            else
            {
                cout << "Enter 1 or 2" << endl;
            }
        }

        //Enter address book contactperson info : age
        int enterAge = 0;
        cout << "Enter age: ";
        cin >> enterAge;
        s_ABS->personArr[s_ABS->m_Size].m_Age = enterAge;

        //Enter address book contactperson info : phone
        string enterPhone;
        cout << "Enter phone: ";
        cin >> enterPhone;
        s_ABS->personArr[s_ABS->m_Size].m_phone = enterPhone;

        //Enter address book contactperson info : address
        string enterAddress;
        cout << "Enter address: ";
        cin >> enterAddress;
        s_ABS->personArr[s_ABS->m_Size].m_Address = enterAddress;

        //tip info
        cout << "-------- " << s_ABS->personArr[s_ABS->m_Size].m_Name << " Add Succeeded ! --------" << endl;

        //update address book m_size
        s_ABS->m_Size++;

        //clear console show info
        system("pause"); //�밴�����
        system("cls"); //clear console show info
    }
}

//��ʾ��ϵ��
void showPerson(s_AddressBook *s_ABS)
{
    if (s_ABS->m_Size == 0)
    {
        cout << "-------- Address Book No Contact ! --------" << endl;
    }
    else
    {
        for (int i = 0; i < s_ABS->m_Size; i++)
        {
            cout << " " << i << ". "
                 << "Name: " << s_ABS->personArr[i].m_Name
                 << " / Sex: " << (s_ABS->personArr[i].m_Sex == 1 ? "��" : "Ů")
                 << " / Age: " << s_ABS->personArr[i].m_Age
                 << " / Phone: " << s_ABS->personArr[i].m_phone
                 << " / Address: " << s_ABS->personArr[i].m_Address << endl;
        }
    }
    system("pause");
    system("cls");
}

//������ϵ��(������ɾ����ϵ�˹���)
int findPersonByDeletOrModify(s_AddressBook *s_ABS, string enterName)
{
    for (int i = 0; i < s_ABS->m_Size; i++)
    {
        if (s_ABS->personArr[i].m_Name == enterName)
        {
            return i; //���ҵ�
        }
    }
    return -1; //��û�ҵ�
}

//ɾ����ϵ��
void deletPerson(s_AddressBook *s_ABS, int personIndex, string enterName)
{
    if (personIndex == -1)
    {
        cout << "-------- No Contact --------" << endl;
    }
    else
    {
        cout << "-------- " << enterName << " Delet Succeeded ! --------" << endl;
        for (int i = personIndex; i < s_ABS->m_Size; i++)
        {
            s_ABS->personArr[i] = s_ABS->personArr[i + 1];
        }
        s_ABS->m_Size--;
    }
    system("pause");
    system("cls");
}

//��ʾ������Ϣ
string tipEnterInfo(string enterName)
{
    cout << "Enter Name for Delet: ";
    cin >> enterName;
    return enterName;
}

//��ʾ������Ϣ
void tipReturnInfo(int returnNum)
{
    if (returnNum == -1)
    {
        cout << "-------- No Contact --------" << endl;
    }
    else
    {
        cout << "-------- Have Contact --------" << endl;
    }
}

//������ϵ��
void findPerson(s_AddressBook *s_ABS)
{
    cout << "Enter name: ";
    string findName;
    cin >> findName;

    int nameIndex = findPersonByDeletOrModify(s_ABS, findName);

    if (nameIndex == -1)
    {
        cout << "-------- No Contact --------" << endl;
    }
    else
    {
        cout << " " << nameIndex << ". "
             << "Name: " << s_ABS->personArr[nameIndex].m_Name
             << " / Sex: " << (s_ABS->personArr[nameIndex].m_Sex == 1 ? "��" : "Ů")
             << " / Age: " << s_ABS->personArr[nameIndex].m_Age
             << " / Phone: " << s_ABS->personArr[nameIndex].m_phone
             << " / Address: " << s_ABS->personArr[nameIndex].m_Address << endl;
    }
    system("pause");
    system("cls");
}

//�޸���ϵ�˲˵�
void showModifyContactMenu()
{
    cout << endl;
    cout << "-------- Modify Contact --------" << endl;
    cout << "\t1. Modify Name" << endl;
    cout << "\t2. Modify Sex" << endl;
    cout << "\t3. Modify Age" << endl;
    cout << "\t4. Modify Phone" << endl;
    cout << "\t5. Modify Address" << endl;
    cout << "\t0. Exit Modify" << endl;
}

//�޸���ϵ��
int modifyPerson(s_AddressBook *s_ABS)
{
    cout << "Enter name: ";
    string modifyName;
    cin >> modifyName;

    int nameIndex = findPersonByDeletOrModify(s_ABS, modifyName);

    if (nameIndex == -1)
    {
        cout << "-------- No Contact --------" << endl;
    }
    else
    {
        int userSelect;

        while (true)
        {
            showModifyContactMenu();

            cout << "Select : ";
            cin >> userSelect;

            switch (userSelect)
            {
                case 1 : //Modify Name
                {
                    cout << "Enter name: " << endl;
                    string newName;
                    cin >> newName;
                    s_ABS->personArr[nameIndex].m_Name = newName;
                    cout << "-------- Modify Name Succeeded ! --------" << endl;

                    system("pause");
                    system("cls");
                }
                    break;
                case 2: //Modify Sex
                {
                    cout << "Enter sex(1-Man / 2-Women / default 1): ";
                    int newSex;
                    while (true)
                    {
                        cin >> newSex;
                        if (newSex == 1 || newSex == 2)
                        {
                            s_ABS->personArr[nameIndex].m_Sex = newSex;
                            break;
                        }
                        else
                        {
                            cout << "Enter 1 or 2" << endl;
                        }
                    }
                    cout << "-------- Modify Sex Succeeded ! --------" << endl;

                    system("pause");
                    system("cls");
                }
                    break;
                case 3: //Modify Age
                {
                    cout << "Enter Age: ";
                    int newAge;
                    cin >> newAge;
                    s_ABS->personArr[nameIndex].m_Age = newAge;
                    cout << "-------- Modify Age Succeeded ! --------" << endl;

                    system("pause");
                    system("cls");
                }
                    break;
                case 4: //Modify Phone
                {
                    cout << "Enter Phone: ";
                    string newPhone;
                    cin >> newPhone;
                    s_ABS->personArr[nameIndex].m_phone = newPhone;
                    cout << "-------- Modify Phone Succeeded ! --------" << endl;

                    system("pause");
                    system("cls");
                }
                    break;
                case 5: //Modify Address
                {
                    cout << "Enter Address: ";
                    string newAddress;
                    cin >> newAddress;
                    s_ABS->personArr[nameIndex].m_Address = newAddress;
                    cout << "-------- Modify Address Succeeded ! --------" << endl;

                    system("pause");
                    system("cls");
                }
                    break;
                case 0:
                {
                    cout << "���˳��޸���ϵ��" << endl;
                    system("pause");
                    system("cls");
                }
                    return 0;
                    break;
                default:
                    break;
            }
        }
    }

    system("pause");
    system("cls");
}

//�����ϵ��
void cleanPerson(s_AddressBook *s_ABS)
{
    string enterYN;
    string selectYN;
    while (true)
    {
        cout << "Clean All Contact ( y / n ): ";
        cin >> enterYN;
        if (enterYN == "y" || enterYN == "n")
        {
            selectYN = enterYN;
            break;
        }
        else
        {
            cout << "Enter y or n" << endl;
        }
    }

    if (selectYN == "y")
    {
        s_ABS->m_Size = 0;
        cout << "-------- Address Book Clean Succeeded ! --------" << endl;
    }
    else
    {
        cout << "-------- Address Book Clean Exit ! --------" << endl;
    }
    system("pause");
    system("cls");
}

//�˳�ͨѶ¼
void exitAddressBook()
{
    cout << "���˳�ͨѶ¼" << endl;
    system("pause");
}