import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] a = new int[N][2];
		int[][] ans = new int[M + 1][];
		for (int i = 1; i <= M; ++i) {
			ans[i] = new int[M / i + 1];
		}
		ArrayList<Integer>[] lis = new ArrayList[M + 1];
		for (int i = 0; i < lis.length; ++i) {
			lis[i] = new ArrayList<>();
		}
		for (int i = 0; i < N; ++i) {
			a[i][0] = sc.nextInt();
			a[i][1] = sc.nextInt();
			lis[a[i][0]].add(a[i][1]);
		}
		FenwickTree ft = new FenwickTree(M + 1);
		ArrayList<Integer>[] div = new ArrayList[M + 1];
		for (int i = 0; i < div.length; ++i) {
			div[i] = new ArrayList<>();
		}
		for (int i = 1; i <= M; ++i) {
			for (int j = i; j <= M; j += i) {
				div[j].add(i);
			}
		}
		for (int i = 1; i <= M; ++i) {
			for (int v : lis[i]) {
				ft.add(v, 1);
			}
			for (int v : div[i]) {
				int k = v;
				int m = i / k;
				ans[m][k] += ft.sum(Math.min(M, (k + 1) * m - 1)) - ft.sum(k * m - 1);
			}
		}
		PrintWriter pw = new PrintWriter(System.out);
		for (int m = 1; m <= M; ++m) {
			int s = 0;
			for (int v : ans[m]) {
				s += v;
			}
			pw.println(s);
		}
		pw.close();
	}

	class FenwickTree {
		int n;
		int[] v;

		public FenwickTree(int n) {
			this.n = n;
			v = new int[n + 1];
		}

		void add(int k, int val) {
			while (k <= n) {
				v[k] += val;
				k += k & -k;
			}
		}

		int sum(int k) {
			int s = 0;
			while (k > 0) {
				s += v[k];
				k -= k & -k;
			}
			return s;
		}

	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.