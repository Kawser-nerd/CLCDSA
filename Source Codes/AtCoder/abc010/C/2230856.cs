using System;
using System.Linq;
public class Testing_SOIDJOIA
{
	public static void Main()
	{	
	double []a=Console.ReadLine().Split().Select(double.Parse).ToArray();
	int n=int.Parse(Console.ReadLine());
	double his=a[4]*a[5];
	bool flag=false;
	for(int i=0;i<n;i++){
		double []s=Console.ReadLine().Split().Select(double.Parse).ToArray();
	if(flag){continue;}
	double k1=Math.Sqrt((s[0]-a[0])*(s[0]-a[0])+(s[1]-a[1])*(s[1]-a[1]));
		double k2=Math.Sqrt((s[0]-a[2])*(s[0]-a[2])+(s[1]-a[3])*(s[1]-a[3]));
	//	Console.WriteLine(k1+" "+k2+" "+his);
		double k=k1+k2;
	if(k<=his){flag=true;}
	}
		Console.WriteLine(flag?"YES":"NO");
	}}