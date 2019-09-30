import java.util.*;
import java.util.stream.*;

public class Main {
	public static final long MOD = 1_000_000_007L;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), 
			a = in.nextInt() - 1, b = in.nextInt() - 1,
			m = in.nextInt();
		List<Integer>[] edges = new List[n];
		for(int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int x = in.nextInt() - 1, y = in.nextInt() - 1;
			edges[x].add(y);
			edges[y].add(x);
		}
		int[] costs = new int[n];
		Arrays.fill(costs, Integer.MAX_VALUE);
		Deque<Pair> que = new ArrayDeque<>();
		que.addLast(new Pair(a, 0));
		while(!que.isEmpty()) {
			Pair p = que.pop();
			if(costs[p.to] <= p.cost) {
				continue;
			}
			costs[p.to] = p.cost;
			for(int to : edges[p.to]) {
				que.addLast(new Pair(to, p.cost + 1));
			}
		}
		for(int i = 0; i < n; i++) {
			List<Integer> list = new ArrayList<>();
			list.addAll(edges[i]);
			edges[i].clear();
			final int cost = costs[i] + 1;
			edges[i].addAll(list.stream().filter(to -> costs[to] == cost).collect(Collectors.toList()));
		}
		Deque<Integer> que2 = new ArrayDeque<>();
		long[] counts = new long[n];
		counts[a] = 1;
		que2.addLast(a);
		while(!que2.isEmpty()) {
			int x = que2.pop();
			for(int to : edges[x]) {
				if(counts[to] == 0) {
					que2.addLast(to);
				}
				counts[to] = counts[to] == 0 ? counts[x] : (counts[to] + counts[x]) % MOD;
			}
		}
		System.out.println(counts[b]);
	}
}

class Pair {
	int to, cost;
	public Pair(int to, int cost) {
		this.to = to; this.cost = cost;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.