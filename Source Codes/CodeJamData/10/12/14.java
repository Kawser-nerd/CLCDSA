import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Smooth {

	private Scanner fin;
	private PrintStream fout;

	public Smooth(String in, String out) {
		try {
			fin = new Scanner(new FileInputStream(in));
			fout = new PrintStream(out);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private int D, I, M, N;
	private int cost[][];
	private final int MAX = 256;

	private void run() {
		int cas = fin.nextInt();
		for (int t = 1; t <= cas; ++t) {
			fout.println("Case #" + t + ": " + process());
		}
	}

	private int min(int a, int b) {
		return a < b ? a : b;
	}

	private int dis(int a, int b) {
		return a > b ? a - b : b - a;
	}

	private int process() {
		D = fin.nextInt();
		I = fin.nextInt();
		M = fin.nextInt();
		N = fin.nextInt();
		cost = new int[N + 1][MAX + 1];
		for (int j = 0; j < MAX; ++j) {
			cost[0][j] = I;
		}
		cost[0][MAX] = 0;
		for (int i = 1; i <= N; ++i) {
			int num = fin.nextInt();
			for (int j = 0; j < MAX; ++j) {
				cost[i][j] = min(cost[i - 1][MAX] + dis(num, j), cost[i - 1][j]
						+ D);
			}
			cost[i][MAX] = cost[i - 1][MAX] + D;
			for (int j = 0; j < MAX; ++j) {
				int tmp = cost[i - 1][j];
				for (int k = 1; k <= M; ++k) {
					if (j - k >= 0)
						tmp = min(tmp, cost[i - 1][j - k]);
					if (j + k < MAX)
						tmp = min(tmp, cost[i - 1][j + k]);
				}
				cost[i][j] = min(cost[i][j], tmp + dis(num, j));
			}
			for (int j = 0; j < MAX; ++j) {
				for (int k = 1; k <= M; ++k) {
					if (j + k < MAX) {
						cost[i][j + k] = min(cost[i][j + k], cost[i][j] + I);
					}
				}
			}
			for (int j = MAX - 1; j >= 0; --j) {
				for (int k = 1; k <= M; ++k) {
					if (j - k >= 0) {
						cost[i][j - k] = min(cost[i][j - k], cost[i][j] + I);
					}
				}
			}
		}
		int ret = cost[N][MAX];
		for (int i = 0; i < MAX; ++i) {
			ret = min(ret, cost[N][i]);
		}
		return ret;
	}

	public static void main(String[] args) {
		new Smooth("b.in", "b.out").run();
	}

}
