import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static int gen = 0;

	static class Vertex {
		List<Vertex> adj = new ArrayList<>();
		long stones;
		int id = gen++;

		public Vertex(long stones) {
			this.stones = stones;
		}

		long dfs(Vertex parent) {
			if (adj.size() == 1)
				return stones;
			long sum = 0;
			long max = 0;
			for (Vertex v : adj) {
				if (v == parent)
					continue;
				long got = v.dfs(this);
				sum += got;
				max = Math.max(max, got);
			}
			long nextPathNum = 2 * stones - sum;
			max = Math.max(max, nextPathNum);
			if (nextPathNum < 0) {
				return -1;
			}
			if (2 * max > 2 * stones) {
				return -1;
			}
			return nextPathNum;
		}
	}

	static int N;
	static int[] a, b;
	static Vertex[] vs;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		vs = new Vertex[N];
		for (int i = 0; i < N; ++i)
			vs[i] = new Vertex(sc.nextInt());
		a = new int[N - 1];
		b = new int[N - 1];
		for (int i = 0; i < N - 1; ++i) {
			Vertex a = vs[sc.nextInt() - 1];
			Vertex b = vs[sc.nextInt() - 1];
			a.adj.add(b);
			b.adj.add(a);
		}

		if (N == 2) {
			if (vs[0].stones == vs[1].stones) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
			return;
		}

		Vertex root = null;
		for (Vertex v : vs) {
			if (v.adj.size() > 1) {
				root = v;
				break;
			}
		}

		long pathNum = root.dfs(null);
		if (pathNum == 0) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}