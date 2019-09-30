using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		long ans = 0;
		int l = 0;
		int r = 0;
		long totsum = 0;
		long totxor = 0;
		while(l < N){
			if(l == r){
				totsum = A[l];
				totxor = A[r];
				r++;
			} else {
				totsum -= A[l - 1];
				totxor ^= A[l - 1];
			}
			while(r < N){
				totsum += A[r];
				totxor ^= A[r];
				if(totsum == totxor){
					r++;
					continue;
				}
				totsum -= A[r];
				totxor ^= A[r];
				break;
			}
//Console.WriteLine("l:{0}, r:{1}, totsum = {2}, totxor = {3}",l, r, totsum, totxor);
			ans += r - l;
			l++;
		}
		Console.WriteLine(ans);
		
		
	}
	int N;
	long[] A;
	public Sol(){
		N = ri();
		A = rla();
	}

	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(char sep=' '){return Console.ReadLine().Split(sep);}
	static int[] ria(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>int.Parse(e));}
	static long[] rla(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>long.Parse(e));}
	static double[] rda(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>double.Parse(e));}
}