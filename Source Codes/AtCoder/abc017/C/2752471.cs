using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] arr=new int[s[1]+2];
		int b=0,c=1<<30;
		for (int i=0;i<s[0];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			arr[q[0]]+=q[2];
			arr[q[1]+1]-=q[2];
			b+=q[2];
		}
		for (int i=1;i<=s[1];i++){
			arr[i]+=arr[i-1];
			if(arr[i]<c){c=arr[i];}
		}
		Console.WriteLine(b-c);
	}
}