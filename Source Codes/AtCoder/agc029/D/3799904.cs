using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int H = int.Parse(str[0]);
		int W = int.Parse(str[1]);
		int N = int.Parse(str[2]);
		int[]Hm = new int[H];
		int[]Wm = new int[W];
		List<int>[]Wlist = new List<int>[W];
		Dictionary<int,int>[]WDic = new Dictionary<int,int>[W];
		for(var i=0;i<W;i++){
			Wlist[i] = new List<int>();
			WDic[i] = new Dictionary<int,int>();
		}
		for(var i=0;i<N;i++){
			string[] str2 = Console.ReadLine().Split();
			int h1 = int.Parse(str2[0]);
			int w1 = int.Parse(str2[1]);
			Wlist[w1-1].Add(h1-1);
			WDic[w1-1][h1-1] = 1;
		}
		int ha = 0;
		int wa = 0;
		Hm[0] = 0;
		Wm[0] = 0;
		while(true){
			ha += 1;
			if(wa==W){
				break;
			}
			if(ha==H){
				for(var i=wa+1;i<W;i++){
					Wm[i] = H;
				}
				break;
			}
			if(wa+1 < W && !WDic[wa+1].ContainsKey(ha)){
				wa += 1;
				Wm[wa] = ha;
			}
			Hm[ha] = wa;
		}
		//for(var i=0;i<W;i++){
		//	Console.WriteLine(Wm[i]);
		//}
		//for(var i=0;i<W;i++){
		//	for(var j=0;j<Wlist[i].Count;j++){
		//		Console.Write(Wlist[i][j]+" ");
		//	}
		//	Console.WriteLine();
		//}
		int ans = H;
		for(var i=0;i<W;i++){
			Wlist[i].Sort();
			int min = 0;
			int max = Wlist[i].Count;
			while(min<max){
				int na = (min+max)/2;
				if(Wlist[i][na] < Wm[i]){
					min = na + 1;
				} else {
					max = na;
				}
			}
			if(min < Wlist[i].Count){
				ans = Math.Min(ans,Wlist[i][min]);
			}
		}
		Console.WriteLine(ans);
	}
}