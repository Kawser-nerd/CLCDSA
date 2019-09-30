import java.util.*;
public class Main {
	static long mod = 1000000007;
	static long arrayCombi[][] = new long[1000][1000];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int row = sc.nextInt();
		int column = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int desk = sc.nextInt();
		int rack = sc.nextInt();
		int sum = desk + rack;
		long ans = 0;

		for(int i = 0; i < 1 << 4; i ++) {
			int tmpX = x;
			int tmpY = y;
			if((i & 1 << 0) != 0) { tmpX --; }
			if((i & 1 << 1) != 0) { tmpX --; }
			if((i & 1 << 2) != 0) { tmpY --; }
			if((i & 1 << 3) != 0) { tmpY --; }
			if(tmpX < 0 || tmpY < 0) { continue; }
			ans = advMod(ans + combi(tmpX * tmpY, sum) * (Integer.bitCount(i) % 2 == 0 ? 1 : -1));
		}

		ans = advMod(ans * combi(sum, desk));
		ans = advMod(ans * (row - x + 1) * (column - y + 1));
		System.out.println((ans + mod) % mod);
	}

	public static long combi(int n, int r){
		if(n <= 0 || n < r) { return 0; }
		r = Math.min(n - r, r);
		if(r == 0) { return 1; }
		if(arrayCombi[n][r] > 0) { return arrayCombi[n][r]; }
		arrayCombi[n][r] = advMod(combi(n - 1, r - 1) + combi(n - 1, r));
		return arrayCombi[n][r];
	}

	public static long advMod(long i) {
		return i % mod + ((i % mod) < 0 ? mod : 0);
	}
}