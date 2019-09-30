using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using static System.Math;

class Program{
	static int n;
	static long k;
	static int[] a;
	static int[] b;
	static long[] count; //count[i] : i???????????

	static void Main(){
		/* ????? */
		string[] input = Console.ReadLine().Split();
		n = int.Parse(input[0]);
		k = long.Parse(input[1]);
		a = new int[n];
		b = new int[n];
		for (int i = 0;i < n;i++){
			input = Console.ReadLine().Split();
			a[i] = int.Parse(input[0]);
			b[i] = int.Parse(input[1]);
		}

		/* count??? */
		count = new long[a.Max() + 1];
		for (int i = 0;i < n;i++) //????????
			count[a[i]] += b[i];

		/* ????? */
		long index = 0;
		for (int i = 0;i < count.Length;i++){
			index += count[i];
			if (index >= k){
				Console.WriteLine(i);
				return;
			}
		}
	}
}