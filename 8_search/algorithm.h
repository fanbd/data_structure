/*顺序查找, a为数组, n为要查找的数组个数, key为要查找的关键字*/

int  Sequential_Search(int *a, int n, int key)
{
	int i;
	for (i = 1; i <= n; ++i)
		if (a[i] == key)
			return i;
	
	return 0;
}

int Sequential_Search2(int *a, int n, int key)
{
	/*有哨兵顺序查找*/
	int i;
	a[0] = key;
	i = n;
	while (a[i] != key)
		--i;
	
	return i;
}

int Binary_Search(int *a, int n, int key)
{
	/*折半查找*/
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
			high = mid-1;
		else if (key > a[mid])
			low = mid+1;
		else 
			return mid;
	}

	return 0;
}

int Fibonacci_Search(int *a, int n, int key)
{ /*斐波那契查找*/

}
