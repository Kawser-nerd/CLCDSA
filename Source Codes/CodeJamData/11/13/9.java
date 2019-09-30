import java.util.*;

public class C {
	private static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		System.err.println("t = " + t);
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %d\n", i + 1, exec());
	}
	
	private static int counter = 0;
	
	private static int exec() {
		int n = sc.nextInt();
		int[] hc = new int[n], hs = new int[n], ht = new int[n];
		for (int i = 0; i < n; i++) {
			hc[i] = sc.nextInt();
			hs[i] = sc.nextInt();
			ht[i] = sc.nextInt();
		}
		int m = sc.nextInt();
		int[] dc = new int[m], ds = new int[m], dt = new int[m];
		for (int i = 0; i < m; i++) {
			dc[i] = sc.nextInt();
			ds[i] = sc.nextInt();
			dt[i] = sc.nextInt();
		}
		
		int[] c = new int[n + m], s = new int[n + m], t = new int[n + m];
		for (int i = 0; i < n; i++) {
			c[i] = hc[i];
			s[i] = hs[i];
			t[i] = ht[i];
		}
		for (int i = 0; i < m; i++) {
			c[i + n] = dc[i];
			s[i + n] = ds[i];
			t[i + n] = dt[i];
		}
		
		boolean[] u = new boolean[n + m];
		System.err.println("CASE: " + (++counter));
		return calc(n, c, s, t, u, 0, 1);
	}
	
	private static int calc(int n, int[] c, int[] s, int[] t, boolean[] u, int score, int turns) {
		if (turns < 1) return score;
		n = Math.min(n, u.length);
		// First play all cards that give 1+ turns.
		for (int i = 0; i < n; i++) {
//			System.err.printf("i:%d n:%d\n", i, n);
			if (u[i]) continue;
			if (t[i] > 0) {
				u[i] = true;
				score += s[i];
				n += c[i];
				n = Math.min(n, u.length);
				turns += t[i] - 1;
			}
		}
		
		// Now we choose either to optimize score or cards, dynamically.
		
		// Best 0c pick
		int best0s = -1;
		int best0i = -1;
		for (int i = 0; i < n; i++) {
			if (u[i]) continue;
			if (s[i] > best0s || (s[i] == best0s && c[best0i] < c[i])) {
				best0i = i;
				best0s = s[i];
			}
		}
		// Best 1c pick
		int best1s = -1;
		int best1i = -1;
		for (int i = 0; i < n; i++) {
			if (u[i]) continue;
			if (c[i] < 1) continue;
			if (s[i] > best1s || (s[i] == best1s && c[best1i] < c[i])) {
				best1i = i;
				best1s = s[i];
			}
		}
		// Best 2c pick
		int best2s = -1;
		int best2i = -1;
		for (int i = 0; i < n; i++) {
			if (u[i]) continue;
			if (c[i] < 2) continue;
			if (s[i] > best2s || (s[i] == best2s && c[best2i] < c[i])) {
				best2i = i;
				best2s = s[i];
			}
		}
		
		// Going for more is pointless if there are no more cards in the deck.
		if (n + 1 >= c.length) best2i = -1;
		if (n >= c.length) best1i = -1;
		
		// Going for more is pointless if there are no more turns.
		if (turns == 1) {best2i = -1; best1i = -1;}
		
		if (best2s == best1s) best1i = -1;
		if (best2i != -1 && best2s == best0s) best0i = -1;
		if (best1i != -1 && best1s == best0s) best0i = -1;
		
		if (best2i == -1 && best1i == -1 && best0i == -1) return score;
		
		int best = -1;
		if (best2i != -1) {
			boolean[] ux2 = Arrays.copyOf(u, u.length);
			ux2[best2i] = true;
			best = Math.max(best, calc(n + c[best2i], c, s, t, ux2, score + s[best2i], turns - 1));
		}
		
		if (best1i != -1) {
			boolean[] ux1 = Arrays.copyOf(u, u.length);
			ux1[best1i] = true;
			best = Math.max(best, calc(n + c[best1i], c, s, t, ux1, score + s[best1i], turns - 1));
		}
		
		if (best0i != -1) {
			boolean[] ux0 = Arrays.copyOf(u, u.length);
			ux0[best0i] = true;
			best = Math.max(best, calc(n + + c[best0i], c, s, t, ux0, score + s[best0i], turns - 1));
		}
		
		return best;
	}
}
