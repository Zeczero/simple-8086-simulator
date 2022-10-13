#pragma once
#include <vector>

class CpuObject {
public: 
	virtual void Mov(int to, int from);
	virtual void FillRegisters(int registerNum, int value);
	virtual void ViewRegisters();
	virtual void GetCommand();
	virtual std::vector<int> GetRegisters();

private: 
	int AL;
	int AH;
	int BL;
	int BH;
	int CL;
	int CH;
	int DL;
	int DH;

	const static int REGISTER_SIZE = 8;
	int TO;
	int FROM;

	enum COMMANDS {
		MOV = 0
	};

};