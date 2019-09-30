using System;
	class Program {
		static void Main(string[] args) {
			int N = int.Parse(Console.ReadLine());
			string[] str = new string[N];
			for (int i = 0; i < N; i++) {
				var get = Console.ReadLine();
				for (int n = 0; n < N; n++) {
					str[n] = get[n] + str[n];
				}
			}
			for (int i = 0; i < N; i++) {
				Console.WriteLine(str[i]);
			}
		}
	}