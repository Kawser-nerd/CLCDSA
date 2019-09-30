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
/*
		int m = a[1];
		int[][] e = new int[m][];
		for(int i=0; i<m; i++) {
			e[i] = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
			e[i] = e[i].Concat(new int[] { i }).ToArray();
		}

		Array.Sort(e,(x,y)=>((x[0]==y[0])?(x[1]-y[1]):(x[0]-y[0])));
*/

		int h=a[0];int w=a[1];int k=a[2];
		
		int total = (int)Math.Pow(2,w-1);

		int[,] route = new int[w,total];
		bool[] valid = new bool[total];
		ulong[,] rcnt = new ulong[w,w];

		for(int j=0; j<total; j++){
			valid[j] = true;
			for(int i=0; i<w-2; i++) if( (((j>>i)&1)==1) && (((j>>(i+1))&1)==1) ) {
				valid[j] = false;
				break;
			}
			if (!valid[j]) continue;
			
			route[0,j] = ((j&1)==0) ? 0 : 1 ;
			for(int i=1; i<w-1; i++)	{
				if(((j>>(i-1))&1)==0) {
					route[i,j] = (((j>>i)&1)==0) ? i : i+1 ;
				}else{
					route[i,j] = i-1;
				}
			}
			route[w-1,j] = (((j>>(w-2))&1)==0) ? w-1 : w-2 ;
			
			for(int i=0; i<w; i++)	rcnt[i,route[i,j]]++;
		}

		ulong[] tcnt = new ulong[w];
		tcnt[0] = 1;
		for(int i=0; i<h; i++){
			ulong[] tmp = new ulong[w];
			for(int l=0; l<w; l++)for(int p=0; p<w; p++)	tmp[p] += rcnt[l,p]*tcnt[l];
			for(int p=0; p<w; p++)	tcnt[p] = tmp[p]%1000000007;
		}

		string ans = tcnt[k-1].ToString();

		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}