package round1a;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int N = sc.nextInt();
			int L = sc.nextInt();
			Set<Long> need = new HashSet<Long>(), have = new HashSet<Long>();
			for (int i=0;i<N;i++) {
				String tmp = sc.next();
				long tmp2 = 0;
				for (int j=0;j<L;j++) if (tmp.charAt(j) == '1') tmp2 |= (1L<<j);
				have.add(tmp2);
			}
			long lastNeeded = 0;
			for (int i=0;i<N;i++) {
				String tmp = sc.next();
				long tmp2 = 0;
				for (int j=0;j<L;j++) if (tmp.charAt(j) == '1') tmp2 |= (1L<<j);
				need.add(tmp2);
				lastNeeded = tmp2;
			}
			int ans = L + 1;
			for (Long elem : have) {
				long flip = lastNeeded ^ elem;
				Set<Long> got = new HashSet<Long>();
				for (Long e : need) {
					got.add(e ^ flip);
				}
				if (got.equals(have)) {
					ans = Math.min(ans, Long.bitCount(flip));
				}
			}

			System.out.println("Case #" + caze + ": "  + (ans > L ? "NOT POSSIBLE" : ans));
		}
	}
}
