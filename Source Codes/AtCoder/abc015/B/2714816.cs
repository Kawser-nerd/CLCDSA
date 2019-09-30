using System;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		int[] arr=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		
		int b=0,c=0;

		for (int i=0;i<s;i++){
			if(arr[i]>0){b+=arr[i];c++;}
		}

		Console.WriteLine("{0}",Math.Ceiling(1.0*b/c));
	}
}