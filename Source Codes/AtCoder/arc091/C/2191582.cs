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
		
		// 
		if(InRange(B, (N + (A - 1))/ A, N - A + 1)){
			int cmp = (N + (A - 1))/ A;
			List<int>[] L = new List<int>[cmp];
			for(int i=0;i<cmp;i++) L[i] = new List<int>();
			for(int i=0;i<N;i++){
				L[i / A].Add(i + 1);
			}
			
			Array.Reverse(L);
			int rem = B - cmp;
			int now = 0;
			while(rem > 0){
				if(rem >= L[now].Count - 1){
					L[now].Reverse();
					rem -= L[now].Count - 1;
				} else {
					L[now].Reverse(0,rem+1);
					rem = 0;
				}
				now++;
			}
			List<int> ans = new List<int>();
			for(int i=0;i<cmp;i++) foreach(var n in L[i]) ans.Add(n);
			Console.WriteLine(String.Join(" ",ans));
			return;
		}
		if(InRange(A, (N + (B - 1))/ B, N - B + 1)){
			int cmp = (N + (B - 1))/ B;
			List<int>[] L = new List<int>[cmp];
			for(int i=0;i<cmp;i++) L[i] = new List<int>();
			for(int i=0;i<N;i++){
				L[i / B].Add(i + 1);
			}
			
			for(int i=0;i<cmp;i++){
				L[i].Reverse();
			}
			
			int rem = A - cmp;
			int now = 0;
			while(rem > 0){
				if(rem >= L[now].Count - 1){
					L[now].Reverse();
					rem -= L[now].Count - 1;
				} else {
					L[now].Reverse(0,rem+1);
					rem = 0;
				}
				now++;
			}
			List<int> ans = new List<int>();
			for(int i=0;i<cmp;i++) foreach(var n in L[i]) ans.Add(n);
			Console.WriteLine(String.Join(" ",ans));
		
			return;
		}
		Console.WriteLine(-1);
	}
	
	bool InRange(int t, int l, int r){
		return l <= t && t <= r;
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