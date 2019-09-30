using System;
class Program{
	static string ans="Nothing";
	static int[][] arr;
	static int[] s;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		arr=new int[s[0]][];

		for (int i=0;i<s[0];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		}
		fu(0,0);

		Console.WriteLine(ans);
	}
	static void fu(int n,int i){
		if(i==s[0]){if(n==0){ans="Found";}}
		else if(ans=="Nothing"){
			for(int j=0;j<s[1];j++){
				fu(n^arr[i][j],i+1);
			}
		}
	}
}