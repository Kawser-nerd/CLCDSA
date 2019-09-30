using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		string s=Console.ReadLine();
		int[] a=new int[4];
		for(int i=0;i<n;i++){a[s[i]-'0'-1]++;}
		Array.Sort(a);
		Console.WriteLine("{0} {1}",a[3],a[0]);
	}
}