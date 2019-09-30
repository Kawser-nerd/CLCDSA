import java.util.*;

public class Main {
	
	static Scanner sc = new Scanner(System.in);
	static boolean twoCol;
	static int size;
	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		ArrayList<Integer>[] adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			adj[u].add(v);
			adj[v].add(u);
		}
		int[] col = new int[n];
		long numNonTwoCol = 0;
		long numTwoCol = 0;
		long numSizeOne = 0;
		ArrayList<Integer> sizes = new ArrayList<>();
		ArrayList<Boolean> twoC = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (col[i] == 0) {
				twoCol = true;
				size = 0;
				dfs(i, 1, col, adj);
				sizes.add(size);
				twoC.add(twoCol);
				if (size == 1) {
					numSizeOne++;
				}
				else if (twoCol) {
					numTwoCol++;
				}
				else {
					numNonTwoCol++;
				}
			}
		}
		long ans = 0;
		for (int i = 0; i < sizes.size(); i++) {
			int size = sizes.get(i);
			boolean tc = twoC.get(i);
			if(size == 1) {
				ans += n;
				continue;
			}
			if(tc) {
				ans += numNonTwoCol + numSizeOne * size + 2 * numTwoCol;
			} else {
				ans += numNonTwoCol + numSizeOne * size + numTwoCol;
			}
		}
		System.out.println(ans);

	}
	
	static void dfs(int v, int c, int[] col, ArrayList<Integer>[] adj) {
		col[v] = c;
		size++;
		for (int u : adj[v]) {
			if (col[u] == 0) {
				dfs(u, 3-c, col, adj);
			}
			else if (col[u] != 3-c) {
				twoCol = false;
			}
		}
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.