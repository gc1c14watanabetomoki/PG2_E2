#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC1C_14_ワタナベ_トモキ_タイトル";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player(640,640,5,30);
	Enemy* enemy = new Enemy(640, 200, 4, 25,true);

	enum Scene {
		Title,
		Game,
		GameOver
	};
	int scene = Title;

	const int baseSceneChangeTime = 60;
	int sceneChangeTimer = baseSceneChangeTime;

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
		case Title:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				player = new Player(640, 640, 5, 30);
				enemy = new Enemy(640, 200, 4, 25, true);
				scene = Game;
			}

			break;

		case Game:

			player->Move(keys, preKeys);
			enemy->Move();

			///当たり判定処理・敵と弾
			if (player->GetBulletIsShot() == true && enemy->GetIsAlive() == true) {
				float distX = float(enemy->GetPosX() - player->GetBulletPosX());
				float distY = float(enemy->GetPosY() - player->GetBulletPosY());
				float distance = (distX * distX) + (distY * distY);
				int radius = enemy->GetRadius() + player->GetBulletRadius();
				if (distance < radius * radius) {
					player->SetBulletisShot(false);
					enemy->SetIsAlive(false);
				}
			}
			///当たり判定処理・プレイヤーと敵
			if (player->GetIsAlive() == true && enemy->GetIsAlive() == true) {
				float distX = float(enemy->GetPosX() - player->GetPosX());
				float distY = float(enemy->GetPosY() - player->GetPosY());
				float distance = (distX * distX) + (distY * distY);
				int radius = enemy->GetRadius() + player->GetRadius();
				if (distance < radius * radius) {
					player->SetIsAlive(false);
				}
			}

			if (player->GetIsAlive() == false) {
				sceneChangeTimer--;
				if (sceneChangeTimer <= 0) {
					scene = GameOver;
					sceneChangeTimer = baseSceneChangeTime;
				}
			}

			break;
		case GameOver:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				delete player;
				delete enemy;
				scene = Title;
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
		case Title:

			Novice::ScreenPrintf(100, 360, "TITLE");


			break;
		case Game:



			player->Draw();
			enemy->Draw();



			break;
		case GameOver:


			Novice::ScreenPrintf(100, 360, "GAME OVER");



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
