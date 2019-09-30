using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] a=new int[s[0]][];
		for(int i=0;i<s[0];i++){a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		Array.Sort(a,(u,v)=>v[1]-u[1]);
		int[] h=new int[s[0]+1];
		long q=0,t=0,ans=0;
		for(int i=0,j=s[1]-1;i<s[0];i++){
			if(i<s[1]){
				if(h[a[i][0]]==0){t++;}
				h[a[i][0]]++;
				q+=a[i][1];
			}
			else if(h[a[i][0]]==0){
				while(j>0&&h[a[j][0]]<=1){j--;}
				if(j==0){break;}
				h[a[j][0]]--;
				q-=a[j][1];
				t++;j--;
				h[a[i][0]]++;
				q+=a[i][1];
			}
			ans=Math.Max(ans,t*t+q);
		}
		Console.WriteLine("{0}",ans);
	}
}