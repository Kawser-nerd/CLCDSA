import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class B {

	void solve(int icase) {
		int L = si();
		long t = sl() / 2;
		int N = si();
		int[] a = new int[si()];

		for (int i = 0; i < a.length; i++) {
			a[i] = si();
		}

		long hours = 0;

		List<Integer> dists = new ArrayList<Integer>();

		for (int star = 0; star < N; star++) {
			int dist = a[star % a.length];
			if (t >= dist) {
				t -= dist;
				hours += dist * 2;
			} else if (t > 0) {
				dists.add((int) (dist - t));
				hours += t * 2;
				t = 0;
			} else {
				dists.add(dist);
			}
		}

		Collections.sort(dists);

		for (int i = dists.size() - 1; i >= 0; i--) {
			hours += dists.get(i) * (L > 0 ? 1 : 2);
			L--;
		}

		printf("Case #%d: %d\n", icase, hours);
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new B().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		sline();
		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}

}
