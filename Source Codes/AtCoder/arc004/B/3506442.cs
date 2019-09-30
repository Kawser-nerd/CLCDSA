using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long o=0,m=0;
		for(int i=0;i<n;i++){
			long q=long.Parse(Console.ReadLine());
			o+=q;
			m=Math.Max(m,q);
		}
		Console.WriteLine("{0}",o);
		Console.WriteLine("{0}",o-m>m?0:m-(o-m));
	}
}