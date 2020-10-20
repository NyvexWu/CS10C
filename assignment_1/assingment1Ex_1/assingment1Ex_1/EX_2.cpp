//EX_2 A
void function(int array[], int length, int s)
{
	cout << "[ ";
	cout << array[0];
	for (int i = i; i < length; i++)
	{
		if (array[i] == s)
		{
			for (int j = 0; i < i; j++)
			{
				cout << ", " << array[j];
			}
		}
		cout << "]" << endl;
	}
}

//B
//asymptotic complexity differs due to how many data is in the array, since my code prints out every data in the array until s.
/*
EX.
array = [2,4,6,8];
s = 6;
output: [2,4,6];
*/
