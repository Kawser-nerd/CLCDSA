using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Numerics;

//using static System.Console;

class _Class
{

  void _Do()
  {
		var s = Split.strings();
		var arr = Split.ints();
		//Array.Sort(i);
		var N = arr.Length;

		var arr2 = new int[100005];
		for (int a = 0; a < N; a++)
		{
			arr2[arr[a]]+=1;
			arr2[arr[a]+1]+=1;
			arr2[arr[a]+2]+=1;
		}
		Array.Sort(arr2);
		Array.Reverse(arr2);

		//
		Console.WriteLine(arr2[0]);
 
  }
  
	static void Main(string[] args)
	{
		new _Class()._Do();
	}

}

//
static class Split
{
	// 1
	public static string[] strings()
	{
		return Console.ReadLine().Split();
	}

  // [2.1] -2,147,483,648 ~ +2,147,483,647
  public static int[] ints()
	{
		var _s = Console.ReadLine().Split();

		var x = new int[_s.Length];
		for (var i = 0; i < _s.Length; i++)
			x[i] = int.Parse(_s[i]);

		return x;
	}

	// [2.2] 
	// -9,223,372,036,854,775,808 ~ 
	// +9,223,372,036,854,775,807
	public static long[] longs()
	{
		var _s = Console.ReadLine().Split();

		var x = new long[_s.Length];
		for (var i = 0; i < _s.Length; i++)
			x[i] = long.Parse(_s[i]);

		return x;
	}

	public static BigInteger[] bigs()
	{
		var _s = Console.ReadLine().Split();

		var x = new BigInteger[_s.Length];
		for (var i = 0; i < _s.Length; i++)
			x[i] = BigInteger.Parse(_s[i]);

		return x;
	}
}