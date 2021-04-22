#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBouncingBall.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CBouncingBall: BouncingBall class
	/////////////////////////////////////////////////////////////////////////////

	CBouncingBall::CBouncingBall()
	{
		const int INITIAL_VELOCITY = 20;	// 初始上升速度
		const int FLOOR = 665;				// 地板座標
		floor = FLOOR;
		x = 0; y = 350;				// y座標比地板高1點(站在地板上)
		righting = true;
		initial_velocity = INITIAL_VELOCITY;
		velocity = initial_velocity;
	}

	void CBouncingBall::LoadBitmap()
	{
		//char *filename[4] = { ".\\bitmaps\\ball1.bmp",".\\bitmaps\\ball2.bmp",".\\bitmaps\\ball3.bmp",".\\bitmaps\\ball4.bmp" };
		//for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
			//animation.AddBitmap(filename[i], RGB(0, 0, 0));
		char *filename[1] = { ".\\bitmaps\\bitmap7.bmp" };
		animation.AddBitmap(filename[0], RGB(255, 255, 255));
	}

	void CBouncingBall::OnMove()
	{
		if (righting) {			// 上升狀態
			if (velocity > 0) {
				x -= velocity;	// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
				velocity--;		// 受重力影響，下次的上升速度降低
			}
			else {
				righting = false; // 當速度 <= 0，上升終止，下次改為下降
				velocity = 1;	// 下降的初速(velocity)為1
			}
		}
		else {				// 下降狀態
			if (x <floor -1) {  // 當y座標還沒碰到地板
				x += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				velocity++;		// 受重力影響，下次的下降速度增加
			}
			else {
				x= 0;  // 當y座標低於地板，更正為地板上
				righting = true;	// 探底反彈，下次改為上升
				velocity = initial_velocity; // 重設上升初始速度
			}
		}
		animation.OnMove();		// 執行一次animation.OnMove()，animation才會換圖
	}

	void CBouncingBall::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}
	//-----------------------------------------------------------------------------------
	 CBouncingShootLeft::CBouncingShootLeft()
	{
		const int INITIAL_VELOCITY = 20;	// 初始上升速度
		const int FLOOR = 665;				// 地板座標
		left_floor = FLOOR;
		left_x = FLOOR-1; left_y = 200;				// y座標比地板高1點(站在地板上)
		lefting = true;
		left_initial_velocity = INITIAL_VELOCITY;
		left_velocity = left_initial_velocity;
	}

	void CBouncingShootLeft::LoadBitmap()
	{
		//char *filename[4] = { ".\\bitmaps\\ball1.bmp",".\\bitmaps\\ball2.bmp",".\\bitmaps\\ball3.bmp",".\\bitmaps\\ball4.bmp" };
		//for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
			//animation.AddBitmap(filename[i], RGB(0, 0, 0));
		char *filename1[1] = { ".\\bitmaps\\bitmap6.bmp" };
		left_animation.AddBitmap(filename1[0], RGB(255, 255, 255));
	}

	void CBouncingShootLeft::OnMove()
	{
		if (lefting) {			// 上升狀態
			if (left_velocity > 0) {
				left_x += left_velocity;	// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
				left_velocity--;		// 受重力影響，下次的上升速度降低
			}
			else {
				lefting = false; // 當速度 <= 0，上升終止，下次改為下降
				left_velocity = 1;	// 下降的初速(velocity)為1
			}
		}
		else {				// 下降狀態
			if (left_x > 0) {  // 當y座標還沒碰到地板
				left_x -= left_velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				left_velocity++;		// 受重力影響，下次的下降速度增加
			}
			else {
				left_x = left_floor-1;  // 當y座標低於地板，更正為地板上
				lefting = true;	// 探底反彈，下次改為上升
				left_velocity = left_initial_velocity; // 重設上升初始速度
			}
		}
		left_animation.OnMove();		// 執行一次animation.OnMove()，animation才會換圖
	}

	void CBouncingShootLeft::OnShow()
	{
		left_animation.SetTopLeft(left_x, left_y);
		left_animation.OnShow();
	}
}