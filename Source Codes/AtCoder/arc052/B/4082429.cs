using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] a=new int[s[0]][];
		double[] ans=new double[s[1]];
		for(int i=0;i<s[0];i++){a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			for(int j=0;j<s[0];j++){
				int e1=Math.Max(q[0],a[j][0]);
				int e2=Math.Min(q[1],a[j][0]+a[j][2]);
				if(e1<e2){
					double u=a[j][2]-(e1-a[j][0]);
					double v=Math.Sqrt(a[j][1]*a[j][1]+a[j][2]*a[j][2])/a[j][2]*u;
					ans[i]+=(v*v-u*u)*Math.PI*u/3;
					u=a[j][2]-(e2-a[j][0]);
					v=Math.Sqrt(a[j][1]*a[j][1]+a[j][2]*a[j][2])/a[j][2]*u;
					ans[i]-=(v*v-u*u)*Math.PI*u/3;
				}
			}
		}
		Console.WriteLine(String.Join("\n",ans));
	}
}