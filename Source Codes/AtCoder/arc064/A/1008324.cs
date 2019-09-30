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
		for(int i=0;i<N-1;i++){
			if(A[i]+A[i+1] > X){
				long rem = A[i+1]+A[i]-X;
				ans += rem;
				if(A[i+1]>rem){
					A[i+1] -= rem;
				}else{
					A[i] -= (rem - A[i+1]);
					A[i+1] = 0;
				}
			}
		}
		Console.WriteLine(ans);
		
	}
	int N,X;
	long[] A;
	public Sol(){
		var  d = ria();
		N = d[0];
		X = d[1];
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