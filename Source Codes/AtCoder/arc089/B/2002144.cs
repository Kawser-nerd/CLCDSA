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
		
		int H = 2 * K;
		int W = 2 * K;
		int[][][] M = new int[2][][];
		for(int i=0;i<2;i++){
			M[i] = new int[H][];
			for(int j=0;j<H;j++){
				M[i][j] = new int[W];
			}
		}
		
		for(int i=0;i<N;i++){
			M[C[i]][Y[i] % H][X[i] % W]++;
		}
		
		var asum = new Acc[2];
		for(int i=0;i<2;i++){
			asum[i] = new Acc(H,W);
			asum[i].Init(M[i]);
		}
		
		int max = 0;
		for(int t=0;t<2;t++){
			for(int i=0;i<K;i++){
				for(int j=0;j<K;j++){
					
					int cnt0 = 0;
					cnt0 += asum[t].cal(j, i, j + K, i + K);
					cnt0 += asum[t].cal(j + K, i + K, W, H);
					cnt0 += asum[t].cal(0, 0, j, i);
					cnt0 += asum[t].cal(j + K, 0, W, i);
					cnt0 += asum[t].cal(0, i + K, j, H);
					
					int cnt1 = 0;
					cnt1 += asum[t^1].cal(j, i, j + K, i + K);
					cnt1 += asum[t^1].cal(j + K, i + K, W, H);
					cnt1 += asum[t^1].cal(0, 0, j, i);
					cnt1 += asum[t^1].cal(j + K, 0, W, i);
					cnt1 += asum[t^1].cal(0, i + K, j, H);
					
					int tt = asum[t^1].cal(0,0,W,H);
					cnt1 = tt - cnt1;
					
					max = Math.Max(max, cnt1 + cnt0);
				}
			}
		}
		
		Console.WriteLine(max);
		
		
		
		
		
		
	}
	int N,K;
	int[] X,Y,C;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1];
		X = new int[N];
		Y = new int[N];
		C = new int[N];
		for(int i=0;i<N;i++){
			var ss = rsa();
			X[i] = int.Parse(ss[0]);
			Y[i] = int.Parse(ss[1]);
			C[i] = (ss[2][0] == 'B' ? 1 : 0);
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

class Acc{

	public Acc(int h, int w){
		H = h; W = w;
	}
	public void Init(int[][] M){
		H = M.Length;
		W = M[0].Length;
		acc = new int[H+1][];
		for(int i=0;i<=H;i++){
			acc[i] = new int[W+1];
			if(i == 0) continue;
			for(int j=1;j<=W;j++){
				acc[i][j] = M[i-1][j-1];
			}
		}
		
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				acc[i][j] += acc[i][j-1];
			}
		}
		for(int j=1;j<=W;j++){
			for(int i=1;i<=H;i++){
				acc[i][j] += acc[i-1][j];
			}
		}
	}
	
	int H,W;
	int[][] acc;
	public int cal(int x1,int y1,int x2,int y2){
		//return num of land [x1,x2)*[y1,y2); left-inclusive / right-noninclusive;
		if(x2<x1||y2<y1)return 0;
		return acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];
	}
	





}