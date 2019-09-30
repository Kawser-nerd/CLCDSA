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
		long sum = 0;
		for(int i=0;i<N;i++) sum += A[i];
		
		long inc = (long)N * (long) (N+1) / 2;
		if(sum % inc != 0){
			Console.WriteLine("NO");
			return;
		}
		
		long tot = sum / inc;
		
		long[] B = new long[N];
		for(int i=0;i<N;i++){
			long diff = A[i] - A[(i-1+N)%N];
			if((tot - diff) % N != 0){
				Console.WriteLine("NO");
				return;
			}
			B[i] = (tot - diff)/N;
			if(B[i] < 0){
				Console.WriteLine("NO");
				return;
			}
		}
		
		long cnt = 0;
		for(int i=0;i<N;i++) cnt += B[i];
		if(cnt != tot){
			Console.WriteLine("NO");
			return;
		}
		
		//Console.WriteLine(String.Join(" ",B));
		
		long a = 0;
		for(int i=0;i<N;i++){
			a += B[i] * (N-i);
		}
		
		//Console.WriteLine(a);
		
		
		Console.WriteLine(a == A[N-1] ? "YES": "NO");
		
		
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