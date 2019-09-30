using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] arr=new int[s[1]][];
		List<int[]> li=new List<int[]>();
		int[] ans=new int[s[2]];
		for(int i=0;i<s[1];i++){arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		for(int i=0;i<s[2];i++){
			li.Add(Array.ConvertAll((Console.ReadLine()+" "+i+" 0").Split(),int.Parse));
			if(li[i][0]<li[i][1]){li[i][3]=1;}
		}
		
		for(int i=0;i<s[1];i++){
			for(int j=0;j<li.Count;j++){
				if(arr[i][0]<=li[j][0]&&arr[i][1]>=li[j][0]){
					if(arr[i][0]<=li[j][1]&&arr[i][1]>=li[j][1]){
						ans[li[j][2]]=i+1;
						li.RemoveAt(j);
						j--;
					}
					else{li[j][0]=arr[i][li[j][3]];}
				}
			}
		}

		for(int i=0;i<s[2];i++){Console.WriteLine(ans[i]);}
	}
}