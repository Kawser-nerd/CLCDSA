using System;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		long[] arr;

		for(int i=0;i<s;i++){
			arr=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);

			if(arr[0]<arr[1]){Console.WriteLine("No");}
			else if(arr[1]>arr[3]){Console.WriteLine("No");}
			else if(arr[1]<=arr[2]+1){Console.WriteLine("Yes");}
			else{
				long g=gcd(arr[1],arr[3]);
				if(arr[1]-g+(arr[0]%g)>arr[2]){Console.WriteLine("No");}
				else{Console.WriteLine("Yes");}
			}
		}
	}
	static long gcd(long a,long b){
		long c=Math.Max(a,b)%Math.Min(a,b);
		b=Math.Min(a,b);
		while(c!=0){
			a=b%c;
			b=c;
			c=a;
		}
		return b;
	}
}