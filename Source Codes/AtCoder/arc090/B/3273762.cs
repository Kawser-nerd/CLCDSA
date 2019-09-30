using System;
using System.Collections.Generic;
class Program{
	static long[] h;
	static List<int[]>[] li;
	static string ans="Yes";
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		h=new long[s[0]+1];
		li=new List<int[]>[s[0]+1];
		for(int i=1;i<=s[0];i++){
			h[i]=long.MinValue;
			li[i]=new List<int[]>();
		}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			li[q[0]].Add(new int[]{q[1],q[2]});
			li[q[1]].Add(new int[]{q[0],-q[2]});
		}
		for(int i=1;i<=s[0]&&ans=="Yes";i++){
			if(h[i]==long.MinValue){
				h[i]=0;
				fu(i);
			}
		}
		Console.WriteLine("{0}",ans);
	}
	static void fu(int a){
		for(int i=0;i<li[a].Count&&ans=="Yes";i++){
			if(h[li[a][i][0]]==long.MinValue){
				h[li[a][i][0]]=h[a]+li[a][i][1];
				fu(li[a][i][0]);
			}
			else if(h[li[a][i][0]]!=h[a]+li[a][i][1]){
				ans="No";
				break;
			}
		}
	}
}