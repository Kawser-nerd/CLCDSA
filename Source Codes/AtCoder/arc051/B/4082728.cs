using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		long n=long.Parse(Console.ReadLine());
		int[] a=new int[41];
		a[0]=1;
		a[1]=2;
		for(int i=2;i<=n;i++){a[i]=a[i-1]+a[i-2];}
		Console.WriteLine("{0} {1}",a[n],a[n-1]);
	}
}