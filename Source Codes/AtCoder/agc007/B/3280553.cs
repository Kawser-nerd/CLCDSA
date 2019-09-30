using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] p=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] a=new int[n],b=new int[n];
		for(int i=0;i<n;i++){b[p[i]-1]=(i+1)*1;}
		a[0]=1;
		b[0]--;
		int m=0;
		for(int i=1;i<n;i++){
			a[i]=a[i-1]+1;
			b[i]-=a[i-1]+1;
			if(b[i]>=b[i-1]){
				a[i]+=b[i]-b[i-1]+1;
				b[i]=b[i-1]-1;
			}
			m=Math.Min(m,b[i]);
		}
		for(int i=0;i<n;i++){b[i]-=m-1;}
		Console.WriteLine(String.Join(" ",a));
		Console.WriteLine(String.Join(" ",b));
	}
}