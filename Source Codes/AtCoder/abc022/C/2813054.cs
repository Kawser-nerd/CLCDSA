using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[,] arr=new int[s[0]+1,s[0]+1];
		List<int> li=new List<int>();
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			if(q[0]==1){li.Add(q[1]);}
			arr[q[0],q[1]]=q[2];
			arr[q[1],q[0]]=q[2];
		}
		for(int i=2;i<=s[0];i++){
			for(int j=i;j<=s[0];j++){
				if(arr[i,j]==0&&i!=j){arr[i,j]=1<<29;arr[j,i]=1<<29;}
			}
		}
		for(int i=2;i<=s[0];i++){
			for(int j=2;j<=s[0];j++){
				for(int k=2;k<=s[0];k++){arr[j,k]=Math.Min(arr[j,k],arr[j,i]+arr[i,k]);}
			}
		}
		int ans=1<<29;
		for(int i=0;i<li.Count;i++){
			for(int j=i+1;j<li.Count;j++){ans=Math.Min(ans,arr[li[i],li[j]]+arr[1,li[i]]+arr[1,li[j]]);}
		}

		if(ans==1<<29){ans=-1;}
		Console.WriteLine(ans);
	}
}