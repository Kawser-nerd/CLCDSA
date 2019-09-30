import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	final static PrintStream so = System.out;
	final static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();

		int[][] g = new int[n][n];
		for (int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			g[u][v] = 1;
			g[v][u] = 1;
		}

		boolean[] visited = new boolean[n];

		int count = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i])	continue;

			Deque<Integer> deq = new ArrayDeque<>();
			Set<Integer> tree  = new HashSet<>();

			deq.push(i);
			tree.add(i);

			boolean hasCircle = false;
			while (!deq.isEmpty()) {
				int current = deq.pop();
				visited[current] = true;
				
				for (int j = 0; j < n; j++) {
					if (visited[j]) continue;
					
					if (g[current][j] == 1) {
						if (tree.contains(j)) hasCircle = true;
						deq.push(j);
						tree.add(j);
					}
				}
			}
			
			if (!hasCircle) count++;
		}
		System.out.println(count);
	}
}