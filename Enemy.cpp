//Enemy.cpp
#include <Novice.h>
#include "Enemy.h"

Enemy::Enemy()
    : pos(100.0f, 100.0f), speed(5), radius(15), size(20, 20),alive(1)
{
    Init();
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
    //画像データ
    gr[0] = Novice::LoadTexture("./white1x1.png");

    //描画位置を更新
    leftTop.x = pos.x - size.x / 2;
    leftTop.y = pos.y - size.y / 2;
    leftBottom.x = pos.x - size.x / 2;
    leftBottom.y = pos.y + size.y / 2;
    rightTop.x = pos.x + size.x / 2;
    rightTop.y = pos.y - size.y / 2;
    rightBottom.x = pos.x + size.x / 2;
    rightBottom.y = pos.y + size.y / 2;

    resporn = 0;
}

void Enemy::Update()
{
    //移動処理
	pos.x += speed;
    // 画面端で反転
    if (pos.x >= 1280) {
        speed *= -1;
    }
    if (pos.x <= 0) {
        speed *= -1;
    }

    leftTop.x = pos.x - size.x / 2;
    leftTop.y = pos.y - size.y / 2;

    leftBottom.x = pos.x - size.x / 2;
    leftBottom.y = pos.y + size.y / 2;

    rightTop.x = pos.x + size.x / 2;
    rightTop.y = pos.y - size.y / 2;

    rightBottom.x = pos.x + size.x / 2;
    rightBottom.y = pos.y + size.y / 2;
}

void Enemy::Draw()
{
    Novice::DrawQuad((int)leftTop.x, (int)leftTop.y, 
        (int)rightTop.x, (int)rightTop.y,
        (int)leftBottom.x, (int)leftBottom.y, 
        (int)rightBottom.x, (int)rightBottom.y,
        1, 1, (int)size.x, (int)size.y,
        gr[0], 0xFF0000FF);
}

void Enemy::Resporn()
{
    ++resporn; // タイマーを進める
    if (alive == 0 && resporn >= 120) {
        alive = 1;
        resporn = 0;
    }
}
