#include "Monster.h"
#include "Tanker.h"

int main()
{
	Monster* mon = new Tanker("��Ŀ", 100, 0, 5, 10);
	cout << mon->getName() << "�� ���ݷ�: " << mon->getAttack() << endl;
	delete mon;
	return 0;
}