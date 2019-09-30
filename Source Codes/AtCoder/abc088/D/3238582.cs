using System;
using System.Collections.Generic;
class Program{
	static long[] s;
	static int[,] h;
	static List<int[]> li=new List<int[]>();
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		h=new int[s[0],s[1]];
		int ans=0;
		for(int i=0;i<s[0];i++){
			string q=Console.ReadLine();
			for(int j=0;j<s[1];j++){
				if(q[j]=='.'){ans++;}
				else{h[i,j]=-1;}
			}
		}
		h[0,0]=1;
		li.Add(new int[]{0,0});
		while(li[0][0]!=s[0]-1||li[0][1]!=s[1]-1){
			if(li[0][0]!=0){fu(li[0][0]-1,li[0][1],h[li[0][0],li[0][1]]+1);}
			if(li[0][1]!=0){fu(li[0][0],li[0][1]-1,h[li[0][0],li[0][1]]+1);}
			if(li[0][0]!=s[0]-1){fu(li[0][0]+1,li[0][1],h[li[0][0],li[0][1]]+1);}
			if(li[0][1]!=s[1]-1){fu(li[0][0],li[0][1]+1,h[li[0][0],li[0][1]]+1);}
			li.RemoveAt(0);
			if(li.Count==0){break;}
		}
		Console.WriteLine("{0}",li.Count==0?-1:ans-h[s[0]-1,s[1]-1]);
	}
	static void fu(int x,int y,int p){
		if(h[x,y]==0){
			h[x,y]=p;
			li.Add(new int[]{x,y});
		}
	}
}