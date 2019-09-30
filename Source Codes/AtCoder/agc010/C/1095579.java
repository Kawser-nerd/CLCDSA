import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static long[] A;
	static ArrayList<Integer>[] adj;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		A = new long[N];
		int[] a = new int[N - 1];
		int[] b = new int[N - 1];
		adj = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < N - 1; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			adj[a[i] - 1].add(b[i] - 1);
			adj[b[i] - 1].add(a[i] - 1);
		}
		sc.close();

		String ans = getCnt(0, -1) == 0 ? "YES" : "NO";
		System.out.println(ans);
	}

	private static long getCnt(int cur, int parent) {
		if (parent != -1 && adj[cur].size() == 1) {
			return A[cur];
		}
		long max = 0;
		long sum = 0;
		for (int child : adj[cur]) {
			if (child == parent) {
				continue;
			}
			long cnt = getCnt(child, cur);
			if (cnt == -1) {
				return -1;
			}
			sum += cnt;
			max = Math.max(cnt, max);
		}
		if (parent == -1 && adj[cur].size() == 1) {
			return A[cur] == sum ? 0 : -1;
		}
		if (A[cur] > sum) {
			return -1;
		}
		if (sum - A[cur] > sum - max || sum - A[cur] > sum / 2) {
			return -1;
		}
		return 2 * A[cur] - sum;
	}
}