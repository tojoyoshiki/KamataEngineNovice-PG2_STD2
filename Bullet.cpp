#include "Bullet.h"
#include "Player.h"

Bullet::Bullet() : pos(0.0f, 0.0f), speed(5), radius(15), size(20, 20)
{
	Init();
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	//画像データ
	gr[0] = Novice::LoadTexture("./white1x1.png");

	pos.x = -10;
	pos.y = -10;

	size.x = 15;
	size.y = 15;

	//描画位置を更新
	leftTop.x = pos.x - size.x / 2;
	leftTop.y = pos.y - size.y / 2;
	leftBottom.x = pos.x - size.x / 2;
	leftBottom.y = pos.y + size.y / 2;
	rightTop.x = pos.x + size.x / 2;
	rightTop.y = pos.y - size.y / 2;
	rightBottom.x = pos.x + size.x / 2;
	rightBottom.y = pos.y + size.y / 2;

	speed = 5;
	radius = 15;
	isShot = 0;
}

void Bullet::Update(Player& playerObj, char keys[256], char preKeys[256])
{
	//描画位置を更新
	leftTop.x = pos.x - size.x / 2;
	leftTop.y = pos.y - size.y / 2;
	leftBottom.x = pos.x - size.x / 2;
	leftBottom.y = pos.y + size.y / 2;
	rightTop.x = pos.x + size.x / 2;
	rightTop.y = pos.y - size.y / 2;
	rightBottom.x = pos.x + size.x / 2;
	rightBottom.y = pos.y + size.y / 2;

	if (isShot == 0 && keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
		isShot = 1;
		pos = playerObj.GetPosition();
	}

	if (isShot == 1) {
		pos.y -= speed;
		if (pos.y < -10) {
			// 弾が画面外に出たらリセット
			isShot = 0;
		}
	}
}

void Bullet::Draw()
{
	Novice::DrawQuad(
		(int)leftTop.x, (int)leftTop.y,
		(int)rightTop.x, (int)rightTop.y,
		(int)leftBottom.x, (int)leftBottom.y,
		(int)rightBottom.x, (int)rightBottom.y,
		0, 0, (int)size.x, (int)size.y, gr[0], 0x6A5ACDFF);
}
