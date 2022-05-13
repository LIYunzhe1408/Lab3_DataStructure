#include "../FindSameMinNumber.h"

void Input(int *array, int arrayNum)
{
	std::cout << "Input " << arrayNum << " elements: ";
	for(int i = 0; i< arrayNum; i++)
		std::cin >> array[i];
}

int main()
{
	int a[10], b[10], c[10], aNum, bNum, cNum;
	std::cout << "Input 3 numbers as the size of 3 array: "; std::cin >> aNum >> bNum >> cNum;
	
	Input(a, aNum);Input(b, bNum);Input(c, cNum);
	
	
	// O(n), but elseif num is too much
	std::cout << "=================================================================" << std::endl;
	std::cout << "O(n), second optimal algorithm" << std::endl;
	if ( FindMinNumber_elseif(a, b, c, aNum, bNum, cNum)) 
		std::cout << "Founded" << std::endl;
	else 
		std::cout << "Not Founded" << std::endl;
	
	// O(n), optimal algorithm
	std::cout << "=================================================================" << std::endl;
	std::cout << "O(n), optimal algorithm" << std::endl;
	if ( FindMinNumber_if(a, b, c, aNum, bNum, cNum)) 
		std::cout << "Founded" << std::endl;
	else 
		std::cout << "Not Founded" << std::endl;
		
	// O(n^3)
	std::cout << "=================================================================" << std::endl;
	std::cout << "O(n^3) algorithm" << std::endl;
	if ( FindMinNumber_slow(a, b, c, aNum, bNum, cNum)) 
		std::cout << "Founded" << std::endl;
	else 
		std::cout << "Not Founded" << std::endl;
	
	return 0;
}
