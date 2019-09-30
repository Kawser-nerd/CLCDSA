using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int n=int.Parse(Console.ReadLine());
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] c=new int[s[0]][];
		int q=0;
		for(int i=0;i<s[0];i++){
			c[i]=new int[s[1]];
			if(i%2==0){
				for(int j=0;j<s[1];j++){
					c[i][j]=q+1;
					a[q]--;
					if(a[q]==0){q++;}
				}
			}
			else{
				for(int j=s[1]-1;j>-1;j--){
					c[i][j]=q+1;
					a[q]--;
					if(a[q]==0){q++;}
				}
			}
			Console.WriteLine("{0}",string.Join(" ",c[i]));
		}
	}
}