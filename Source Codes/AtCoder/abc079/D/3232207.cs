using System;
class Program{
	static int[][] a=new int[10][];
	static int[] h=new int[10];
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int ans=0;
		for(int i=0;i<10;i++){
			a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			h[i]=a[i][1];
		}
		for(int i=0;i<10;i++){
			if(i!=1){fu(i,h[i]);}
		}
		for(int i=0;i<s[0];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			for(int j=0;j<s[1];j++){
				ans+=q[j]==-1?0:h[q[j]];
			}
		}
		Console.WriteLine("{0}",ans);
	}
	static void fu(int n,int c){
		for(int i=0;i<10;i++){
			if(a[i][n]+c<h[i]){
				h[i]=a[i][n]+c;
				fu(i,h[i]);
			}
		}
	}
}