using System;
class Program
{
	static void Main(string[] args)
	{
		// ???????
		int N = int.Parse(Console.ReadLine()); 
		string[] input1 = Console.ReadLine().Split(' ');
		int T = int.Parse(input1[0]);	
		int A = int.Parse(input1[1]);	
		string[] input2 = Console.ReadLine().Split(' ');
		int[] H = new int[N];			
		
		for( var i = 0; i < N; i++ ){
			H[i] = int.Parse(input2[i]);
		}
		
		int index = 0;
		double MinDiffT = A - ( T - H[0] * 0.006 );
		for( var i = 1; i < N; i++ ){
			double t = T - H[i] * 0.006;
			double diff = A - t;
			if(  Math.Abs(diff) < Math.Abs(MinDiffT) ){
				MinDiffT = diff;
				index = i;
			}
		}
		Console.WriteLine(index + 1);
	}
}