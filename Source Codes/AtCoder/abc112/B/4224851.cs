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

		int n = a[0];
		int[][] e = new int[n][];
		for(int i=0; i<n; i++) {
			e[i] = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
			e[i] = e[i].Concat(new int[] { i }).ToArray();
		}

		Array.Sort(e,(x,y)=>(x[0]-y[0]));

		string h = "TLE";
		for(int i=0; i<n; i++){
			if(e[i][1]<=a[1]) {
				h = e[i][0].ToString();
				break;
			}
		}

		string ans = h.ToString();

		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}