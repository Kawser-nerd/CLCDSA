import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int g = sc.nextInt();
		Problem[] array = new Problem[d];
		for (int i = 0; i < d; i++) {
			array[i] = new Problem(100 * (i+1), sc.nextInt(), sc.nextInt());
		}
		sc.close();

		int ans = Integer.MAX_VALUE;
		System.out.println(dfs(d, g, array, "", ans));
	}

	static class Problem {
		int p;
		int c;
		int total;
		public Problem(int s, int p, int c) {
			this.p = p;
			this.c = c;
			this.total = s * p + c;
		}
	}

	static int dfs(int d, int g, Problem[] array, String select, int ans) {
		if (select.length() == d) {
			int total = 0;
			int cnt = 0;
			for (int i = 0; i < d; i++) {
				if (select.charAt(i) == '1') {
					total += array[i].total;
					cnt += array[i].p;
				}
			}
			if (g <= total) {
				return cnt;
			}
			for (int i = d - 1; i >= 0; i--) {
				if (select.charAt(i) == '0') {
					double zanScore = g - total;
					int zanCnt = (int) Math.ceil(zanScore / (100 * (i+1)));
					if (zanCnt < array[i].p) {
						cnt += zanCnt;
					} else {
						cnt = Integer.MAX_VALUE;
					}
					break;
				}
			}
			return cnt;
		}

		ans = Math.min(ans, dfs(d, g, array, select + "0", ans));
		ans = Math.min(ans, dfs(d, g, array, select + "1", ans));
		return ans;
	}
}