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
		
		List<int>[] E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		
		for(int i=0;i<N-1;i++){
			E[A[i]].Add(i+1);
		}
		
		int[] depth = new int[N];
		depth[0] = 0;
		Queue<int> Q = new Queue<int>();
		Q.Enqueue(0);
		while(Q.Count>0){
			var now = Q.Dequeue();
			foreach(var nxt in E[now]){
				depth[nxt] = depth[now] + 1;
				Q.Enqueue(nxt);
			}
		}
		
		int[] order = Enumerable.Range(0,N).ToArray();
		Array.Sort(depth,order);
		Array.Reverse(order);
		
		int[] dp = new int[N];
		for(int j=0;j<N;j++){
			int now = order[j];
			
			List<int> L = new List<int>();
			foreach(var nxt in E[now]){
				L.Add(dp[nxt]);
			}
			if(L.Count == 0){
				dp[now] = 0;
				continue;
			}
			L.Sort();
			L.Reverse();
//Console.WriteLine("now:{0}" + now + " L:" + String.Join(" ",L));
			for(int i=0;i<L.Count;i++) L[i] += i+1;
			int max = 0;
			for(int i=0;i<L.Count;i++){
				max = Math.Max(L[i],max);
			}
			dp[now] = max;
		}
//Console.WriteLine(String.Join(" ",dp));
		Console.WriteLine(dp[0]);
		
		
		
	}
	
	
	
	
	
	
	int N;
	int[] A;
	public Sol(){
		N = ri();
		A = new int[N-1];
		for(int i=0;i<N-1;i++) A[i] = ri() - 1;
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