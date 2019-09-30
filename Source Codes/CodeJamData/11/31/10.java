import java.util.Locale;
import java.util.Scanner;

public class A {

	int nx, ny;

	char[][] pict;

	void solve(int icase) {
		ny = si();
		nx = si();

		pict = new char[ny][];

		for (int y = 0; y < ny; y++) {
			pict[y] = ss().toCharArray();
		}

		printf("Case #%d:\n", icase);

		if (insertAll()) {
			for (int y = 0; y < ny; y++) {
				for (int x = 0; x < nx; x++) {
					printf("%c", pict[y][x]);
				}
				printf("\n");
			}
		} else {
			printf("Impossible\n");
		}

	}

	boolean insertAll() {
		for (int y = 0; y < ny; y++) {
			for (int x = 0; x < nx; x++) {
				if (pict[y][x] == '#') {
					if (!insert(y, x)) {
						return false;
					}
				}
			}
		}
		return true;
	}

	boolean insert(int y, int x) {
		if (isBlue(y + 1, x) && isBlue(y, x + 1) && isBlue(y + 1, x + 1)) {
			pict[y][x] = '/';
			pict[y][x + 1] = '\\';
			pict[y + 1][x] = '\\';
			pict[y + 1][x + 1] = '/';
			return true;
		}
		return false;
	}

	boolean isBlue(int y, int x) {
		return y < ny && x < nx && pict[y][x] == '#';
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
