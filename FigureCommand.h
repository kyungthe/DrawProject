#pragma once
class CFigureCommand
{
public:
	virtual void execute(void) = 0;
	virtual ~CFigureCommand() {}
};

