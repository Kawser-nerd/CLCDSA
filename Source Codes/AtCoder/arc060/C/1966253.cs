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
		
		int M = 20;
		
		int[][] right = new int[M][];
		for(int i=0;i<M;i++) right[i] = new int[N];
		int t = 0;
		for(int i=0;i<N;i++){
			while(true){
				if(t + 1 < N && X[t + 1] - X[i] <= L){
					t++;
					continue;
				}
				break;
			}
			right[0][i] = t;
		}
		
		for(int i=1;i<M;i++){
			for(int j=0;j<N;j++){
				right[i][j] = right[i-1][right[i-1][j]];
			}
		}
		
		int[][] left = new int[M][];
		for(int i=0;i<M;i++) left[i] = new int[N];
		
		t = N - 1;
		for(int i=N-1;i>=0;i--){
			while(true){
				if(t - 1 >= 0 && X[i] - X[t - 1] <= L){
					t--;
					continue;
				}
				break;
			}
			left[0][i] = t;
		}
		
		for(int i=1;i<M;i++){
			for(int j=0;j<N;j++){
				left[i][j] = left[i-1][left[i-1][j]];
			}
		}
		
		List<int> ans = new List<int>(Q);
		for(int q = 0; q < Q; q++){
			int a = A[q], b = B[q];
			
			if(a < b){
				int cnt = 0;
				int now = a;
				
				for(int i=M-1;i>=0;i--){
					if(right[i][now] < b){
						cnt += 1 << i;
						now = right[i][now];
					}
				}
				
				ans.Add(cnt + 1);
			}
			
			if(a > b){
				int cnt = 0;
				int now = a;
				
				for(int i=M-1;i>=0;i--){
					if(left[i][now] > b){
						cnt += 1 << i;
						now = left[i][now];
					}
				}
				ans.Add(cnt + 1);
			}
			
		}
		Console.WriteLine(String.Join("\n",ans));
	}
	int N;
	long[] X;
	long L;
	int Q;
	int[] A,B;
	public Sol(){
		N = ri();
		X = rla();
		L = rl();
		Q = ri();
		A = new int[Q];
		B = new int[Q];
		for(int i=0;i<Q;i++){
			var d = ria();
			A[i] = d[0] - 1;
			B[i] = d[1] - 1;
		}
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