import java.util.*;

public class Main
{
	public static void main(String[] args) {
		new Main().run();
	}

	static final int I = 2, J = 3, K = 4;
	static int[][] table = {
		{1,I,J,K},
		{I,-1,K,-J},
		{J,-K,-1,I},
		{K,J,-I,-1}
	};

	void run() {
		Scanner in = new Scanner(System.in);
		int[] targets = { I, J, K };
		int ts = in.nextInt();
		for (int ti = 1; ti <= ts; ti++) {
			int len = in.nextInt();
			long reps = in.nextLong();
			String line = in.next();
			boolean ans = possible(parse(line), reps, targets);
			System.out.format("Case #%d: %s\n", ti, ans ? "YES" : "NO");
		}
	}

	int[] parse(String line) {
		int[] res = new int[line.length()];
		for (int i = 0; i < line.length(); i++) {
			res[i] = line.charAt(i) - 'i' + I;
		}
		return res;
	}

	boolean possible(int[] line, long reps, int[] targets) {
		int i = 0;
		int t = targets[0];
		int x = 1;
		for (int r = 0; r < (int) Math.min(reps, 4*3); r++) {
			for (int q : line) {
				x = mult(x, q);
				if (x == t) {
					i++;
					t = mult(t, targets[i]);
					if (i == targets.length - 1) {
						return exp(prod(line), reps) == t;
					}
				}
			}
		}
		return false;
	}

	int prod(int[] line) {
		int p = 1;
		for (int x : line) {
			p = mult(p, x);
		}
		return p;
	}

	int exp(int x, long n) {
		int p = 1;
		for (int i = 0; i < n % 4; i++) {
			p = mult(p, x);
		}
		return p;
	}

	int mult(int a, int b) {
		return Integer.signum(a) * Integer.signum(b)
			* table[Math.abs(a)-1][Math.abs(b)-1];
	}
}
