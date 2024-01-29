//EnemyB.cpp
#include "EnemyB.h"

EnemyB::EnemyB() : pos(300.0f,300.0f),speed(5),radius(20),size(25,25),alive(1)
{
    Init();
}

EnemyB::~EnemyB()
{
}

void EnemyB::Init()
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

void EnemyB::Update()
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

void EnemyB::Draw()
{
    Novice::DrawQuad((int)leftTop.x, (int)leftTop.y,
        (int)rightTop.x, (int)rightTop.y,
        (int)leftBottom.x, (int)leftBottom.y,
        (int)rightBottom.x, (int)rightBottom.y,
        1, 1, (int)size.x, (int)size.y,
        gr[0], 0x8B0000FF);
}

void EnemyB::Resporn()
{
    ++resporn; // タイマーを進める
    if (alive == 0 && resporn >= 120) {
        alive = 1;
        resporn = 0;
    }
}
