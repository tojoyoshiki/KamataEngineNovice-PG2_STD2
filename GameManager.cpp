#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::Init()
{
    // Enemyオブジェクトをベクタに追加
    enemies.push_back(Enemy());
    enemies.push_back(Enemy());
}

void GameManager::Update()
{
    //Enemyの更新
    for (auto& enemy : enemies)
    {
        enemy.Update();
    }
}

void GameManager::Draw()
{
    //Enemyの更新
    for (auto& enemy : enemies)
    {
        enemy.Draw();
    }
}
