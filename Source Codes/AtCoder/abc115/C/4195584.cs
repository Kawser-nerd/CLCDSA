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

		int[] diff = new int[a[0]-a[1]+1];
		for(int i=a[1]-1; i<a[0];i++) diff[i-a[1]+1] = e[i][0]-e[i-a[1]+1][0];

		Array.Sort(diff);

		string ans = diff[0].ToString();

		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}