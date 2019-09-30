using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		int M = 0;
		var list = new List<int[]>();
			for(var i=1;i<=N;i++){
				for(var j=i+1;j<=N;j++){
					if(i+j!=N+(N+1)%2){
						list.Add(new int[2]{i,j});
					}
				}
			}
		Console.WriteLine(list.Count);
		for(var i=0;i<list.Count;i++){
			Console.WriteLine(list[i][0]+" "+list[i][1]);
		}
	}
}