#include "feature.h"

int main()
{
    int userSelect;
    s_AddressBook s_ABS; //����ͨѶ¼
    s_ABS.m_Size = 0;

    while (true)
    {
        showAddressBookMenu();

        cout << "Select : ";
        cin >> userSelect;

        switch (userSelect)
        {
            case 1: //1. �����ϵ��
                addPerson(&s_ABS); //ͨ����ַ���ݽṹ��ʵ�Σ������ں������޸ı��صĽṹ����ʵ��ֵ
                break;
            case 2: //2. ��ʾ��ϵ��
                showPerson(&s_ABS);
                break;
            case 3: //3. ɾ����ϵ��
            {
                string enterName;
                int personIndex;

                enterName = tipEnterInfo(enterName);
                findPersonByDeletOrModify(&s_ABS, enterName);

                personIndex = findPersonByDeletOrModify(&s_ABS, enterName);
                deletPerson(&s_ABS, personIndex, enterName);
            }
                break;
            case 4: //4. ������ϵ��
                findPerson(&s_ABS);
                break;
            case 5: //5. �޸���ϵ��
                modifyPerson(&s_ABS);
                break;
            case 6: //6. �����ϵ��
                cleanPerson(&s_ABS);
                break;
            case 0: //0. �˳�ͨѶ¼
                exitAddressBook();
                return 0;
                break;
            default:
                break;
        }
    }
}
