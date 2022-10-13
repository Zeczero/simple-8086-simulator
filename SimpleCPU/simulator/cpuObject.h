#pragma once
#include <vector>
#include <string>

class CpuObject {
public: 
	virtual void Mov (int to, int from);
	virtual void FillRegisters(int registerNum, int value);
	virtual void ViewRegisters();
	virtual void UpdateRegisters();
	virtual void GetCommand(int cmd);
	const char* NAMES[8] = { "AL", "AH", "BL", "BH", "CL", "CH", "DL", "DH" };
	bool stop = false;
	virtual std::vector<int> GetRegisters();

private: 
	int AL, AH, BL, BH, CL, CH, DL, DH;
	int ALL_REGISTERS[8] = { AL, AH, BL, BH, CL, CH, DL, DH };
	const static int REGISTER_SIZE = 8;

	enum COMMANDS {
		MOV = 0,
		STOP = 1
	};
};