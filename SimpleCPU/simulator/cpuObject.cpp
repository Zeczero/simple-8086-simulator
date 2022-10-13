#include "cpuObject.h";
#define FETCH_NAME(var)  #var
#include <iostream>
#include <string>

void CpuObject::FillRegisters(int registerNum, int value) {

	switch (registerNum) {
		case 0:
			AL = value;
			break;
		case 1:
			AH = value;
			break;
		case 2:
			BL = value;
			break;
		case 3:
			BH = value;
			break;
		case 4:
			CL = value;
			break;
		case 5:
			CH = value;
			break;
		case 6:
			DL = value;
			break;
		case 7:
			DH = value;
			break;
		default:
			std::cout << "Nieprawidlowy rejestr";
			break;
	}
}

std::vector<int> CpuObject::GetRegisters() {
	return std::vector<int> { AL, AH, BL, BH, CL, CH, DL, DH };
}

void CpuObject::UpdateRegisters() {
	std::vector<int> registers = GetRegisters();
	for (size_t i = 0; i < REGISTER_SIZE; i++) {
		ALL_REGISTERS[i] = registers[i];
	}
}

void CpuObject::ViewRegisters() {
	for (int i = 0; i != REGISTER_SIZE; i++) {
		std::cout << "Zawartosc rejestru " << NAMES[i]  << " : " << std::hex << ALL_REGISTERS[i] << std::endl;
	}
}


void CpuObject::Mov(int to,  int from) {
	ALL_REGISTERS[to] = ALL_REGISTERS[from];
	ViewRegisters();
}
void CpuObject::GetCommand(int cmd) {
	switch (cmd) {
	case MOV:
		int reg, reg2;
		for (int i = 0; i < REGISTER_SIZE; i++) {
			std::cout << i << NAMES[i] << std::endl;
		}
		std::cout << "Wybierz rejestr koncowy: ";
		std::cin >> reg;
		std::cout << "Wybierz rejestr poczatkowy: ";
		std::cin >> reg2;
		Mov(reg, reg2);
		break;
	case STOP: 
		stop = true;
			break;
	}
}