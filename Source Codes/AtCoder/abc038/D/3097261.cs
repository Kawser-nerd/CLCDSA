using System;
class Program{
	static int[] dp=new int[231072];
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[][] arr=new int[n][];
		int t=131071;
		for(int i=0;i<n;i++){arr[i]=Array.ConvertAll((Console.ReadLine()).Split(),int.Parse);}
		Array.Sort(arr,ca);
		for(int i=0;i<n;i++){
			dp[arr[i][0]+t]=Math.Max(dp[arr[i][0]+t]-1,fu(0,arr[i][0]-1,0,0,131071))+1;
			for(int j=arr[i][0]+t;j>0;){
				dp[(j-1)/2]=Math.Max(dp[j],dp[(j-1)/2]);
				j=(j-1)/2;
			}
		}
		Console.WriteLine("{0}",dp[0]);
	}
	static int fu(int a,int b,int k,int l,int r){
		if(r<=a||b<=l){return 0;}
		if(a<=l&&r<=b){return dp[k];}
		else{return Math.Max(fu(a,b,k*2+1,l,(l+r)/2),fu(a,b,k*2+2,(l+r)/2,r));}
	}
	static int ca(int[] a,int[] b){
		if(a[1]>b[1]){return 1;}
		else if(a[1]<b[1]){return -1;}
		else if(a[0]<b[0]){return 1;}
		else if(a[0]>b[0]){return -1;}
		else{return 0;}
	}
}