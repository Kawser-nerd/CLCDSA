using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
	static void Main(string[] args) {
		string[] input = Console.ReadLine().Split(' ');
		int tx_a = int.Parse(input[0]);
		int ty_a = int.Parse(input[1]);
		int tx_b = int.Parse(input[2]);
		int ty_b = int.Parse(input[3]);
		int t = int.Parse(input[4]);
		int v = int.Parse(input[5]);
		int n = int.Parse(Console.ReadLine());
		bool flag = false;

		for (int i = 0; i < n; i++) {
			input = Console.ReadLine().Split(' ');
			int hx = int.Parse(input[0]);
			int hy = int.Parse(input[1]);

			decimal dis_a = Sqrt((tx_a - hx) * (tx_a - hx) + (ty_a - hy) * (ty_a - hy));
			decimal dis_b = Sqrt((tx_b - hx) * (tx_b - hx) + (ty_b - hy) * (ty_b - hy));

			if (t * v >= dis_a + dis_b) {
				flag = true;
			}
		}
		if (flag) {
			Console.WriteLine("YES");
		} else {
			Console.WriteLine("NO");
		}
	}

	private static decimal Sqrt(decimal a) {
		if (a == 0) {
			return 0;
		}
		int calc = 100;
		decimal x1 = a * 100000;
		decimal x2 = 0;
		for (int n = 0; n < calc; n++) {
			x2 = x1 - (x1 * x1 - a) / (2 * x1);
			x1 = x2;
		}
		return x2;
	}
}