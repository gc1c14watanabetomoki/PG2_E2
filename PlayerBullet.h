#pragma once

typedef struct Transform {
	int posX;
	int posY;
	int radius;
	int speed;
	bool isShot = false;
}Transform;

class PlayerBullet {
public:
	Transform transform_{-100,-100,15,10,false};

public:

	PlayerBullet();
	void Move();
	void Draw();
	int GetPosX();
};