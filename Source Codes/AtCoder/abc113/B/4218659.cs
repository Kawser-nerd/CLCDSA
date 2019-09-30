using System;
using System.Collections.Generic;


public class Contest
{
	public static void Main()
	{
		int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));

		int[] b = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
		int[] c = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
//		int[] d = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
/*
		int n = a[0];
		int[][] e = new int[n][];
		for(int i=0; i<n; i++) e[i] = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
*/

		double ss = (double)(b[0]-b[1])/0.006;
		double m = Math.Abs(ss-c[0]);
		int idx = 0;
		for(int i=1; i<c.Length; i++) if(Math.Abs(ss-c[i]) < m) {
			m = Math.Abs(ss-c[i]);
			idx = i;
		}

		string ans = (idx+1).ToString();

		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}