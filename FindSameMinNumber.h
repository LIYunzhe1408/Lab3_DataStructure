#include <iostream>
/**
** Second efficient algorithm.
** [param] 3 array and 3 array size
** [out] Found: output min same number and their position, return true
**/
bool FindMinNumber_elseif(const int *a, const int * b, const int *c, int aNum, int bNum, int cNum)
{
	int i = 0, j = 0, k = 0, same_min_number, cnt = 0;
	while(i < aNum && j < bNum && k < cNum)
	{
		cnt ++;
		if(a[i] < b[j]) i++;
		else if(b[j] < c[k]) j++;
		else if(c[k] < a[i]) k++;
		else
			{
				same_min_number = a[i];
				std::cout << same_min_number << " " << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
				std::cout << "cnt_elseif = " << cnt << std::endl;
				return true;
			}
	}
	return false;
}

/**
** Most efficient algorithm.
** [param] 3 array and 3 array size
** [out] Found: output min same number and their position, return true
**/
bool FindMinNumber_if(const int *a, const int * b, const int *c, int aNum, int bNum, int cNum)
{
	int i = 0, j = 0, k = 0, same_min_number, cnt = 0;
	while(i < aNum && j < bNum && k < cNum)
	{
		cnt ++;
		if(a[i] < b[j]) i++;
		if(b[j] < c[k]) j++;
		if(c[k] < a[i]) k++;
		if(a[i] == b[j] && b[j] == c[k])  
		{
			same_min_number = a[i];
			std::cout << same_min_number << " " << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;	 
				std::cout << "cnt_if = " << cnt << std::endl;
			return true;
		}
	}
	return false;
}


/**
** Least efficient algorithm. 
**Traverse a, b and c, if found same number in a and b, search in c.
** [param] 3 array and 3 array size
** [out] Found: output min same number and their position, return true
**/
bool FindMinNumber_slow(const int *a, const int * b, const int *c, int aNum, int bNum, int cNum)
{
	for(int i = 0; i < aNum; i++)
		for(int j = 0; j < bNum; j++)
			if(a[i] == b[j])
				for(int k = 0; k < cNum; k++)
					if (c[k] == a[i]){std::cout << c[k] << " " << i + 1 << " " << j + 1 << " " << k + 1 << std::endl; return true;}
		
	return false;
}

