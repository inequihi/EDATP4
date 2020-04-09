#pragma once
class Simulation
{
public:
	Simulation();
	void startMoving(int);
	void stopMoving(int);
	void refresh(void);
	void quit(void);
	bool running(void);
private:
	bool continueRunning;
};