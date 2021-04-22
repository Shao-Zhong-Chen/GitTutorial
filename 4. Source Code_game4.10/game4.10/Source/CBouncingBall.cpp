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
		const int INITIAL_VELOCITY = 20;	// ��l�W�ɳt��
		const int FLOOR = 665;				// �a�O�y��
		floor = FLOOR;
		x = 0; y = 350;				// y�y�Ф�a�O��1�I(���b�a�O�W)
		righting = true;
		initial_velocity = INITIAL_VELOCITY;
		velocity = initial_velocity;
	}

	void CBouncingBall::LoadBitmap()
	{
		//char *filename[4] = { ".\\bitmaps\\ball1.bmp",".\\bitmaps\\ball2.bmp",".\\bitmaps\\ball3.bmp",".\\bitmaps\\ball4.bmp" };
		//for (int i = 0; i < 4; i++)	// ���J�ʵe(��4�i�ϧκc��)
			//animation.AddBitmap(filename[i], RGB(0, 0, 0));
		char *filename[1] = { ".\\bitmaps\\bitmap7.bmp" };
		animation.AddBitmap(filename[0], RGB(255, 255, 255));
	}

	void CBouncingBall::OnMove()
	{
		if (righting) {			// �W�ɪ��A
			if (velocity > 0) {
				x -= velocity;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				righting = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (x <floor -1) {  // ��y�y���٨S�I��a�O
				x += velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				x= 0;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				righting = true;	// �����ϼu�A�U���אּ�W��
				velocity = initial_velocity; // ���]�W�ɪ�l�t��
			}
		}
		animation.OnMove();		// ����@��animation.OnMove()�Aanimation�~�|����
	}

	void CBouncingBall::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}
	//-----------------------------------------------------------------------------------
	 CBouncingShootLeft::CBouncingShootLeft()
	{
		const int INITIAL_VELOCITY = 20;	// ��l�W�ɳt��
		const int FLOOR = 665;				// �a�O�y��
		left_floor = FLOOR;
		left_x = FLOOR-1; left_y = 200;				// y�y�Ф�a�O��1�I(���b�a�O�W)
		lefting = true;
		left_initial_velocity = INITIAL_VELOCITY;
		left_velocity = left_initial_velocity;
	}

	void CBouncingShootLeft::LoadBitmap()
	{
		//char *filename[4] = { ".\\bitmaps\\ball1.bmp",".\\bitmaps\\ball2.bmp",".\\bitmaps\\ball3.bmp",".\\bitmaps\\ball4.bmp" };
		//for (int i = 0; i < 4; i++)	// ���J�ʵe(��4�i�ϧκc��)
			//animation.AddBitmap(filename[i], RGB(0, 0, 0));
		char *filename1[1] = { ".\\bitmaps\\bitmap6.bmp" };
		left_animation.AddBitmap(filename1[0], RGB(255, 255, 255));
	}

	void CBouncingShootLeft::OnMove()
	{
		if (lefting) {			// �W�ɪ��A
			if (left_velocity > 0) {
				left_x += left_velocity;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				left_velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				lefting = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				left_velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (left_x > 0) {  // ��y�y���٨S�I��a�O
				left_x -= left_velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				left_velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				left_x = left_floor-1;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				lefting = true;	// �����ϼu�A�U���אּ�W��
				left_velocity = left_initial_velocity; // ���]�W�ɪ�l�t��
			}
		}
		left_animation.OnMove();		// ����@��animation.OnMove()�Aanimation�~�|����
	}

	void CBouncingShootLeft::OnShow()
	{
		left_animation.SetTopLeft(left_x, left_y);
		left_animation.OnShow();
	}
}