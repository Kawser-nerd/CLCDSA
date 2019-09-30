using System;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		int[][] arr=new int[s+1][];
		arr[1]=new int[] {0,0,0,1<<29};
		for(int i=2;i<=s;i++){
			arr[i]=new int[] {int.Parse(Console.ReadLine()),0,0,1<<29};
		}
		for(int i=s;i>1;i--){
			arr[arr[i][0]][1]=1;
			if(arr[i][1]==0){
				arr[arr[i][0]][2]=Math.Max(arr[arr[i][0]][2],1);
				arr[arr[i][0]][3]=1;
			}
			else{
				arr[arr[i][0]][2]=Math.Max(arr[arr[i][0]][2],arr[i][2]+arr[i][3]+1);
				arr[arr[i][0]][3]=Math.Min(arr[arr[i][0]][3],arr[i][2]+arr[i][3]+1);
			}
		}
		Console.WriteLine("{0}",arr[1][2]+arr[1][3]+1);
	}
}