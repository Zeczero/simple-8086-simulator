#include "cpuObject.h";
#include <iostream>


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

void CpuObject::ViewRegisters() {
	std::vector<int> registers = GetRegisters();
	for (int i = 0; i != REGISTER_SIZE; i++) {
		std::cout << "Zawartosc rejestru " << i + 1 << " : " << std::hex << registers[i] << std::endl;
	}
}

void CpuObject::Mov(int to, int from) {

}
void CpuObject::GetCommand() {

}