using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
	static void Main(string[] args)
	{
		long N = long.Parse(Console.ReadLine());
		int ix = 0;
		int iy = 0;
		long m = 2;
		long t = m;
		long h = 1;
		long[,]A = new long[500,500];
		long[,]B = new long[500,500];
		long[,]C = new long[500,500];
		long at = 0;
		var list = GeneratePrime(10000);
		while(true){
			if((ix+iy)%2==0){
				B[ix,iy] = list[249+(ix-iy)/2];
				C[ix,iy] = list[500];
				if(ix+iy>500){
					C[ix,iy] = list[((ix+iy)-500)/2*2+499];
				} else if(ix+iy<500){
					C[ix,iy] = list[(500-(ix+iy))/2*2+500];
				}
				A[ix,iy]=(long)B[ix,iy] * (long)C[ix,iy];
			}
			ix += 1;
			if(ix>=500){
				iy += 1;
				ix = 0;
				if(iy==500){
					break;
				}
			}
		}
		ix = 0;
		iy = 0;
		while(true){
			if((ix+iy)%2==1){
				long aa = 1;
				if(ix==0){
					if(iy<499){
						aa *= B[ix,iy+1];
					}
				} else {
					aa *= B[ix-1,iy];
				}
				if(ix==499){
					if(iy>0){
						aa *= B[ix,iy-1];
					}
				} else {
					aa *= B[ix+1,iy];
				}
				if(ix==499){
					if(iy<499){
						aa *= C[ix,iy+1];
					}
				} else {
					aa *= C[ix+1,iy];
				}
				if(ix==0){
					if(iy>0){
						aa *= C[ix,iy-1];
					}
				} else {
					aa *= C[ix-1,iy];
				}
				A[ix,iy] = aa + 1;
			}
			ix += 1;
			if(ix>=500){
				iy += 1;
				ix = 0;
			}
			if(iy>=500){
				break;
			}
		}
		for(var i=0;i<N;i++){
			string str = "";
			str += A[0,i];
			for(var j=1;j<N;j++){
				str += " " + A[j,i];
			}
			Console.WriteLine(str);
		}
	}
	
	public static List<int> GeneratePrime(int max)
	{
		System.Diagnostics.Debug.Assert(max >= 2);
		int prime;
		double sqrtMax = Math.Sqrt(max);
		var primeList = new List<int>();
		var searchList = Enumerable.Range(2, max - 1).ToList();
		do
		{
			prime = searchList.First();
			primeList.Add(prime);
			searchList.RemoveAll(n => n % prime == 0);
		} while (prime < sqrtMax);
		primeList.AddRange(searchList);
		return primeList;
	}
}