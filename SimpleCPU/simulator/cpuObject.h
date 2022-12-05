#pragma once
#include <vector>
#include <string>

class CpuObject {
public: 
	virtual void Mov (int to, int from);
	virtual void FillRegisters(int registerNum, int value);
	virtual void ViewRegisters();
	virtual void UpdateRegisters();
	virtual void DeployPointers();
	virtual void INC(int registerId);
	virtual void DEC(int registerId);
	virtual void NOT(int registerId);
	virtual void Xchng(int Registerto, int Registerfrom);
	virtual void GetCommand(int cmd);
	const char* NAMES[8] = { "AL", "AH", "BL", "BH", "CL", "CH", "DL", "DH" };
	bool STOP = false;
	const static int REGISTER_SIZE = 8;
	virtual std::vector<int> GetRegisters();

private: 
	int AL, AH, BL, BH, CL, CH, DL, DH;
	int ALL_REGISTERS[8] = { AL, AH, BL, BH, CL, CH, DL, DH };
	int* REGISTER_ADDRESSES[8];

	enum COMMANDS {
		MOV = 0,
		EXIT = 1,
		Exchange = 2,
		INCREASE = 3,
		DECREASE = 4,
		NOTOPERATION = 5,
	};
};