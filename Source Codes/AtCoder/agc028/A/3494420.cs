using System;
using System.Linq;

namespace agc028_a
{
	class Program
	{
		static void Main(string[] args)
		{
			long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
			long gcm = x.Min();
			while (!(x[0] % gcm == 0 && x[1] % gcm == 0)) gcm--;
			string s1 = Console.ReadLine(); string s2 = Console.ReadLine();
			string t1 = ""; string t2 = "";
			for (int i = 0; i < gcm; i++) t1 += s1[(int)(x[0] / gcm) * i];
			for (int i = 0; i < gcm; i++) t2 += s2[(int)(x[1] / gcm) * i];
			Console.WriteLine(t1 == t2 ? x[0] * x[1] / gcm : -1);
		}
	}
}