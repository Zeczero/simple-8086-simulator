#include <iostream>;
#include "simulator/cpuObject.h";

int main()
{
    CpuObject cpu;
    std::cout << "\t============= Intel 8086 Simulator ===================" << std::endl;
    std::cout << "\t====================  2022   =======================" << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < CpuObject::REGISTER_SIZE; i++) {
        int n;
        std::cout << "Prosze wpisac wartosc dla rejestru " << cpu.NAMES[i] << ": ";
        std::cin >> std::hex >> n;
        cpu.FillRegisters(i, n);
    }

    std::cout << "\n";
    cpu.UpdateRegisters();
    cpu.DeployPointers();
    cpu.ViewRegisters();

    std::vector<int> registers = cpu.GetRegisters();

    while (!cpu.STOP) {
        int sel;
        std::cout << "Wybierz Komende: \n";
        std::cout << "0. MOV {TO} {FROM}" << std::endl;
        std::cout << "1. WYJDZ Z PROGRAMU" << std::endl;
        std::cout << "2. Xchng {TO} {FROM}" << std::endl;
        std::cout << "3. INC {REGISTER}" << std::endl;
        std::cout << "4. DEC {REGISTER} " << std::endl;
        std::cout << "5. OPERACJA NOT {REGISTER}" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> sel;

        cpu.GetCommand(sel);
    }
}

