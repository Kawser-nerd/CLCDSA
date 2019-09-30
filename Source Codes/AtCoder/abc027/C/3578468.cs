using System;

namespace abc027_c
{
	class Program
	{
		static void Main(string[] args)
		{
			long n = long.Parse(Console.ReadLine());
			int count = 0;
			while (n >> count > 0) count++;
			long x = 1; bool b = count % 2 == 0;
			bool ret = count % 2 == 0;
			while (true)
			{
				if (ret) x = x * 2;
				else x = x * 2 + 1;
				if (x > n) break;
				ret = !ret;
			}
			Console.WriteLine(ret == b ? "Aoki" : "Takahashi");
		}
	}
}