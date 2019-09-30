using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

class _Class
{
	void _Do()
	{
		//
		var _s = _stringArray();
		var n_ = int.Parse(_s[0]);

		var a_ = _intArray();

		Array.Sort(a_);
		Array.Reverse(a_);

		int a=0;
		int b = 0;
		int i = 0;
		for (;i<n_-1;i++) {

			int x1 = a_[i];
			int x2 = a_[i+1];

			if (x1 == x2)
			{
				if (a == 0)
				{
					a = x1;
					i++;
				}
				else
				{
					b = x1;
					break;
				}
			}
		}
		Console.WriteLine(((long)(a))*b);
	}	

	static void Main(string[] args)
	{
		new _Class()._Do();
	}


	// 1
	string[] _stringArray()
	{
		return Console.ReadLine().Split();
	}

	// 2.1 -2,147,483,648 ~ +2,147,483,647
	int[] _intArray()
	{
		var _s = Console.ReadLine().Split();

		var x = new int[_s.Length];
		for (var i = 0; i < _s.Length; i++)
			x[i] = int.Parse(_s[i]);

		return x;
	}

	// 2.2 -9,223,372,036,854,775,808 ~ +9,223,372,036,854,775,807
	long[] _longArray()
	{
		var _s = Console.ReadLine().Split();

		var x = new long[_s.Length];
		for (var i = 0; i < _s.Length; i++)
			x[i] = long.Parse(_s[i]);

		return x;
	}
}