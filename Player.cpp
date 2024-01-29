//Player.cpp
#include <Novice.h>
#include "Player.h"

Player::Player()
{
	Init();

	//Bulletクラスの新しいインスタンス
	bullet = new Bullet();
}

Player::~Player()
{
	delete bullet;
}

void Player::Init()
{
	//画像データ
	gr[0] = Novice::LoadTexture("./white1x1.png");

	pos.x = 720;
	pos.y = 520;
	size.x = 30;
	size.y = 30;
	radius = 30;
	speed = 5;
	alive = 1;

	resporn = 0;

	leftTop.x = pos.x - size.x / 2;
	leftTop.y = pos.y - size.y / 2;
	leftBottom.x = pos.x - size.x / 2;
	leftBottom.y = pos.y + size.y / 2;
	rightTop.x = pos.x + size.x / 2;
	rightTop.y = pos.y - size.y / 2;
	rightBottom.x = pos.x + size.x / 2;
	rightBottom.y = pos.y + size.y / 2;
}

void Player::Update(char keys[256])
{
	//プレイヤー移動
	if (keys[DIK_W] != 0) {
		pos.y -= speed;
	}
	if (keys[DIK_S] != 0) {
		pos.y += speed;
	}
	if (keys[DIK_A] != 0) {
		pos.x -= speed;
	}
	if (keys[DIK_D] != 0) {
		pos.x += speed;
	}
	//スピード反転
	if (pos.x <= 15) {
		pos.x = 15;
	}
	if (pos.y <= 15) {
		pos.y = 15;
	}
	if (pos.x > 1265) {
		pos.x = 1265;
	}
	if (pos.y > 705) {
		pos.y = 705;
	}

	//描画位置を更新
	leftTop.x = pos.x - size.x / 2;
	leftTop.y = pos.y - size.y / 2;
	leftBottom.x = pos.x - size.x / 2;
	leftBottom.y = pos.y + size.y / 2;
	rightTop.x = pos.x + size.x / 2;
	rightTop.y = pos.y - size.y / 2;
	rightBottom.x = pos.x + size.x / 2;
	rightBottom.y = pos.y + size.y / 2;
}

void Player::Draw()
{
	Novice::DrawQuad((int)leftTop.x, (int)leftTop.y,
		(int)rightTop.x, (int)rightTop.y,
		(int)leftBottom.x, (int)leftBottom.y,
		(int)rightBottom.x, (int)rightBottom.y,
		1, 1, (int)size.x, (int)size.y,
		gr[0], 0xFFFFFFF);
}

void Player::Resporn()
{
	++resporn; // タイマーを進める
	if (alive == 0 && resporn >= 120) {
		alive = 1;
		resporn = 0;
		pos.x = 720;
		pos.y = 520;
	}
}
