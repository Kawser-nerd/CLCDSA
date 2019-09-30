using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[,] h=new long[s[0]*s[1]+1,2];
		long[] a=new long[s[0]*s[1]+1];
		long[][] arr=new long[s[0]][];
		for(int i=0;i<s[0];i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			for(int j=0;j<s[1];j++){
				h[arr[i][j],0]=i;
				h[arr[i][j],1]=j;
			}
		}
		for(int i=1;i<=s[0]*s[1]-s[2];i++){
			a[i+s[2]]=Math.Abs(h[i+s[2],0]-h[i,0])+Math.Abs(h[i+s[2],1]-h[i,1])+a[i];
		}
		int n=int.Parse(Console.ReadLine());
		for(int i=0;i<n;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			Console.WriteLine("{0}",a[q[1]]-a[q[0]]);
		}
	}
}