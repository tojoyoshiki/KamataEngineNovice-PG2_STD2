//GameManager.h
#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Vector2.h"
#include <vector>

class GameManager
{
public:
    GameManager();
    ~GameManager();

    // メンバ関数
    void Init();
    void Update();
    void Draw();

    static int gameOverCount; // ゲームオーバーまでのカウント

    static void CheckGameOver(Player& playerObj);

private:
    // メンバ変数
    std::vector<Enemy> enemies;  // Enemyベクタ
    std::vector<Player> players; // Playerベクタ
    std::vector<Bullet> bullets; // Bulletベクタ
};