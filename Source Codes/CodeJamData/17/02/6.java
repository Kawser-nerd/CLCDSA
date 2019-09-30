import java.util.*;

class B {
	static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		int T = in.nextInt();
		
		for (int t = 0; t < T; ++t) {
			System.out.printf("Case #%d: %d%n", t + 1, solve());
		}
	}
	
	static long solve() {
		String s = in.next();
		char[] c = s.toCharArray();
		
		for (int i = 1; i < c.length; ++i) {
			if (c[i - 1] > c[i]) {
				c[i - 1]--;
				while (i - 2 >= 0 && c[i - 1] < c[i - 2]) {
					i--;
					c[i - 1]--;
				}
				while (i < c.length) {
					c[i++] = '9';
				}
			}
		}
		
		return Long.valueOf(new String(c));
	}
}