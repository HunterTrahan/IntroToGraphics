#pragma once
class Actor
{
	public:
		Actor() {};
		~Actor() {};

		virtual bool update(double deltatime) { return true; };
		virtual bool draw() { return true; };
};

