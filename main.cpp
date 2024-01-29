//main.cpp
#include <Novice.h>
#include <new.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyB.h"
#include "GameManager.h"

const char kWindowTitle[] = "LC1D_18_トウジョウ_ヨシキ_評価課題";

//敵と弾の当たり判定
void BulletEnemyCollision(Enemy& enemyObj,
	float leftTopX, float leftTopY,
	float rightBottomX, float rightBottomY);

void BulletEnemyBCollision(EnemyB& enemyBobj,
	float leftTopX, float leftTopY,
	float rightBottomX, float rightBottomY);

//敵とプレイヤーの当たり判定
void PlayerEnemyCollision(Player& playerObj,
	float leftTopX, float leftTopY,
	float rightBottomX, float rightBottomY);

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// プレイヤー情報------------
	Player* player = new Player(); //インスタンス
	player->Init(); // 初期化関数呼び出し

	//弾情報------------
	Bullet* bullet = new Bullet();
	bullet->Init();

	//エネミー情報------------
	Enemy* enemy = new Enemy();
	enemy->Init();

	EnemyB* enemyB = new EnemyB();
	enemyB->Init();

	//マネジメント情報------------
	GameManager* gameManager = new GameManager();
	gameManager->Init();

	//シーン情報
	int scene;
	enum Scene {
		title,
		game,
		gameClear,
		gameOver,
	};
	scene = title;

	// 画像データ
	int gr[50] = { 0 };
	gr[0] = Novice::LoadTexture("./Resource/title.png");
	gr[1] = Novice::LoadTexture("./Resource/game.png");
	gr[2] = Novice::LoadTexture("./Resource/clear.png");
	gr[3] = Novice::LoadTexture("./Resource/gameOver.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene) {
		case title:
			// 全クラス情報毎ループごとに初期化
			enemy->Init();
			enemy->GetAlive() = 1;
			enemyB->Init();
			enemyB->GetAlive() = 1;
			player->Init();
			bullet->Init();
			gameManager->Init();

			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = game;
			}
			break;
		case game:
			//
			// enemy更新処理ここから----
			//

			if (enemy->GetAlive() == 1) {
			enemy->Update();
			}
			enemy->Resporn(); //リスポーン処理

			if (enemyB->GetAlive() == 1) {
				enemyB->Update();
			}
			enemyB->Resporn(); //リスポーン処理（ B ）の

			//
			// enemy更新処理ここまで----
			//

			//
			// player更新処理ここから----
			//

			if (player->GetAlive() == 1) {
				player->Update(keys);
				bullet->Update(*player, keys, preKeys);

				// 弾と敵の当たり判定
				BulletEnemyCollision(*enemy,
					static_cast<float>(bullet->GetLeftTopX()),
					static_cast<float>(bullet->GetLeftTopY()),
					static_cast<float>(bullet->GetRightBottomX()),
					static_cast<float>(bullet->GetRightBottomY()));
				BulletEnemyBCollision(*enemyB,
					static_cast<float>(bullet->GetLeftTopX()),
					static_cast<float>(bullet->GetLeftTopY()),
					static_cast<float>(bullet->GetRightBottomX()),
					static_cast<float>(bullet->GetRightBottomY()));

				//プレイヤーと敵の当たり判定
				PlayerEnemyCollision(*player,
					static_cast<float>(enemy->GetLeftTopX()),
					static_cast<float>(enemy->GetLeftTopY()),
					static_cast<float>(enemy->GetRightBottomX()),
					static_cast<float>(enemy->GetRightBottomY()));
				//Bの当たり判定
				PlayerEnemyCollision(*player,
					static_cast<float>(enemyB->GetLeftTopX()),
					static_cast<float>(enemyB->GetLeftTopY()),
					static_cast<float>(enemyB->GetRightBottomX()),
					static_cast<float>(enemyB->GetRightBottomY()));
			}						   
			player->Resporn();

			//clear
			if (enemy->GetAlive() == 0 &&
				enemyB->GetAlive() == 0) {
				scene = gameClear;
			}
			//clear
			if (player->GetAlive() == 0) {
				scene = gameOver;
			}

			break;

			//
			// player更新処理ここまで----
			//

		case gameClear:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = title;
			}
			break;
		case gameOver:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = title;
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene) {
		case title:
			Novice::DrawSprite(0, 0, gr[0], 1, 1, 0.0f, 0xFFFFFFFF);
			break;
		case game:
			// 背景
			Novice::DrawSprite(0, 0, gr[1], 1, 1, 0.0f, 0xFFFFFFFF);

			// enemy描画ここから----

			if (enemy->GetAlive() == 1) {
			enemy->Draw();
			}
			if (enemyB->GetAlive() == 1) {
				enemyB->Draw();
			}

			// enemy描画ここまで----

			// player.bullet描画ここから----

			if (player->GetAlive() == 1) {
			player->Draw();
			bullet->Draw();
			}

			// player.bullet描画ここまで----

			break;
		case gameClear:
			Novice::DrawSprite(0, 0, gr[2], 1, 1, 0.0f, 0xFFFFFFFF);
			break;
		case gameOver:
			Novice::DrawSprite(0, 0, gr[3], 1, 1, 0.0f, 0xFFFFFFFF);
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

// プレイヤーの弾と敵の当たり判定
void BulletEnemyCollision(Enemy& enemyObj,
	float leftTopX, float leftTopY,
	float rightBottomX, float rightBottomY)
{
	if (leftTopX < enemyObj.GetRightBottomX() && enemyObj.GetLeftTopX() < rightBottomX) {
		if (leftTopY < enemyObj.GetRightBottomY() && enemyObj.GetLeftTopY() < rightBottomY) {
			// enemyのaliveを０にする
			enemyObj.GetAlive() = 0;
		}
	}
}
void BulletEnemyBCollision(EnemyB& enemyBobj,
	float leftTopX, float leftTopY,
	float rightBottomX, float rightBottomY)
{
	if (leftTopX < enemyBobj.GetRightBottomX() && enemyBobj.GetLeftTopX() < rightBottomX) {
		if (leftTopY < enemyBobj.GetRightBottomY() && enemyBobj.GetLeftTopY() < rightBottomY) {
			// enemyのaliveを０にする
			enemyBobj.GetAlive() = 0;
		}
	}
}

void PlayerEnemyCollision(Player& playerObj, 
	float leftTopX, float leftTopY, 
	float rightBottomX, float rightBottomY)
{
	if (leftTopX < playerObj.GetRightBottomX() && playerObj.GetLeftTopX() < rightBottomX) {
		if (leftTopY < playerObj.GetRightBottomY() && playerObj.GetLeftTopY() < rightBottomY) {
			// playerのaliveを０にする
			playerObj.GetAlive() = 0;
		}
	}
}