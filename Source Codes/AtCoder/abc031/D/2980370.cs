using System;
class Program{
	static int[] h=new int[10];
	static string[] k=new string[10];
	static int[] s;
	static bool b=false;
	static string[][] arr;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		arr=new string[s[1]][];
		for(int i=0;i<s[1];i++){arr[i]=Console.ReadLine().Split();}
		fu(1);
		for(int i=1;i<=s[0];i++){Console.WriteLine(k[i]);}
	}
	static void fu(int a){
		if(b){}
		else if(a<=s[0]){
			h[a]=1;fu(a+1);
			h[a]=2;fu(a+1);
			h[a]=3;fu(a+1);
		}
		else{
			b=true;
			for(int i=0;i<s[1];i++){
				int p=0;
				for(int j=0;j<arr[i][0].Length;j++){
					p+=h[arr[i][0][j]-'0'];
				}
				if(p!=arr[i][1].Length){b=false;break;}
			}
			if(b){
				for(int i=0;i<s[1];i++){
					int p=0;
					for(int j=0;j<arr[i][0].Length;j++){
						k[arr[i][0][j]-'0']=arr[i][1].Substring(p,h[arr[i][0][j]-'0']);
						p+=h[arr[i][0][j]-'0'];
					}
				}
			}
		}
	}
}