namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供會一直彈跳的球
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////

	class CBouncingBall {
	public:
		CBouncingBall();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetFloor(int);
		void SetXY(int, int);
		void SetVelocity(int);
	private:
		int x, y;
		int floor;
		bool righting;
		int initial_velocity;
		int velocity;
		CAnimation animation;


	};
	class CBouncingShootLeft{
	public:
		CBouncingShootLeft();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetFloor(int);
		void SetXY(int, int);
		void SetVelocity(int);
	private:
		int left_x, left_y;
		int left_floor;
		bool lefting;
		int left_initial_velocity;
		int left_velocity;
		CAnimation left_animation;

	};
}