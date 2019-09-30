import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	static List<Integer>[] adj;
	static int[] parent;
	static int[] level, realLevel;
	static int diameter;
	static int N;
	
	static int[] makeRooted(int node) {
		parent = new int[N];
		parent[node] = -1;
		vis(node);
		return parent;
	}
	
	static void vis(int node) {
		for (int vec : adj[node]) {
			if (vec != parent[node]) {
				parent[vec] = node;
				vis(vec);
			}
		}
	}
	
	static void calcLevels(int node) {
		level[node] = 0;
		for (int vec : adj[node]) {
			if (vec != parent[node]) {
				parent[vec] = node;
				calcLevels(vec);
				level[node] = Math.max(level[node], 1 + level[vec]);
			}
		}
	}
	
	static int calcDiam(int node) {
		int ret = 0;
		int[] maxs = new int[2];
		for (int vec : adj[node]) {
			if (vec != parent[node]) {
				ret = Math.max(ret, calcDiam(vec));
				if (1 + level[vec] > maxs[0]) {
					maxs[1] = maxs[0];
					maxs[0] = 1 + level[vec];
				} else if (1 + level[vec] > maxs[1]) {
					maxs[1] = 1 + level[vec];
				}
			}
		}
		ret = Math.max(ret, maxs[0] + maxs[1]);
		return ret;
	}
	
	static boolean okTree(int root) {
		int max = (diameter + 1) / 2;
		return level[root] <= max;
	}
	
	static void calcRealLevels(int node, int lev) {
		realLevel[node] = lev;
		for (int vec : adj[node]) {
			if (vec != parent[node]) {
				calcRealLevels(vec, lev + 1);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		N = sc.nextInt();
		adj = new List[N];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < N - 1; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		parent = new int[N];
		level = new int[N];
		realLevel = new int[N];
		for (int i = 0; i < N; i++) {
			makeRooted(i);
			calcLevels(i);
			if (i == 0) {
				diameter = calcDiam(i);
//				System.err.println(Arrays.toString(level));
//				System.err.println("diam " + diameter);
			}
			if (okTree(i)) {
				int colors = (diameter + 2) / 2;
				calcRealLevels(i, 0);
				if (diameter % 2 == 1) {
					for (int vec : adj[i]) {
						if (vec != parent[i] && level[vec] == colors - 1) {
							calcRealLevels(vec, 0);
						}
					}
				}
				long ans = 1, ans2;
				for (int j = 0; j + 1 < colors; j++) {
					long max = 0;
					for (int k = 0; k < N; k++) if (realLevel[k] == j ) {
						max = Math.max(max, adj[k].size() - 1 + (k == i && diameter % 2 == 0 ? 1 : 0));
					}
					ans *= max;
				}
				if (diameter % 2 == 1) ans *= 2;
				if (diameter % 2 == 0) {
					diameter++;
					for (int vec : adj[i]) {
						if (vec != parent[i]) {
							calcRealLevels(vec, 0);
							ans2 = 1;
							for (int j = 0; j + 1 < colors; j++) {
								long max = 0;
								for (int k = 0; k < N; k++) if (realLevel[k] == j ) {
									max = Math.max(max, adj[k].size() - 1 + (k == i && diameter % 2 == 0 ? 1 : 0));
								}
								ans2 *= max;
							}
							ans2 *= 2;
							ans = Math.min(ans, ans2);
							calcRealLevels(vec, 1);
						}
					}
				}
				System.out.println(colors + " " + ans);
				break;
			}
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.