using System;
using System.Collections.Generic;


public class Contest
{
	public static void Main()
	{
		int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));

//		int[] b = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
//		int[] c = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
//		int[] d = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));

		int n = a[0];
		int[][] e = new int[n][];
		for(int i=0; i<n; i++) e[i] = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));


		Array.Sort(e,(x,y)=>x[0]-y[0]);
		int sum = e[e.Length-1][0]/2;
		for(int i=0; i<e.Length-1;i++) sum += e[i][0];

		string ans = sum.ToString();

		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}