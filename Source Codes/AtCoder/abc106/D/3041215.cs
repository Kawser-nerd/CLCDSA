using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[,] a=new int[s[0]+1,s[0]+1];
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			a[q[0],q[1]]++;
		}
		for(int i=1;i<=s[0];i++){for(int j=1;j<=s[0];j++){a[i,j]+=a[i,j-1];}}
		for(int i=1;i<=s[0];i++){for(int j=1;j<=s[0];j++){a[i,j]+=a[i-1,j];}}
		for(int k=0;k<s[2];k++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			Console.WriteLine("{0}",a[q[1],q[1]]-a[q[0]-1,q[1]]-a[q[1],q[0]-1]+a[q[0]-1,q[0]-1]);
		}
	}
}