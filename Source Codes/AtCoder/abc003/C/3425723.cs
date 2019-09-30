using System;
using System.Linq; //?????
class Program
{
	static void Main(string[] args)
	{
		// ?????
		string r=Console.ReadLine(); //?????????
		string[] a=r.Split(' ');
		int[]i1=new int[a.Length];
		for(int i=0;i<a.Length;i++){
			i1[i]=int.Parse(a[i]);
		}
		r=Console.ReadLine(); //?????
		a=r.Split(' ');
		int[]i2=new int[a.Length];
		for(int i=0;i<a.Length;i++){
			i2[i]=int.Parse(a[i]);
		}
        Array.Sort(i2);
        double output=0;
        int l=i2.Length;
        for(int i=1;i<=i1[1];i++){
        	output+=i2[l-i]/Math.Pow(2,i);
        }
        
		//??
		Console.WriteLine(output);
	}
}