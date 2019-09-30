import java.util.Locale;
import java.util.Scanner;

public class C {

	int n;
	int low;
	int high;
	int[] fs;

	void solve(int icase) {
		n = si();
		low = si();
		high = si();
		fs = new int[n];

		for (int i = 0; i < n; i++) {
			fs[i] = si();
		}

		int res = -1;

		for (int i = low; i <= high; i++) {
			res = i;
			for (Integer f : fs) {
				if (f % i != 0 && i % f != 0) {
					res = -1;
					break;
				}
			}
			if (res != -1) {
				break;
			}
		}

		printf("Case #%d: %s\n", icase, res == -1 ? "NO" : ("" + res));
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new C().repSolve();
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
