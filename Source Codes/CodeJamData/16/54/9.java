import java.util.Arrays;
import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.println("Case #" + i + ": " + solve());
		}
	}

	static String solve() {
		int N = sc.nextInt();
		int L = sc.nextInt();
		String[] G = new String[N];
		for (int i = 0; i < N; ++i) {
			G[i] = sc.next();
		}
		String B = sc.next();
		for (int i = 0; i < N; ++i) {
			if (G[i].equals(B)) {
				return "IMPOSSIBLE";
			}
		}
		if (L == 1) {
			return "? 0";
		}
		char[] p1 = new char[L - 1];
		Arrays.fill(p1, '?');
		StringBuilder p2 = new StringBuilder();
		for (int i = 0; i < 49; ++i) {
			p2.append((char) ('0' + i % 2));
		}
		p2.append('?');
		for (int i = 0; i < 49; ++i) {
			p2.append((char) ('0' + (i + 1) % 2));
		}
		return String.valueOf(p1) + " " + p2.toString();
	}

}
