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
		//var n_ = 100000;
		//var a_ = new int[100000];

		//
		var l = new int[n_];

		if(n_%2==0) {

			for (int i =0;i<n_/2;i++) {
				l[i] = a_[a_.Length-1-i*2];	
			}

			for (int i = 0; i < n_/2; i++) {
				l[i+n_/2] = a_[i*2];
			}

		}	else{

			for (int i = 0; i < n_ / 2+1; i++)
			{
				l[i] = a_[a_.Length - 1 - i * 2];
			}

			for (int i = 0; i < n_ / 2; i++)
			{
				l[i + n_ / 2+1] = a_[i* 2+1];
			}
		}


		//
		for (int i = 0; i < n_; i++)
		{
			if (i >= 1)
				Console.Write(" ");
			Console.Write(l[i]);
		}
		Console.WriteLine();
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