using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int K = int.Parse(str[1]);
		int[][]A = new int[N][];
		for(var i=0;i<N;i++){
			string[] str2 = Console.ReadLine().Split();
			A[i] = new int[2]{int.Parse(str2[0]),int.Parse(str2[1])};
		}
		Array.Sort(A,(x,y)=>y[1].CompareTo(x[1]));
		List<int>[] list = new List<int>[N];
		for(var i=0;i<N;i++){
			list[i] = new List<int>();
		}
		for(var i=0;i<N;i++){
			list[A[i][0]-1].Add(A[i][1]);
		}
		for(var i=0;i<N;i++){
			list[i].Sort((x,y)=>y-x);
		}
		Array.Sort(list,(x,y)=>((y.Count>0 ? y[0] : 0).CompareTo(x.Count>0 ? x[0] : 0)));
		int[]C = new int[N];
		long ans = 0;
		int ct = 0;
		long bct = 0;
		for(var i=0;i<Math.Min(N,K);i++){
			if(list[i].Count == 0){
				break;
			}
			ct++;
			bct++;
			C[i]++;
			ans += list[i][0];
		}
		if(ct<K){
			var list2 = new List<int[]>();
			for(var i=0;i<N;i++){
				for(var j=C[i];j<list[i].Count;j++){
					list2.Add(new int[2]{list[i][j],i});
				}
			}
			list2.Sort((x,y)=>y[0]-x[0]);
			int ct2 = K-ct;
			for(var i=0;i<ct2;i++){
				ct++;
				C[list2[i][1]]++;
				ans += list2[i][0];
			}
		}
		var list3 = new List<int>();
		for(var i=0;i<N;i++){
			if(C[i]==1){
				list3.Add(list[i][0]);
			}
		}
		var list4 = new List<int>();
		for(var i=0;i<N;i++){
			for(var j=C[i];j<list[i].Count;j++){
				list4.Add(list[i][j]);
			}
		}
		list3.Sort();
		list4.Sort((x,y)=>y-x);
		int cta = 0;
		long ansmax = ans+bct*bct;
		while(true){
			if(cta >= list3.Count || cta >= list4.Count){
				break;
			}
			if(list4[cta]+((bct-1)*(bct-1))> list3[cta]+bct*bct){
				bct--;
				ans += list4[cta]-list3[cta];
				ansmax = Math.Max(ans+bct*bct,ansmax);
				cta++;
			} else if(list4[cta] > list3[cta]){
				bct--;
				ans += list4[cta]-list3[cta];
				ansmax = Math.Max(ans+bct*bct,ansmax);
				cta++;
			} else {
				break;
			}
		}
		Console.WriteLine(ansmax);
	}
}