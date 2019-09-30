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
		
		Queue<int>[] Q = new Queue<int>[N];
		for(int i=0;i<N;i++){
			Q[i] = new Queue<int>();
			for(int j=0;j<M;j++) Q[i].Enqueue(A[i][j]);
		}
		int min = N;
		HashSet<int> H = new HashSet<int>();
		for(int i=0;i<M;i++) H.Add(i);
		
		while(H.Count>0){
		//for(int t=0;t<M;t++){
			bool chk = true;
			for(int i=0;i<N;i++){
				while(Q[i].Count>0 && !H.Contains(Q[i].Peek())) Q[i].Dequeue();
				if(Q[i].Count == 0) chk = false;
			}
			if(!chk) break;
			
			int[] cnt = new int[M];
			for(int i=0;i<N;i++){
				var n = Q[i].Peek();
				cnt[n]++;
			}
			int mx = 0;
			for(int i=0;i<M;i++) mx = Math.Max(cnt[i],mx);
			min = Math.Min(min,mx);
			
			HashSet<int> hs = new HashSet<int>();
			for(int j=0;j<M;j++) if(cnt[j] == mx) hs.Add(j);
			
			for(int i=0;i<N;i++){
				if(hs.Contains(Q[i].Peek())) Q[i].Dequeue();
			}
			for(int j=0;j<M;j++){
				if(cnt[j] == mx)H.Remove(j);
			}
			
			chk = true;
			for(int i=0;i<N;i++){
				while(Q[i].Count>0 && !H.Contains(Q[i].Peek())) Q[i].Dequeue();
				if(Q[i].Count == 0) chk = false;
			}
			if(!chk) break;
			//Console.WriteLine(String.Join(" ",H.ToArray()));
		}
		
		Console.WriteLine(min);
		
	}
	int N,M;
	int[][] A;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		A = new int[N][];
		for(int i=0;i<N;i++){
			A[i] = ria();
			for(int j=0;j<M;j++) A[i][j]--;
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