using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[][] arr=new long[s[0]][];
		int[,] h=new int[s[1]*2+1,s[1]*2+1];
		int ans=0;
		for(int i=0;i<s[0];i++){
			object[] q=Console.ReadLine().Split(' ');
			arr[i]=new long[]{Convert.ToInt64(q[0]),Convert.ToInt64(q[1]),Convert.ToChar(q[2])};
			if(arr[i][2]==87){arr[i][1]+=s[1];}
			arr[i][0]%=s[1]*2;
			arr[i][1]%=s[1]*2;
			h[arr[i][0]+1,arr[i][1]+1]++;
		}
		for(int i=1;i<=s[1]*2;i++){
			for(int j=1;j<=s[1]*2;j++){h[i,j]+=h[i,j-1];}
		}
		for(int i=1;i<=s[1]*2;i++){
			for(int j=1;j<=s[1]*2;j++){h[j,i]+=h[j-1,i];}
		}
		for(int i=1;i<=s[1];i++){
			for(int j=1;j<=s[1]*2;j++){
				int a=h[i,j]-h[i,Math.Max(j-s[1],0)];
				a+=h[i,s[1]*2]-h[i,Math.Min(j+s[1],s[1]*2)];
				a+=h[i+s[1],Math.Min(j+s[1],s[1]*2)]-h[i,Math.Min(j+s[1],s[1]*2)]-h[i+s[1],j]+h[i,j];
				if(j>s[1]){a+=h[i+s[1],j-s[1]]-h[i,j-s[1]];}
				a+=h[s[1]*2,j]-h[i+s[1],j]-h[s[1]*2,Math.Max(j-s[1],0)]+h[i+s[1],Math.Max(j-s[1],0)];
				if(j<s[1]&&i<s[1]){a+=h[s[1]*2,s[1]*2]-h[s[1]*2,j+s[1]]-h[i+s[1],s[1]*2]+h[i+s[1],j+s[1]];}
				ans=Math.Max(ans,a);
			}
		}
		Console.WriteLine("{0}",ans);
	}
}