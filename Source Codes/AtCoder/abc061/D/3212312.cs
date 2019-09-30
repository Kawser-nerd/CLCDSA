using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] h=new long[s[0]+1];
		for(int i=1;i<=s[0];i++){h[i]=long.MinValue;}
		h[1]=0;
		long[][] arr=new long[s[1]][];
		for(int i=0;i<s[1];i++){arr[i]=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}

		long l=0;
		bool b=false;
		while(l<=s[0]+1){
			l++;
			for(int i=0;i<s[1];i++){
				if(h[arr[i][0]]!=long.MinValue&&h[arr[i][1]]<h[arr[i][0]]+arr[i][2]){
					h[arr[i][1]]=h[arr[i][0]]+arr[i][2];
					if(l>s[0]&&arr[i][1]==s[0]){b=true;}
				}
			}
		}
		Console.WriteLine("{0}",b?"inf":h[s[0]].ToString());
	}
}