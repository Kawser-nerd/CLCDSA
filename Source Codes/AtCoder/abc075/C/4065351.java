import java.util.List;
import java.util.Queue;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int M = sc.nextInt();

		int[] a = new int[M];
		int[] b = new int[M];

		for (int i = 0; i < M; i++) {
			int ai = sc.nextInt();
			int bi = sc.nextInt();
			a[i] = ai;
			b[i] = bi;
		}

		int cnt = 0;
		for (int i = 0; i < M; i++) {
			HashMap<Integer, List<Integer>> graph = new HashMap<>();
			boolean[] visited = new boolean[N];
			int vcnt = 0;
			for (int j = 0; j < M; j++) {
				if (j == i) {
					continue;
				}
				int from = a[j] - 1;
				int to = b[j] - 1;
				if (!graph.containsKey(from)) {
					graph.put(from, new ArrayList<Integer>());
				}
				if (!graph.containsKey(to)) {
					graph.put(to, new ArrayList<Integer>());
				}
				graph.get(from).add(to);
				graph.get(to).add(from);
			}

			Queue<Integer> q = new LinkedList<>();
			q.add(0);
			while (!q.isEmpty()) {
				int node = q.remove();
				if (!visited[node]) {
					visited[node] = true;
					vcnt++;
					if (graph.containsKey(node)) {
						List<Integer> toNodes = graph.get(node);
						for (Integer to : toNodes) {
							q.add(to);
						}
					}
				}
			}
			if (vcnt < N) {
				cnt++;
			}
		}

		System.out.println(cnt);
		sc.close();
	}

}