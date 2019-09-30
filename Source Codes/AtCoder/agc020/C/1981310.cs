using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	
	const int MB = 64;
	public void Solve(){
		
		int sum = A.Sum();
		Array.Sort(A);
		
		int NN = (sum + 1  + MB - 1) / MB;
		ulong[] dp = new ulong[NN + 1];
		dp[0] = 1;
		for(int i=0;i<N;i++){
			ulong[] ndp = new ulong[NN + 1];
			int nj = A[i] / MB;
			int nb = A[i] % MB;
			for(int j=0;j + nj + 1 <= NN;j++){
				ndp[j] |= dp[j];
				ndp[j + nj] |= dp[j] << nb;
				if(nb > 0) ndp[j + nj + 1] |= dp[j] >> (MB - nb);
			}
			dp = ndp;
//Console.WriteLine(String.Join(" ",dp.Select(v => String.Format("{0:X}",v))));
		}
		int trgt = sum %2 == 0 ? sum / 2: (sum / 2 + 1);
		for(int k = trgt ;k <= sum; k++){
			int ii = k / MB;
			int jj = k % MB;
			if(((dp[ii] >> jj) & 1 ) == 1){
				Console.WriteLine(k);
				return;
			}
		}
		
		
	}
	int N;
	int[] A;

	public Sol(){
		N = ri();
		A = ria();
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