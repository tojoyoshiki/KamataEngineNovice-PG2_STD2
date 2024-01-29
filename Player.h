//Player.h
#pragma once
#include "Vector2.h"
#include "Bullet.h"

class Bullet;

class Player
{
public:
	Player();//コンストラクタ
	~Player();//デストラクタ

	//メンバ関数
	void Init();
	void Update(char keys[256]);
	void Draw();
	void Resporn();

	// アクセッサ
	const Vector2& GetPosition() const { return pos; }
	int GetPosX() const { return static_cast<int>(pos.x); }
	int GetPosY() const { return static_cast<int>(pos.y); }

	int GetLeftTopX() const { return static_cast<int>(leftTop.x); }
	int GetLeftTopY() const { return static_cast<int>(leftTop.y); }
	int GetRightBottomX() const { return static_cast<int>(rightBottom.x); }
	int GetRightBottomY() const { return static_cast<int>(rightBottom.y); }

	int GetSpeed() const { return speed; }
	int GetRadius() const { return radius; }
	int& GetAlive() { return alive; }
	int GetResporn() const { return resporn; }
	int GetWidth() const { return static_cast<int>(size.x); }
	int GetHeight() const {return static_cast<int>(size.y); }

private:
	//メンバ変数
	Bullet* bullet; // Bulletクラスのポインタ変数を包含

	Vector2 pos;
	Vector2 size; // xがw、yがh。
	Vector2 leftTop;
	Vector2 leftBottom;
	Vector2 rightTop;
	Vector2 rightBottom;
	int speed;
	int radius;
	int alive;

	int resporn;

	int gr[50] = { 0 };
};