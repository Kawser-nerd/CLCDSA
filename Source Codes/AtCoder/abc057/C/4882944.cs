using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using static System.Math;

class Program{
	static long n;

	static void Main(){
		n = long.Parse(Console.ReadLine());
		long border = (long)Pow(n,0.5);
		while (border > 0){
			if (n % border != 0){
				border--;
				continue;
			}
			long bigger = n / border;
			Console.WriteLine(Count(bigger));
			return;
		}
	}

	static int Count(long k){ //k???
		int c = 0;
		while (k > 0){
			k /= 10;
			c++;
		}
		return c;
	}
}