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
		
		Array.Sort(A);
		Array.Sort(B);
		Array.Sort(C);
		
		long[] btot = new long[N];
		int k = 0;
		for(int j=0;j<N;j++){
			while(k < N){
				if(C[k] <= B[j]){
					k++;
					continue;
				}
				break;
			}
			btot[j] = N - k;
		}
		
		long[] bsum = new long[N+1];
		for(int i=0;i<N;i++){
			bsum[i+1] = btot[i] + bsum[i];
		}
		
		long ans = 0;
		k = 0;
		for(int i=0;i<N;i++){
			while(k < N){
				if(B[k] <= A[i]){
					k++;
					continue;
				}
				break;
			}
			ans += bsum[N] - bsum[k];
		}
		
		Console.WriteLine(ans);
		
		
		
	}
	int N;
	int[] A,B,C;
	public Sol(){
		N = ri();
		A = ria();
		B = ria();
		C = ria();
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