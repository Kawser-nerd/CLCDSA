using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		bool[] b=new bool[s[0]+1];
		int[] h=new int[s[0]+1];
		int ans=1;
		b[1]=true;
		for(int i=1;i<=s[0];i++){h[i]=1;}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			h[q[0]]--;
			h[q[1]]++;
			if(b[q[0]]&&(!b[q[1]])){b[q[1]]=true;ans++;}
			if(h[q[0]]==0&&b[q[0]]){b[q[0]]=false;ans--;}
		}
		Console.WriteLine("{0}",ans);
	}
}