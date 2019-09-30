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
		var N_ = int.Parse(_s[0]);
		var M_ = int.Parse(_s[1]);

		long a = 0;
		long z = 1000000007;

		if (N_ == M_) {
			a = 1;
			for (int i = 1; i <= N_; i++)
			{
				a *= i;
				a = a % z;
			}
			a*= a;
			a = a % z;
			a *= 2;
			a = a % z;
			Console.WriteLine(a);
			return;
		} else if (Math.Abs(N_-M_)==1) {
			a = 1;
			for (int i = 1; i <= N_; i++)
			{
				a *= i;
				a = a%z;
			}
			for (int i = 1; i <= M_; i++)
			{
				a *= i;
				a = a % z;
			}
			Console.WriteLine(a);
			return;
		}

		Console.WriteLine(0);

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