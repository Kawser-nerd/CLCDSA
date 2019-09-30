using System;
class Program{
	static int[] s,f=new int[3];
	static bool[] b;
	static long ans=long.MaxValue;
	static long[,] h;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		h=new long[3,s[1]+1];
		long[][] arr=new long[s[1]+1][];
		for(int i=1;i<=s[1];i++){
			arr[i]=Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);
		}
		for(int i=0;i<s[0];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			for(int j=0;j<s[0];j++){
				for(int k=1;k<=s[1];k++){
					h[(i+j)%3,k]+=arr[q[j]][k];
				}
			}
		}
		b=new bool[s[1]];
		fu1(0);
		Console.WriteLine("{0}",ans);
	}
	static void fu1(int a){
		for(int i=0;i<s[1];i++){
			if(!b[i]){
				f[a]=i+1;
				if(a==2){
					long o=h[0,f[0]]+h[1,f[1]]+h[2,f[2]];
					ans=Math.Min(ans,o);
				}
				else{
					b[i]=true;
					fu1(a+1);
					b[i]=false;
				}
			}
		}
	}
}