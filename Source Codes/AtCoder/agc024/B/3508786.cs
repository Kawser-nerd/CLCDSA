using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] h=new int[n+1];
		for(int i=0;i<n;i++){
			int a=int.Parse(Console.ReadLine());
			h[a]=h[a-1]+1;
		}
		Console.WriteLine("{0}",n-h.Max());
	}
}