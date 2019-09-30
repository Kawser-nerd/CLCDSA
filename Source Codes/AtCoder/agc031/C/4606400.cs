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
		
		int[] bcnt = new int[1 << 20];
		for(int i=0;i<(1 << 20);i++){
			for(int j=0;j<20;j++) if((i >> j) % 2 == 1) bcnt[i]++;
		}
		
		int xor = A ^ B;
		if(bcnt[xor] % 2 != 1){
			Console.WriteLine("NO");
			return;
		}
		if(N == 1){
			Console.WriteLine("YES");
			Console.WriteLine("{0} {1}",A,B);
			return;
		}
		
		int[] g0 = CreateCode(N, bcnt[xor]);
		List<int> one = new List<int>();
		List<int> zero = new List<int>();
		for(int i=0;i<N;i++){
			if((xor >> i) % 2 == 0) zero.Add(i);
			if((xor >> i) % 2 == 1) one.Add(i);
		}
		int[] map = new int[N];
		for(int i=0;i<one.Count;i++){
			map[one[i]] = N - 1 - i;
		}
		for(int i=0;i<zero.Count;i++){
			map[zero[i]] = N - 1 - (i + one.Count);
		}
		
		int[] g = new int[1<<N];
		for(int i=0;i<1<<N;i++){
			for(int j=0;j<N;j++){
				int v = (g0[i] >> map[j]) % 2;
				g[i] |= (v << j);
			}
		}
		
		int[] ans = new int[1 << N];
		for(int i=0;i<(1<<N);i++){
			ans[i] = A ^ g[i];
		}
		
		Console.WriteLine("YES");
		Console.WriteLine(String.Join(" ",ans));
		
		
	}
	
	int[] CreateCode(int n, int b){
		int[] a = new int[]{0,1,3,2};
		int[] ax = new int[]{2,3,1,0};
		int[] aa = new int[]{2,0,1,3};
		int[] a2 = new int[]{0,1};
		int[] a2x = new int[]{1,0};
		int[][] dp = new int[n + 1][];
		for(int i=0;i<=n;i++) dp[i] = new int[1 << i];
		
		dp[1][0] = 0;
		dp[1][1] = 1;
		int bb = b / 2;
		int now = 1;
		for(int k=0;k<bb;k++){
			int nt = now + 2;
			for(int j=0;j<dp[now].Length;j++){
				if(j % 2 == 0){
					for(int t=0;t<4;t++){
						dp[nt][j * 4 + t] = (dp[now][j] << 2) + a[t];
					}
				} else if(j == dp[now].Length - 1){
					for(int t=0;t<4;t++){
						dp[nt][j * 4 + t] = (dp[now][j] << 2) + aa[t];
					}
				} else {
					for(int t=0;t<4;t++){
						dp[nt][j * 4 + t] = (dp[now][j] << 2) + ax[t];
					}
				}
			}
			now = nt;
		}
		while(now != n){
			int nt = now + 1;
			for(int j=0;j<dp[now].Length;j++){
				if(j % 2 == 0){
					for(int t=0;t<2;t++){
						dp[nt][j * 2 + t] = (dp[now][j] << 1) + a2[t];
					}
				}else {
					for(int t=0;t<2;t++){
						dp[nt][j * 2 + t] = (dp[now][j] << 1) + a2x[t];
					}
				}
			}
			now = nt;
		}
		
		return dp[n];
	}
	int N,A,B;
	public Sol(){
		var d = ria();
		N = d[0]; A = d[1]; B = d[2];
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