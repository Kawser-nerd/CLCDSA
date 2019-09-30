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
		var Na = _int();

		var N_?=Na[0];
		var T_? = Na[1];

		var t_?? = _int();
		int sum = 0;
		for (int i = N_? - 1; i >= 0; i--)
		{
			if (i == N_? - 1)
				sum += (T_?);
			else
			{
				var a = (t_??[i + 1] - t_??[i]);
				sum += Math.Min(T_?,a);
			}
		}
		Console.WriteLine(sum);
	}

	static void Main(string[] args)
  {
    new _Class()._Do();
  }

#region

  string _string()
  {
    return Console.ReadLine();
  }

	//
	string[] _strings()
  {
    return Console.ReadLine().Split();
  }

  int[] _int(int n)
  {
    var x = new int[n];
    for (var i = 0; i < n; i++)
    {
      x[i] = int.Parse(Console.ReadLine());
    }
    return x;
  }

	//
	int[] _int()
  {
    var ss = Console.ReadLine().Split();

    var x = new int[ss.Length];
    for (var i = 0; i < ss.Length; i++)
      x[i] = int.Parse(ss[i]);

    return x;
  }

	long[] _long()
	{
		var ss = Console.ReadLine().Split();

		var x = new long[ss.Length];
		for (var i = 0; i < ss.Length; i++)
			x[i] = long.Parse(ss[i]);

		return x;
	}
#endregion

}