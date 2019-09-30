using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		double ans=s[0]*q[0];
		for(int i=0;i<=s[0];i++){
			double a=Math.Max(((s[0]-i)*q[4]-s[1]-q[1]*i)/(q[3]+q[4])+1,0);
			if(s[1]+i*q[1]-(s[0]-i)*q[4]>0){a=0;}
			ans=Math.Min(ans,q[0]*i+q[2]*a);
		}
		Console.WriteLine("{0}",ans);
	}
}