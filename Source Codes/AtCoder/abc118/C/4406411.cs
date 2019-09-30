using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
	public static void Main()
	{
		var n = int.Parse(Console.ReadLine());
		var split = Console.ReadLine().Split(' ');
		var a = new List<int>();
		for(int i=0;i<n;i++){
			a.Add(int.Parse(split[i]));
		}
		var min = a.Min();
		while(a.Count(x=>x%min!=0) != 0){
			min = a.Select(x=>x%min).Where(x=>x!=0).Min();
		}
		Console.WriteLine(min);
	}
}