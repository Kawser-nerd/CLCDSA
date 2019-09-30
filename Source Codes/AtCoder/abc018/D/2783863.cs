using System;
class Program{
	static int[] s;
	static int[] t;
	static int[][] arr;
	static int ans,b;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		arr=new int[s[0]+1][];
		for (int i=0;i<=s[0];i++){
			arr[i]=new int[s[1]+1];
			arr[i][0]=i;
		}
		t=new int[s[3]];

		for (int i=0;i<s[4];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			arr[q[0]][q[1]]=q[2];
		}
		fu(1,0);
		Console.WriteLine(ans);
	}
	static void fu(int n,int m){
		if(m==s[3]){
			Array.Sort(arr,ca);
			b=0;
			for (int i=0;i<s[2];i++){
				foreach(int j in t){b+=arr[i][j];}
			}
			ans=Math.Max(ans,b);
		}
		else{
			int v=s[1]-s[3]+1+m;
			for (;n<=v;n++){
				t[m]=n;
				fu(n+1,m+1);
			}
		}
	}
	static int ca(int[] a,int[] b){
		int aa=0,bb=0;
		foreach(int i in t){aa+=a[i];bb+=b[i];}
		if(aa<bb){return 1;}
		else if(aa>bb){return -1;}
		else{return 0;}
	}
}