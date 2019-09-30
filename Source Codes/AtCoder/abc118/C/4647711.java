import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		System.out.println(gcd(a));
	}

	public static final int gcd(int a, int b) {
		// a > b ????swap?
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

	/**
	 * <h1>??????????????[gcd(a, b, c,...)]</h1>
	 * <p>
	 * ????????????????????
	 * </p>
	 * 
	 * @param param ? ??1, 2, 3,... (a, b, c,...) (>0) [???3???]
	 * @return<b>int</b> ? ?????(??=1[????])
	 */
	public static final int gcd(final int[] param) {
		final int len = param.length;
		int g = gcd(param[0], param[1]); // gcd(a, b) ????????
		for (int i = 1; i < len - 1; i++) {
			g = gcd(g, param[i + 1]); // gcd(a, b) ????????
		}
		return g;
	}
}