using System;
class Program{
	static int[] s;
	static int b,ans=0;
	static int[] h;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		h=new int[s[0]+1];
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			h[q[0]]|=1<<(q[1]-1);
			h[q[1]]|=1<<(q[0]-1);
		}
		fu(1);
		Console.WriteLine("{0}",ans);
	}
	static void fu(int n){
		b|=1<<(n-1);
		if(b==(1<<s[0])-1){ans++;}
		else{
			for(int i=0;i<s[0];i++){
				if(((h[n]&(1<<i))!=0)&&((b&(1<<i))==0)){fu(i+1);}
			}
		}
		b-=1<<(n-1);
	}
}