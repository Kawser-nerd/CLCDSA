using System;
using System.Collections.Generic;


public class Contest
{
	public static void Main()
	{
		ulong[] a = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,ulong>(s => ulong.Parse(s)));

//		int[] b = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
//		int[] c = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
//		int[] d = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
/*
		int n = a[0];
		int[][] e = new int[n][];
		for(int i=0; i<n; i++) e[i] = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string,int>(s => int.Parse(s)));
*/

		ulong[] pans = new ulong[a[0]+1];
		ulong[] pats = new ulong[a[0]+1];
		pans[0] = 0;
		pats[0] = 1;
		for(ulong i=1; i<=a[0];i++) {
			pans[i] = pans[i-1]*2+2;
			pats[i] = pats[i-1]*2+1;
		}

		ulong cnt = 0;
		ulong k = a[1];
		for(ulong i=a[0]; 0<i;i--) {
			if(k==0) {
				break;
			} else if(k==1){
				break;
			} else if(k<=(pans[i-1]+pats[i-1]+1)){
				k--;
			} else if(k==(pans[i-1]+pats[i-1]+2)){
				cnt += pats[i-1]+1;
				break;
			} else if(k<=((pans[i-1]+pats[i-1])*2+2)){
				cnt += pats[i-1]+1;
				k = k-pans[i-1]-pats[i-1]-2;
			} else if(k==((pans[i-1]+pats[i-1])*2+3)){
				cnt += pats[i-1]*2+1;
				break;
			} else {
				break;
			}
			if((i==1)&&(k==1)) cnt++;
		}

		string ans = cnt.ToString();

		Console.WriteLine(ans);
	}
	
	private static int calc_main(int[] a,int[] b,int[] c,int[] d) {



		return 0;
	}




}