#include "Novice.h"
#include "Player.h"


Player::Player(int posX, int posY, int speed, int radius) {
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	isAlive_ = true;
	bullet_->transform_.posX = 0;
	bullet_->transform_.posY = 0;
	bullet_->transform_.isShot = false;
	bullet_->transform_.radius = 15;
	bullet_->transform_.speed = 10;
}

void Player::Move(char* keys,char* preKeys) {
	if (isAlive_ == true) {
		if (keys[DIK_UP] || keys[DIK_W]) {
			posY_ -= speed_;
		}
		if (keys[DIK_LEFT] || keys[DIK_A]) {
			posX_ -= speed_;
		}
		if (keys[DIK_DOWN] || keys[DIK_S]) {
			posY_ += speed_;
		}
		if (keys[DIK_RIGHT] || keys[DIK_D]) {
			posX_ += speed_;
		}
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			if (bullet_->transform_.isShot == false) {
				bullet_->transform_.isShot = true;
				bullet_->transform_.posX = posX_;
				bullet_->transform_.posY = posY_;
			}
		}

		if (posX_ < radius_) {
			posX_ = radius_;
		}
		if (posX_ > 1280 - radius_) {
			posX_ = 1280 - radius_;
		}
		if (posY_ < radius_) {
			posY_ = radius_;
		}
		if (posY_ > 720 - radius_) {
			posY_ = 720 - radius_;
		}
	}
	

	bullet_->Move();

}

void Player::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	bullet_->Draw();
}

void Player::SetPos(int x, int y) {
	posX_ = x;
	posY_ = y;
}
void Player::SetSpeed(int a) {
	speed_ = a;
}
void Player::SetIsAlive(bool is) {
	isAlive_ = is;
}

int Player::GetPosX() {
	return posX_;
}
int Player::GetPosY() {
	return posY_;
}
int Player::GetSpeed() {
	return speed_;
}
int Player::GetRadius() {
	return radius_;
}
bool Player::GetIsAlive() {
	return isAlive_;
}


int Player::GetBulletPosX() {
	return bullet_->transform_.posX;
}
int Player::GetBulletPosY() {
	return bullet_->transform_.posY;
}
int Player::GetBulletSpeed() {
	return bullet_->transform_.speed;
}
int Player::GetBulletRadius() {
	return bullet_->transform_.radius;
}
bool Player::GetBulletIsShot() {
	return bullet_->transform_.isShot;
}
void Player::SetBulletisShot(bool is) {
	bullet_->transform_.isShot = is;
}