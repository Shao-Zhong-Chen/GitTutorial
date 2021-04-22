namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѷ|�@���u�����y
	// �����N�i�H��g���ۤv���{���F
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