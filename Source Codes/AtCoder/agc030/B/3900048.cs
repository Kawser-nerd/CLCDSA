using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] arr=new long[s[1]+1];
		long[] r=new long[s[1]+1];
		for(int i=1;i<=s[1];i++){
			arr[i]=int.Parse(Console.ReadLine());
			r[i]=arr[i]+r[i-1];
		}
		long ans=Math.Max(arr[1],s[0]-arr[1]);
		for(int i=1;i<s[1];i++){
			int m1=(int)(s[1]+i+1)/2;
			int m2=(int)(s[1]+2-i)/2;
			if((i+s[1])%2==0){
				ans=Math.Max(ans,2*(r[m1-1]-r[i-1])+arr[m1]+s[0]*(s[1]-i)-2*(r[s[1]]-r[m1]));
				ans=Math.Max(ans,2*(r[m2-1])+s[0]*(s[1]+1-i)-arr[m2]-2*(r[s[1]+1-i]-r[m2]));
			}
			else{
				ans=Math.Max(ans,2*(r[m1-1]-r[i-1])+s[0]*(s[1]-i)-arr[m1]-2*(r[s[1]]-r[m1]));
				ans=Math.Max(ans,2*(r[m2-1])+arr[m2]+s[0]*(s[1]+1-i)-2*(r[s[1]+1-i]-r[m2]));
			}
		}
		Console.WriteLine("{0}",ans);
	}
}