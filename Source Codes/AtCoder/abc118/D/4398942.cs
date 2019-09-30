using System;
using System.Collections.Generic;
using System.Linq;
 
public class Program
{
	public static void Main()
	{
		var rule = new int[]{2,5,5,4,5,6,3,7,6};
		var split = Console.ReadLine().Split().Select(int.Parse).ToList();
		var n = split[0];
		var m = split[1];
		split = Console.ReadLine().Split().Select(int.Parse).ToList();
		Check(split);
		var rule2 = new Dictionary<int,int>();
		foreach(var v in split){
			rule2.Add(rule[v-1],v);
		}
		var dp_dic = new Dictionary<int,int>();
		dp_dic.Add(0,0);
		foreach(var loop in Enumerable.Range(1,n)){
			foreach(var d in rule2.OrderByDescending(x=>x.Value)){
				if(dp_dic.Keys.Contains(loop-d.Key)){
					if(dp_dic[loop-d.Key]==int.MinValue)continue;
					if(dp_dic.Keys.Contains(loop)){
						if(dp_dic[loop]<dp_dic[loop-d.Key]+1){
							dp_dic[loop] = dp_dic[loop-d.Key]+1;
						}
						continue;
					}
					dp_dic.Add(loop,dp_dic[loop-d.Key]+1);
				}
			}
			if(!dp_dic.Keys.Contains(loop)){
				dp_dic.Add(loop,int.MinValue);
			}
		}
		while(n>0){
			foreach(var d in rule2.OrderByDescending(x=>x.Value)){
				if(n-d.Key<0)continue;
				if(dp_dic[n-d.Key]==dp_dic[n]-1){
					Console.Write(d.Value);
					n-=d.Key;
					break;
				}
			}
		}
		Console.WriteLine();
	}
	public static void Check(List<int> list){
		if(list.Contains(2)&&list.Contains(3)){
			list.Remove(2);
		}
		if(list.Contains(3)&&list.Contains(5)){
			list.Remove(3);
		}
		if(list.Contains(2)&&list.Contains(5)){
			list.Remove(2);
		}
		if(list.Contains(6)&&list.Contains(9)){
			list.Remove(6);
		}
	}
}