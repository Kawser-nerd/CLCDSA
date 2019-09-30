import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class C {

	static Scanner sc = new Scanner(System.in);
	static boolean[][] g;
	static int[] city;
	static int[] ord;
	static Stack<Integer> stack;
	static int N;
	static long ALL;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve());
		}
	}

	static String solve() {
		N = sc.nextInt();
		ALL = (1L << N) - 1;
		int M = sc.nextInt();
		int[] zip = new int[N];
		city = new int[N];
		ord = new int[N];
		for (int i = 0; i < N; ++i) {
			zip[i] = sc.nextInt();
			city[i] = (zip[i] << 10) + i;
		}
		Arrays.sort(city);
		for (int i = 0; i < N; ++i) {
			city[i] &= 0x3FF;
		}
		g = new boolean[N][N];
		for (int i = 0; i < M; ++i) {
			int t = sc.nextInt() - 1;
			int f = sc.nextInt() - 1;
			g[t][f] = g[f][t] = true;
		}
		ord[0] = city[0];
		stack = new Stack<>();
		stack.push(city[0]);
		dfs(1L << city[0], 1);
		String ret = "";
		for (int i = 0; i < N; ++i) {
			ret += zip[ord[i]];
		}
		return ret;
	}

	static boolean dfs(long state, int depth) {
		if (depth == N) {
			return true;
		}

		for (int i = 0; i < N; ++i) {
			int next = city[i];
			if ((state & (1L << next)) != 0) continue;
			ord[depth] = next;
			Stack<Integer> backup = new Stack<Integer>();
			backup.addAll(stack);
			while (!stack.isEmpty()) {
				int prev = stack.peek();
				if (g[prev][next]) {
					stack.push(next);
					if (ok(stack, state | (1L << next))) {
						dfs(state | (1L << next), depth + 1);
						return true;
					}
					stack.pop();
				}
				stack.pop();
			}
			stack = backup;
		}
		return false;
	}

	static boolean ok(Stack<Integer> history, long visited) {
		long all = visited;
		for (int i = 0; i < history.size(); ++i) {
			int cur = history.get(i);
			all |= checkVisit(cur, visited);
		}
		return all == ALL;
	}

	static long checkVisit(int cur, long visited) {
		long ret = visited;
		for (int i = 0; i < N; ++i) {
			if (!g[cur][i]) continue;
			if ((ret & (1L << i)) != 0) continue;
			ret |= checkVisit(i, visited | (1L << i));
		}
		return ret;
	}

}
