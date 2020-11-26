#include "feature.h"

int main()
{
    int userSelect;
    s_AddressBook s_ABS; //创建通讯录
    s_ABS.m_Size = 0;

    while (true)
    {
        showAddressBookMenu();

        cout << "Select : ";
        cin >> userSelect;

        switch (userSelect)
        {
            case 1: //1. 添加联系人
                addPerson(&s_ABS); //通过地址传递结构体实参，可以在函数中修改本地的结构体内实参值
                break;
            case 2: //2. 显示联系人
                showPerson(&s_ABS);
                break;
            case 3: //3. 删除联系人
            {
                string enterName;
                int personIndex;

                enterName = tipEnterInfo(enterName);
                findPersonByDeletOrModify(&s_ABS, enterName);

                personIndex = findPersonByDeletOrModify(&s_ABS, enterName);
                deletPerson(&s_ABS, personIndex, enterName);
            }
                break;
            case 4: //4. 查找联系人
                findPerson(&s_ABS);
                break;
            case 5: //5. 修改联系人
                modifyPerson(&s_ABS);
                break;
            case 6: //6. 清空联系人
                cleanPerson(&s_ABS);
                break;
            case 0: //0. 退出通讯录
                exitAddressBook();
                return 0;
                break;
            default:
                break;
        }
    }
}
