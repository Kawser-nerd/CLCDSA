using System;
using System.Collections.Generic;
using System.Linq;


public class Contest
{
	public static void Main()
	{
		int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));

//		int[] b = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
//		int[] c = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
//		int[] d = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));

		int m = a[1];
		int[][] e = new int[m][];
		for(int i=0; i<m; i++) {
			e[i] = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
			e[i] = e[i].Concat(new int[] { i }).ToArray();
		}

		Array.Sort(e,(x,y)=>((x[0]==y[0])?(x[1]-y[1]):(x[0]-y[0])));

		string[] ss = new string[m];
		int[] ccnt = new int[a[0]+1];
		for(int i=0; i<m; i++) {
			ccnt[e[i][0]]++;
			ss[e[i][2]] = String.Format("{0:D6}{1:D6}", e[i][0], ccnt[e[i][0]]);
		}

		for(int i=0; i<m; i++) Console.WriteLine(ss[i]);

//		string ans = e[1][1].ToString();

//		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}