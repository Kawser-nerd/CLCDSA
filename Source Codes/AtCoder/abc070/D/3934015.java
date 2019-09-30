import java.util.*;

public class Main {
	static ArrayList<Route>[] lists;
	static long[] costs; // K?????
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		lists = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			lists[i] = new ArrayList<Route>();
		}
		for (int i = 1; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			lists[a].add(new Route(b, c));
			lists[b].add(new Route(a, c));
		}
		costs = new long[n + 1];
		Arrays.fill(costs, -1);
		int q = sc.nextInt();
		int k = sc.nextInt();
		setCost(0, k);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < q; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			sb.append(costs[x] + costs[y]).append("\n");
		}
		System.out.print(sb);
	}
	
	static void setCost(long total, int idx) {
		if (costs[idx] == -1) {
			costs[idx] = total;
			for (Route r : lists[idx]) {
				setCost(total + r.cost, r.point);
			}
		}
	}
	
	static class Route {
		public int point;
		public long cost;
		
		public Route(int point, long cost) {
			this.point = point;
			this.cost = cost;
		}
	}
	
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.