using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		var ht = new Dictionary<int,bool>();
		foreach(int i in q){ht[i>>((int)Math.Log(i&-i,2))]=true;}
		Console.WriteLine(ht.Count);
	}
}