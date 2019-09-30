import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		int numA = 0;
		int numB = 0;

		try {
			scanner = new Scanner(System.in);
			numA = scanner.nextInt();
			numB = scanner.nextInt();

			int res = numA - 1;
			res += numB >= numA ? 1 : 0;

			System.out.println(res);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int[] wk = new int[3];
		int numK = 0;

		try {
			scanner = new Scanner(System.in);
			wk[0] = scanner.nextInt();
			wk[1] = scanner.nextInt();
			wk[2] = scanner.nextInt();
			numK = scanner.nextInt();

			Arrays.sort(wk);

			int res = wk[wk.length - 1];
			for (int i = 0; i < numK; i++) {
				res *= 2;
			}
			wk[wk.length - 1] = res;
			res = 0;
			for (int i = 0; i < 3; i++) {
				res += wk[i];
			}

			System.out.println(res);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private boolean hasNeighbor(char[][] wk, int i, int j, int maxH, int muxW) {
		int cnt = 0;

		if (i > 0 && wk[i - 1][j] == '#') {
			cnt++;
		}
		if (j < muxW - 1 && wk[i][j + 1] == '#') {
			cnt++;
		}
		if (i < maxH - 1 && wk[i + 1][j] == '#') {
			cnt++;
		}
		if (j > 0 && wk[i][j - 1] == '#') {
			cnt++;
		}

		return cnt > 0;
	}

	private void solveC() {
		Scanner scanner = null;
		int numH = 0;
		int numW = 0;

		try {
			scanner = new Scanner(System.in);
			numH = scanner.nextInt();
			numW = scanner.nextInt();
			char[][] wk = new char[numH][numW];

			for (int i = 0; i < numH; i++) {
				wk[i] = scanner.next().toCharArray();
			}

			boolean isRepaint = true;
			outside: for (int i = 0; i < numH; i++) {
				for (int j = 0; j < numW; j++) {
					if (wk[i][j] == '#') {
						isRepaint = hasNeighbor(wk, i, j, numH, numW);
						if (!isRepaint) {
							break outside;
						}
					}
				}
			}

			System.out.println(isRepaint ? "Yes" : "No");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveD() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}
}