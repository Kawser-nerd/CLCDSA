import java.util.Locale;
import java.util.Scanner;

public class B {

	int[] mins = new int[3000001];

	void solve(int icase) {
		int x = si();
		int y = si();

		int k = mins[Math.abs(x) + Math.abs(y)];

		char[] res = new char[k];

		while (x != 0 || y != 0 || k > 0) {
			char c;
			if (Math.abs(x) > Math.abs(y)) {
				if (x > 0) {
					x -= k;
					c = 'E';
				} else {
					x += k;
					c = 'W';
				}
			} else {
				if (y > 0) {
					y -= k;
					c = 'N';
				} else {
					y += k;
					c = 'S';
				}
			}
			k--;
			res[k] = c;
		}

		printf("Case #%d: ", icase);
		for (int i = 0; i < res.length; i++) {
			System.out.print(res[i]);
		}
		System.out.println();
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new B().repSolve();
	}

	void repSolve() throws Exception {
		int k = 0;
		for (int i = 1;; i++) {
			k += i;
			if (k >= mins.length) {
				break;
			}
			for (int j = k; j > 0; j -= 2) {
				if (mins[j] != 0) {
					break;
				}
				mins[j] = i;
			}
		}

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
