using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[][] arr=new long[s[0]][];
		bool[] h=new bool[s[0]];
		for(int i=0;i<s[0];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		}
		Array.Sort(arr,ca);
		long ans=0,t=0,b=0,c=0;
		while(b!=s[0]){
			ans++;
			t=0;
			for(int i=0;i<s[0];i++){
				if(!h[i]&&arr[i][0]>=t+(arr[i][2]==c?0:1)){
					h[i]=true;
					t=arr[i][1];
					b++;
					c=arr[i][2];
				}
			}
		}
		Console.WriteLine("{0}",ans);
	}
	static int ca(long[] a,long[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else{return 0;}
	}
}