using System;
using System.Linq;
class Program{
	static void Main(string[] args){
		int n=int.Parse(Console.ReadLine());
                int[] rn=new int[n];
                for (int i=0;i<n;i++){
                     rn[i]=int.Parse(Console.ReadLine());
                }
                Array.Sort(rn);
		Console.WriteLine(rn[0]);
	}
}