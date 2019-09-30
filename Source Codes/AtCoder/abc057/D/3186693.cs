using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		Array.Sort(a,ca);
		long d=0;
		int m=0,k=0;
		for(int i=0;i<s[0];i++){
			if(i<s[1]){d+=a[i];}
			if(a[i]>a[s[1]-1]){m++;}
			else if(a[i]==a[s[1]-1]){k++;}
		}

		long[,] cb=new long[k+1,k+1];
		for(var i=0;i<=k;i++){
			for(var j=0;j<=i;j++){
				if(j==0||j==i){cb[i,j]=1;}
				else{cb[i,j]=(cb[i-1,j]+cb[i-1,j-1]);}
			}
		}
		
		Console.WriteLine("{0}",1.0*d/s[1]);
		if(m==0){
			long ans=0;
			for(int i=s[1]-m;i<=k&&i<=s[2];i++){ans+=cb[k,i];}
			Console.WriteLine("{0}",ans);
		}
		else{Console.WriteLine("{0}",cb[k,s[1]-m]);}
	}
	static int ca(long a,long b){
		if(a<b){return 1;}
		else if(a>b){return -1;}
		else{return 0;}
	}
}