using System;
class Program{
	static long[] s;
	static int[,] arr;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		arr=new int[s[0],s[1]];
		int ans=0;
		for(int i=0;i<s[0];i++){
			string q=Console.ReadLine();
			for(int j=0;j<s[1];j++){
				if(q[j]=='.'){arr[i,j]=int.MaxValue;ans++;}
				else{arr[i,j]=-1;}
			}
		}
		fu(0,0,0);
		Console.WriteLine("{0}",arr[s[0]-1,s[1]-1]==int.MaxValue?-1:ans-arr[s[0]-1,s[1]-1]-1);
	}
	static void fu(int x,int y,int p){
		if(arr[x,y]>p){
			arr[x,y]=p;
			if(x!=s[0]-1||y!=s[1]-1){
				if(x!=0){fu(x-1,y,p+1);}
				if(y!=0){fu(x,y-1,p+1);}
				if(x!=s[0]-1){fu(x+1,y,p+1);}
				if(y!=s[1]-1){fu(x,y+1,p+1);}
			}
		}
	}
}