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
		
		int[][] A = new int[N][];
		for(int i=0;i<N;i++){
			A[i] = new int[M];
			for(int j=0;j<M;j++) A[i][j] = (int) (S[i][j] - '0');
		}
		
		var blk = new Acc2();
		blk.Init(A);
		
		int[][] H = new int[N][];
		for(int i=0;i<N;i++){
			H[i] = new int[M];
			for(int j=0;j<M-1;j++){
				if(S[i][j] == '1' && S[i][j+1] == '1') H[i][j] = 1;
			}
		}
		
		var hor = new Acc2();
		hor.Init(H);
		
		int[][] V = new int[N][];
		for(int i=0;i<N;i++){
			V[i] = new int[M];
		}
		for(int i=0;i<N-1;i++){
			for(int j=0;j<M;j++){
				if(S[i][j] == '1' && S[i+1][j] == '1') V[i][j] = 1;
			}
		}
		
		var ver = new Acc2();
		ver.Init(V);
		
		int[] Ans = new int[Q];
		for(int i=0;i<Q;i++){
			int x1 = Query[i][0] - 1;
			int y1 = Query[i][1] - 1;
			int x2 = Query[i][2] - 1;
			int y2 = Query[i][3] - 1;
			int bb = blk.cal(y1, x1, y2+1, x2+1);
			if(bb == 0){
				Ans[i] = 0;
				continue;
			}
			int hh = hor.cal(y1, x1, y2, x2+1);
			int vv = ver.cal(y1, x1, y2+1, x2);
			//Console.WriteLine("bb{0} hh{1} vv{2}",bb,hh,vv);
			Ans[i] = bb - hh - vv;
		}
		Console.WriteLine(String.Join("\n",Ans));
		
	}
	int N,M;
	int Q;
	String[] S;
	int[][] Query;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1]; Q = d[2];
		S = new String[N];
		for(int i=0;i<N;i++) S[i] = rs();
		Query = new int[Q][];
		for(int i=0;i<Q;i++) Query[i] = ria();
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

class Acc2{
	
	int H,W;
	int[][] acc;
	
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

	public int cal(int x1,int y1,int x2,int y2){
		//return num of land [x1,x2)*[y1,y2); left-inclusive / right-noninclusive;
		if(x2<x1||y2<y1)return 0;
		return acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];
	}

}