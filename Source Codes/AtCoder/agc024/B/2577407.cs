using System;
class Program
{
	static void Main(string[] args)
	{
		string s = Console.ReadLine();
		int N = int.Parse(s);
		int [] P = new int[N];
		for(var i=0;i<N;i++){
			string t = Console.ReadLine();
			int m = int.Parse(t);
			P[m-1] = 1;
			if(m >= 2){
				if(P[m-2] >= P[m-1]){
					P[m-1] += P[m-2];
				} 
			}
		}
		var countmax = 0;
		for(var i=0;i<N;i++){
			countmax = Math.Max(countmax, P[i]);
		}
		Console.WriteLine(N-countmax);
	}
}