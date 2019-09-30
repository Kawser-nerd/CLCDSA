import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class C {

	class Tribe {
		int d, n, w, e, s, deltaD, deltaP, deltaS;
	}

	Tribe[] t;

	class Attack {
		int d, w, e, s;
	}

	void solve(int icase) {
		int N = si();
		t = new Tribe[N];

		int nPos = 0;
		int[] allPos = new int[N * 2000];

		for (int i = 0; i < N; i++) {
			Tribe x = t[i] = new Tribe();
			x.d = si();
			x.n = si();
			x.w = si();
			x.e = si();
			x.s = si();
			x.deltaD = si();
			x.deltaP = si();
			x.deltaS = si();

			nPos += addPos(x, allPos, nPos);
		}

		Arrays.sort(allPos, 0, nPos);

		Attack[] at = new Attack[nPos / 2];

		Map<Integer, Integer> mpos = new HashMap<Integer, Integer>(nPos);
		for (int p : allPos) {
			if (!mpos.containsKey(p)) {
				mpos.put(p, mpos.size());
			}
		}

		int ai = 0;
		for (Tribe x : t) {
			for (int i = 0; i < x.n; i++) {
				Attack a = at[ai++] = new Attack();
				a.d = x.d + i * x.deltaD;
				a.w = 2 * mpos.get(x.w + i * x.deltaP);
				a.e = 2 * mpos.get(x.e + i * x.deltaP);
				a.s = x.s + i * x.deltaS;
			}
		}

		Arrays.sort(at, new Comparator<Attack>() {
			@Override
			public int compare(Attack a1, Attack a2) {
				return a1.d - a2.d;
			}
		});

		int[] h = new int[2 * mpos.size()];
		int success = 0;

		for (int i = 0; i < at.length;) {
			int k = i + 1;
			while (k < at.length && at[i].d == at[k].d) {
				k++;
			}

			for (int j = i; j < k; j++) {
				Attack a = at[j];

				for (int p = a.w; p <= a.e; p++) {
					if (h[p] < a.s) {
						success++;
						break;
					}
				}
			}

			for (int j = i; j < k; j++) {
				Attack a = at[j];

				for (int p = a.w; p <= a.e; p++) {
					if (h[p] < a.s) {
						h[p] = a.s;
					}
				}
			}

			i = k;
		}

		printf("Case #%d: %d\n", icase, success);
	}

	int addPos(Tribe x, int[] allPos, int nPos) {
		for (int i = 0; i < x.n; i++) {
			allPos[nPos + 2 * i] = x.w + i * x.deltaP;
			allPos[nPos + 2 * i + 1] = x.e + i * x.deltaP;
		}

		return 2 * x.n;
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
