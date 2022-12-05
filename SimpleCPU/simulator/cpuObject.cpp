#include "cpuObject.h";
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
		std::cout << "ZAWARTOSC REJESTRU: " << NAMES[i] << ": 0x" << std::hex << ALL_REGISTERS[i] << " ADRES PAMIECI: " << REGISTER_ADDRESSES[i] << std::endl;
	}
}

void CpuObject::DeployPointers() {
	for (size_t i = 0; i < REGISTER_SIZE; i++) {
		REGISTER_ADDRESSES[i] = &ALL_REGISTERS[i];
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
			std::cout << i << ". " << NAMES[i] << std::endl;
		}
		std::cout << "Wybierz rejestr koncowy: ";
		std::cin >> reg;
		std::cout << "Wybierz rejestr poczatkowy: ";
		std::cin >> reg2;
		Mov(reg, reg2);
		break;
	case EXIT: 
		STOP = true;
			break;
	case Exchange:
		int registerTo, registerFrom;
		for (int i = 0; i < REGISTER_SIZE; i++) {
			std::cout << i << ". " << NAMES[i] << std::endl;
		}
		std::cout << "Wybierz rejestr zamiany 1: ";
		std::cin >> reg;
		std::cout << "Wybierz rejestr zamiany 2: ";
		std::cin >> reg2;
		Xchng(reg, reg2);
		break;
	case INCREASE:
		int toIncrease;
		for (int i = 0; i < REGISTER_SIZE; i++) {
			std::cout << i << ". " << NAMES[i] << std::endl;
		}
		std::cout << "Wybierz rejestr do inkrementacji: ";
		std::cin >> toIncrease;
		INC(toIncrease);
		break;
	case DECREASE: 
		int toDecrease;
		for (int i = 0; i < REGISTER_SIZE; i++) {
			std::cout << i << ". " << NAMES[i] << std::endl;
		}
		std::cout << "Wybierz rejestr do dekrementacji: ";
		std::cin >> toDecrease;
		DEC(toDecrease);
	case NOTOPERATION:
		int toNOT;
		for (int i = 0; i < REGISTER_SIZE; i++) {
			std::cout << i << ". " << NAMES[i] << std::endl;
		}
		std::cout << "Wybierz rejestr do operacji NOT: ";
		std::cin >> toNOT;
		NOT(toNOT);
	}
}
void CpuObject::Xchng(int Registerto, int Registerfrom) {
	int temp = ALL_REGISTERS[Registerto];
	ALL_REGISTERS[Registerto] = ALL_REGISTERS[Registerfrom];
	ALL_REGISTERS[Registerfrom] = temp;
	ViewRegisters();
}
void CpuObject::INC(int registerId) {
	ALL_REGISTERS[registerId]++;
	ViewRegisters();
}
void CpuObject::DEC(int registerId) {
	ALL_REGISTERS[registerId]--;
	ViewRegisters();
}
void CpuObject::NOT(int registerId) {
	int NOTTED = ~ALL_REGISTERS[registerId];
	ALL_REGISTERS[registerId] = NOTTED;
	ViewRegisters();
}