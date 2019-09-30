using System;

class main{
	static void Main(){
		int N = int.Parse(Console.ReadLine());
		string[] str = Console.ReadLine().Trim().Split(' ');
		int D = int.Parse(str[0]);
		int X = int.Parse(str[1]);
		int ans = X;
		for(int i = 0; i < N; i++){
			int A = int.Parse(Console.ReadLine());
			ans += (D - 1) / A + 1;
		}
		Console.WriteLine(ans);
	}
}