using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int M = int.Parse(str[1]);
		string s = Console.ReadLine();
		int[] B = new int[N];
		HashSet<int>[] D = new HashSet<int>[N];
		var E = new HashSet<int>();
		for(var i=0;i<N;i++){
			D[i] = new HashSet<int>();
			E.Add(i);
			if(s.Substring(i,1) == "B"){
				B[i] = 1;
			}
		}
		int[,] A = new int[M,2];
		int[,] C = new int[N,2];
		for(var i=0;i<M;i++){
			string[] str2 = Console.ReadLine().Split();
			A[i,0] = int.Parse(str2[0]);
			A[i,1] = int.Parse(str2[1]);
			if(!D[A[i,0]-1].Contains(A[i,1]-1)){
				D[A[i,0]-1].Add(A[i,1]-1);
				if(B[A[i,1]-1] == 1){
					C[A[i,0]-1,1] += 1;
				} else {
					C[A[i,0]-1,0] += 1;
				}
			}
			if(!D[A[i,1]-1].Contains(A[i,0]-1)){
				D[A[i,1]-1].Add(A[i,0]-1);
				if(B[A[i,0]-1] == 1){
					C[A[i,1]-1,1] += 1;
				} else {
					C[A[i,1]-1,0] += 1;
				}
			}
		}
		int ct = N;
		string ans = "No";
		var F = new HashSet<int>();
		foreach(var i in E){
			if(C[i,0]==0 || C[i,1]==0){
				F.Add(i);
			}
		}
		while(ct>0){
			int ct2 = 0;
			var d1 = new HashSet<int>();
			var G = new HashSet<int>();
			foreach(var i in F){
				var d2 = new HashSet<int>();
				foreach(var j in D[i]){
					d2.Add(j);
				}
				foreach(var j in d2){
					D[j].Remove(i);
					C[j,B[i]] -= 1;
					if(C[j,B[i]]==0 && C[j,(B[i]+1)%2]>=1){
						G.Add(j);
						ct2 += 1;
					}
				}
				d1.Add(i);
			}
			foreach(var i in d1){
				F.Remove(i);
				ct -= 1;
				ct2 += 1;
			}
			if(ct2 == 0){
				ans = "Yes";
				break;
			}
			foreach(var i in G){
				F.Add(i);
			}
		}
		Console.WriteLine(ans);
	}
}