import java.util.Locale;
import java.util.Scanner;

public class A {

	void solve(int icase) {
		String name = ss();
		int n = si();
		sline();

		int[] idx = new int[name.length()];

		int v = 0;
		int lastIdx = -1;
		for (int i = name.length() - 1; i >= 0; i--) {
			boolean c = cons(name.charAt(i));

			if (!c) {
				v = 0;
			} else {
				v++;
			}

			if (v >= n) {
				lastIdx = i + n - 1;
			}

			idx[i] = lastIdx;
		}

		long res = 0;

		for (int i = 0; i < idx.length; i++) {
			if (idx[i] != -1) {
				res += idx.length - idx[i];
			}
		}

		printf("Case #%d: %d\n", icase, res);
	}

	boolean cons(char c) {
		return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().repSolve();
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
