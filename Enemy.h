//Enemy.h
#pragma once
#include <Novice.h>
#include "Vector2.h"
#include <vector>

class Enemy
{
public:
	Enemy();//コンストラクタ
	~Enemy();//デストラクタ
	//メンバ関数
	void Init();
	void Update();
	void Draw();
	void Resporn();

	// アクセッサ
	const Vector2& GetPosition() const { return pos; }
	int GetLeftTopX() const { return static_cast<int>(leftTop.x); }
	int GetLeftTopY() const { return static_cast<int>(leftTop.y); }
	int GetRightBottomX() const { return static_cast<int>(rightBottom.x); }
	int GetRightBottomY() const { return static_cast<int>(rightBottom.y); }

	int GetSpeed() const { return speed; }
	int GetRadius() const { return radius; }
	int& GetAlive() { return alive; }
	int GetResporn() const { return resporn; }
	int GetWidth() const { return static_cast<int>(size.x); }
	int GetHeight() const { return static_cast<int>(size.y); }

private:
	//メンバ変数
	Vector2 pos;
	Vector2 size; // xがw、yがh。
	Vector2 leftTop;
	Vector2 leftBottom;
	Vector2 rightTop;
	Vector2 rightBottom;
	int speed;
	int radius;
	int alive;

	// リスポーンタイマー
	int resporn;
  
	int gr[50] = { 0 };
};