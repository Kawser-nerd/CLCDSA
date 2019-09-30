using System;
class Program
{
	static void Main(string[] args)
	{
		string s = Console.ReadLine();
		long N = long.Parse(s);
		long [] P = new long[N];
		long count = 0;
		string b = Console.ReadLine();
		P[0] = long.Parse(b);
		if(P[0] > 0){
			count = -1;
		} else {
			for(var i=1;i<N;i++){
				string t = Console.ReadLine();
				P[i] = long.Parse(t);
				if(P[i] - P[i-1] == 1){
					count += 1;
				} else if(P[i] - P[i-1] >= 2){
					count = -1;
					break;
				} else {
					count += P[i];
				}
			}
		}
		Console.WriteLine(count);
	}
}