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
/*
		int n = a[0];
		int[][] e = new int[n][];
		for(int i=0; i<n; i++) e[i] = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
*/

		string q = "";
		switch(a[0]){
			case 22: q="Christmas Eve Eve Eve";break;
			case 23: q="Christmas Eve Eve";break;
			case 24: q="Christmas Eve";break;
			case 25: q="Christmas";break;
			default : break;
		}

		string ans = q.ToString();

		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}