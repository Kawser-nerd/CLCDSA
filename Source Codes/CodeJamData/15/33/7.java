// darn rust is too hard
import java.util.*;

class Money {
	static Scanner s = new Scanner(System.in);
	static void tc(int tci) {
		long c = s.nextLong();
		int nd = s.nextInt();
		long v = s.nextLong();
		ArrayList<Long> denoms = new ArrayList<Long>();
		long best = 0;
		long bad = 0;
		for (int i = 0; i < nd; i++) {
			long d = s.nextLong();
			while (best < d - 1) {
				best = best + c * (best + 1);
				bad += 1;
			}
			best = best + c * d;
		}
		while (best < v) {
			best = (c + 1) * (best + 1) - 1;
			bad += 1;
		}
		System.out.printf("Case #%d: %d\n", tci, bad);
	}

	public static void main(String[] args) {
		int tcn = s.nextInt();
		for (int tci = 1; tci <= tcn; tci++) {
			tc(tci);
		}
	}
}
