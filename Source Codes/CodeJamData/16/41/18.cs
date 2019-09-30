using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		
		var d =ria();
		int N = d[0];
		int[] A = {d[1],d[2],d[3]};
		
		int[][] dp = new int[N+1][];
		for(int i=0;i<=N;i++){
			dp[i] = new int[3];
		}
		
		dp[0][0] = 1;
		for(int i=1;i<=N;i++){
			dp[i][0] = dp[i-1][0] + dp[i-1][2];
			dp[i][1] = dp[i-1][1] + dp[i-1][0];
			dp[i][2] = dp[i-1][2] + dp[i-1][1];
		}
		
		var AA = (int[])A.Clone();
		var JJ = (int[])dp[N].Clone();
		Array.Sort(AA);
		Array.Sort(JJ);
		for(int i=0;i<3;i++){
			if(AA[i] != JJ[i]){
				Console.WriteLine("IMPOSSIBLE");
				return;
			}
		}
		
		String Hand ="RPS";
		List<int> cand = new List<int>();
		for(int i=0;i<3;i++){
			if(A[i] == dp[N][0]){
				cand.Add(i);
			}
		}
		
		char[] lose = new char[255];
		lose['R']='S';
		lose['S']='P';
		lose['P']='R';
		
		String Match = "";
		
		foreach(var n in cand){
			String ans = Hand[n].ToString();
			for(int t=0;t<N;t++){
				List<char> L = new List<char>();
				for(int i=0;i<ans.Length;i++){
					L.Add(ans[i]);
					L.Add(lose[ans[i]]);
				}
				ans = new String(L.ToArray());
			}
//Console.WriteLine("n:{0},ans:{1}",);			
			if( ans.Count(c => c == 'R') == A[0] && ans.Count(c => c == 'P') == A[1] && ans.Count(c => c == 'S') == A[2] ){
				Match = ans;
			}
		}
		
		int len = Match.Length;
		for(int t=0;t<N;t++){
			int sz = (1<<t);
			String nxt = "";
			for(int i=0;i<len;i+=sz*2){
				String l = Match.Substring(i,sz);
				String r = Match.Substring(i+sz,sz);
				if(l.CompareTo(r)<0){
					nxt += l;
					nxt += r;
				}else{
					nxt += r;
					nxt += l;
				}
			}
			
			Match = nxt;
		}
		
		Console.WriteLine(Match);
		
	}

	public Sol(int T){
		Console.Write("Case #{0}: ",T);
	}




	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}

}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}