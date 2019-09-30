using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program {
	static void Main(string[] args) {
		new Calc().Solve();
		return;
	}

	public class Calc {
		Scan cin = new Scan();
		public void Solve() {
			var HW = cin.ReadLong(' ');
			long mod = 1000000000 + 7;
			long X = HW[0] + HW[1] - 2, Y = HW[0] - 1, Z = HW[1] - 1;
			for (long i = X - 1; i > 0; i--) {
				X = X * i % mod;
			}
			for (long i = 1; i <= Y; i++) {
				X *= (ModPow(i, mod - 2, mod) % mod);
				X %= mod;
			}
			for (long i = 1; i <=Z; i++) {
				X *= (ModPow(i, mod - 2, mod) % mod);
				X %= mod;
			}
			(X%mod).WL();
			return;
		}
		private long ModPow(long a,long b,long p) {
			if (b == 0) return 1;
			if(b%2==0) {
				long d = ModPow(a, b / 2, p);
				return (d * d) % p;
			} else {
				return (a * ModPow(a, b - 1, p)) % p;
			}
		}
	}


}
public class Scan {
	
	public int ReadInt() => int.Parse(Console.ReadLine());
	public int[] ReadInt(char separators) => Console.ReadLine().Split(separators).Select(int.Parse).ToArray();
	public double ReadDouble() => double.Parse(Console.ReadLine());
	public double[] ReadDouble(char separators) => Console.ReadLine().Split(separators).Select(double.Parse).ToArray();
	public long ReadLong() => long.Parse(Console.ReadLine());
	public long[] ReadLong(char separators) => Console.ReadLine().Split(separators).Select(long.Parse).ToArray();
	public string ReadLine() => Console.ReadLine();
}
public static class Utils {
	public static void WL(this object obj) {
		Console.WriteLine(obj);
	}
	public static string Docking<T>(this IEnumerable<T> collection, Func<T, string> filter = null) {
		StringBuilder sb = new StringBuilder();
		foreach (var item in collection) {
			string str = filter != null ? filter(item) : item.ToString();
			sb.Append(str);
		}
		return sb.ToString();
	}
	public static void WriteLineAll<T>(this IEnumerable<T> collection) {
		foreach (var item in collection) {
			item.WL();
		}
	}

}