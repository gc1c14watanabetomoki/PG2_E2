#pragma once
#include "PlayerBullet.h"

class Player {
private:
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	bool isAlive_;

	PlayerBullet* bullet_ = new PlayerBullet();
	
public:

	Player(int posX, int posY, int speed, int radius);
	//~Player();

	void Move(char *keys,char* preKeys);
	void Draw();

	void SetPos(int x, int y);
	void SetSpeed(int a);
	void SetIsAlive(bool is);
	int GetPosX();
	int GetPosY();
	int GetSpeed();
	int GetRadius();
	bool GetIsAlive();

	int GetBulletPosX();
	int GetBulletPosY();
	int GetBulletSpeed();
	int GetBulletRadius();
	bool GetBulletIsShot();

	void SetBulletisShot(bool is);

};