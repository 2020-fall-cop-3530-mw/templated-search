#ifndef SEARCH_HPP
#define SEARCH_HPP

int Find (int arrayItems[], int length, int searchKey)
{
	int foundIndex = -1;

	for (int i = 0; i < length; ++i)
	{
		if (arrayItems[i] == searchKey)
		{
			foundIndex = i;
			break;
		}
	}

	return foundIndex;
}
#endif /*SEARCH_HPP*/
