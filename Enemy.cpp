#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speed, int radius,bool isAlive) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	isAlive_ = isAlive;
}


void Enemy::Move() {
	if (isAlive_ == true) {
		posX_ += speed_;

		if (posX_ < radius_) {
			posX_ = radius_;
			speed_ *= -1;
		}
		if (posX_ > 1280 - radius_) {
			posX_ = 1280 - radius_;
			speed_ *= -1;
		}
		if (posY_ < radius_) {
			posY_ = radius_;
		}
		if (posY_ > 720 - radius_) {
			posY_ = 720 - radius_;
		}
	} else {
		respawnTimer_--;
		if (respawnTimer_ <= 0) {
			isAlive_ = true;
			respawnTimer_ = baseRespawnTime;
		}
	}
	
}

void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}

void Enemy::SetPos(int x, int y) {
	posX_ = x;
	posY_ = y;
}
void Enemy::SetSpeed(int a) {
	speed_ = a;
}
void Enemy::SetIsAlive(bool is) {
	isAlive_ = is;
}

int Enemy::GetPosX() {
	return posX_;
}
int Enemy::GetPosY() {
	return posY_;
}
int Enemy::GetSpeed() {
	return speed_;
}
int Enemy::GetRadius() {
	return radius_;
}
bool Enemy::GetIsAlive() {
	return isAlive_;
}