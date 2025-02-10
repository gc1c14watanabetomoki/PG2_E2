#include "Novice.h"
#include "PlayerBullet.h"

PlayerBullet::PlayerBullet() {
	transform_.posX = 0;
	transform_.posY = 0;
	transform_.radius = 15;
	transform_.speed = 10;
	transform_.isShot = false;
}

void PlayerBullet::Move() {
	if (transform_.isShot == true) {
		transform_.posY -= transform_.speed;
		if (transform_.posY < 0 - transform_.radius) {
			transform_.isShot = false;
		}
	} else {

	}
}

void PlayerBullet::Draw() {
	if (transform_.isShot == true) {
		Novice::DrawEllipse(transform_.posX, transform_.posY, transform_.radius, transform_.radius, 0.0f, WHITE, kFillModeSolid);
	}
}

/*
int PlayerBullet::GetPosX() {

}
*/