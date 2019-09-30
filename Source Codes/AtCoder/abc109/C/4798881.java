import java.util.*;

public class Main {
	public static long MOD = 1000000007l;

	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] city = new int[n + 1];
		for (int i = 0; i < n; i++) {
			city[i] = sc.nextInt();
		}
		sc.close();
		city[n] = x;
		Arrays.sort(city);
		int[] sa = new int[n];
		for (int i = 0; i < n; i++) {
			sa[i] = city[i + 1] - city[i];
		}
		if (n!=1)
			System.out.println(gcd(sa));
		else
			System.out.println(city[1] - city[0]);
	}

	public static final int gcd(final int[] param) {
		final int len = param.length;
		int g = gcd(param[0], param[1]); // gcd(a, b) ????????
		for (int i = 1; i < len - 1; i++) {
			g = gcd(g, param[i + 1]); // gcd(a, b) ????????
		}
		return g;
	}

	public static final int gcd(int a, int b) {
		// a > b ???(swap)
		if (a < b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		// ??????????
		int r = -1;
		while (r != 0) {
			r = a % b;
			a = b;
			b = r;
		}

		return a; // b ?? r=0 ????????a ???
	}
}