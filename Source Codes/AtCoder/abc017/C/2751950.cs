using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] arr=new int[s[1]+1];
		int b=0,c=1<<30;
		for (int i=0;i<s[0];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			for (int j=q[0];j<=q[1];j++){arr[j]+=q[2];}
			b+=q[2];
		}
		for (int i=1;i<=s[1];i++){if(arr[i]<c){c=arr[i];}}
		Console.WriteLine(b-c);
	}
}