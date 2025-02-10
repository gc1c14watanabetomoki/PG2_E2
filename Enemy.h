#pragma once

class Enemy {
private:
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	bool isAlive_;
	const int baseRespawnTime = 300;
	int respawnTimer_ = baseRespawnTime;

public:

	Enemy(int posX, int posY, int speed, int radius,bool isAlive);

	void Move();
	void Draw();

	void SetPos(int x, int y);
	void SetSpeed(int a);
	void SetIsAlive(bool is);
	
	int GetPosX();
	int GetPosY();
	int GetSpeed();
	int GetRadius();
	bool GetIsAlive();
};