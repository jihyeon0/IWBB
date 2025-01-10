#pragma once
#include <iostream>
#include <string>
using namespace std;

class Monster
{
public:
	Monster(string Monstername, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack)
		:_Monstername(Monstername), _MonsterHP(MonsterHP), _MonsterEXP(MonsterEXP), _MonsterGold(MonsterGold), _MonsterAttack(MonsterAttack) //생성자의 매개변수로 멤버변수 초기화
	{
		//기타 초기 필요 초기화 
	}
	virtual ~Monster(){}

public: //순수가상함수 => 자식클래스들(오크,슬라임 or 탱커, 어택커, 힐러..)이 재정의 해서 사용하는 함수들
	string getName() { return _Monstername; }
	virtual int getHp() = 0;
	virtual int getAttack() = 0;
	virtual void takeDamage(int damage) = 0;

protected: //부모 클래스에서 정의하고 자식 클래스에서 공통으로 사용하는 멤버변수들(탱커의 HP, 어택커의 HP, 힐러의 HP..)
	string	_Monstername;
	int		_MonsterHP;
	int		_MonsterEXP;
	int		_MonsterGold;
	int		_MonsterAttack;
};


// Monster를 상속받은 자식클래스
class Tanker : public Monster
{
public:
	Tanker(string Monstername, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack)
		: Monster(Monstername, MonsterHP, MonsterEXP, MonsterGold, MonsterAttack)// 생성자 호출 순서: 부모 생성자 호출 -> 부모 생성자에서 멤버변수 초기화 -> 부모 생성자 호출 종료 -> 자식 생성자 호출  -> 자식 생성자 호출 종료
	{
		//기타 초기 필요 초기화 
	}
	~Tanker() {}

public: 
	int getHp() override { return _MonsterHP; }
	int getAttack() override { return _MonsterAttack; }
	void takeDamage(int damage) override 
		{ 
			_MonsterHP -= damage;
			if (_MonsterHP <= 0) { _MonsterHP = 0; return; } //피격 당한 후 hp 체크 -> 몬스터 죽으면 삭제
			//삭제 추가 필요
		}
};