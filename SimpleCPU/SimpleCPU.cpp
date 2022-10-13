#include <iostream>;
#define FETCH_NAME(var)  #var
#include "simulator/cpuObject.h";


int main()
{

    CpuObject cpu;
    std::cout << "\t============= Intel 8086 Simulator ===================" << std::endl;
    std::cout << "\t============= Written by soczix ===================" << std::endl;
    std::cout << "\t====================  2022   =======================" << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i <= 7; i++) {
        int n;
        int cnt = i + 1;
        std::cout << "Prosze wpisac wartosc dla rejestru " << cnt  << ": ";
        std::cin >> std::hex >> n;
        cpu.FillRegisters(i, n);
    }
    // ssdasd
    std::cout << "\n";
    cpu.ViewRegisters();

    std::vector<int> registers = cpu.GetRegisters();

    // TO DO: IMPLEMENT MOV COMMAND

}

