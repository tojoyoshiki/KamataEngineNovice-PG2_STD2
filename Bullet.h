#pragma once
#include <Novice.h>
#include "Vector2.h"
#include "Player.h"

class Player;

class Bullet
{
public:
	Bullet();//コンストラクタ
	~Bullet();//デストラクタ

	//メンバ関数
	void Init();
	void Update(Player& playerObj,char keys[256],char preKeys[256]);
	void Draw();

	// アクセッサ
	const Vector2& GetPosition() const { return pos; }
	int GetSpeed() const { return speed; }
	int GetRadius() const { return radius; }
	int GetWidth() const { return static_cast<int>(size.x); }
	int GetHeight() const {return static_cast<int>(size.y); }

	int GetLeftTopX() const { return static_cast<int>(leftTop.x); }
	int GetLeftTopY() const { return static_cast<int>(leftTop.y); }
	int GetRightBottomX() const { return static_cast<int>(rightBottom.x); }
	int GetRightBottomY() const { return static_cast<int>(rightBottom.y); }

private:
	//メンバ変数
	Vector2 pos;// x,y座標
	Vector2 size; // xがw、yがh。
	Vector2 leftTop;
	Vector2 leftBottom;
	Vector2 rightTop;
	Vector2 rightBottom;
	int speed;
	int radius;
	int isShot;// フラグ

	int gr[50] = { 0 };
};

