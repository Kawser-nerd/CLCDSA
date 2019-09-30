using System;

public class Solver {
	public static long GCD(long x, long y){
		if(x == 0) return y;
		if(y == 0) return x;
		if(x == 1 || y == 1) return 1;
		return GCD(y, x%y);
	}
	public static int p2(long k){
		if(k == 1) return 0;
		if(k%2 == 1) return -1;
		for(int i=1;; i++){
			k /= 2;
			if(k == 1) return i;
			if(k%2 == 1) return -1;
		}
	}
	public static int compute(long p, int q, int curr){
		if(p == (1<<q)) return curr;
		if(p > (1<<(q-1))) {
			if(q + curr <= 40) return curr+1;
			return -100;
		}else{
			return compute(p, q-1, curr+1);
		}
	}
	public static void Main(string[] args) {
		int T = int.Parse(Console.ReadLine());
		for(int Ti=1; Ti<=T; Ti++) {
			string[] line = Console.ReadLine().Split('/');
			long p = long.Parse(line[0]), q = long.Parse(line[1]);
			long g = GCD(p, q); p /= g; q /= g;
			if(p2(q) < 0) Console.WriteLine("Case #{0}: impossible", Ti);
			else Console.WriteLine("Case #{0}: {1}", Ti, compute(p, p2(q), 0));
		}
	}
}
