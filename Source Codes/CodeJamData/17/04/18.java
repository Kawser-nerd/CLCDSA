import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class d {
	public static void main(String[] Args) throws Exception {
		// Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(new File("d.out"))));
		// PrintWriter out = new PrintWriter(System.out);

		// Board stuff
		HashMap<String, Integer> hm = new HashMap<String, Integer>();
		hm.put(".", 0);
		hm.put("+", 1);
		hm.put("x", 2);
		hm.put("o", 3);
		String[] type2 = { ".", "+", "x", "o" };
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			// Read header
			int n = sc.nextInt();
			int ps = sc.nextInt();

			// Read the board
			int[][] board = new int[n][n];
			int[][] oBoard = new int[n][n];
			boolean[] row = new boolean[n];
			boolean[] col = new boolean[n];

			for (int i = 0; i < ps; i++) {
				int type = hm.get(sc.next().trim());
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				board[a][b] = type;
				oBoard[a][b] = type;
				if ((board[a][b] & 2) != 0) {
					row[a] = true;
					col[b] = true;
				}
			}

			// Handle the x's
			for (int i = 0; i < n; i++) {
				for (int j = 0; !row[i] && j < n; j++) {
					if (!col[j]) {
						col[j] = true;
						row[i] = true;
						board[i][j] |= 2;
					}
				}
			}

			// Handle the +'s using flow
			int numDiag = n * 2 - 1;
			int[] diags1 = new int[n * n];
			int[] diags2 = new int[n * n];
			TidalFlow tf = new TidalFlow(numDiag * 2);
			for (int i = 0; i < numDiag; i++) {
				boolean good = true;
				for (int j = 0; j + i - n + 1 < n && j < n; j++) {
					if (j + i - n + 1 >= 0 && (board[j][j + i - n + 1] & 1) != 0) {
						good = false;
					}
					if (j + i - n + 1 >= 0) {
						diags1[j * n + (j + i - n + 1)] = i;
					}
				}
				if (good)
					tf.add(tf.s, i, 1);
			}
			for (int i = 0; i < numDiag; i++) {
				boolean good = true;
				for (int j = 0; i - j >= 0 && j < n; j++) {
					int k = i - j;
					if (k < n && (board[j][k] & 1) != 0) {
						good = false;
					}
					if (k < n) {
						diags2[j * n + (k)] = i;
					}
				}
				if (good)
					tf.add(numDiag + i, tf.t, 1);
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					tf.add(diags1[i * n + j], numDiag + diags2[i * n + j], 1);
				}
			}
			int num = tf.getFlow();

			// Update the board
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (Edge e : tf.adjj[diags1[i * n + j]]) {
						if (e.j - numDiag == diags2[i * n + j]) {
							if (e.flow == 1)
								board[i][j] |= 1;
							break;
						}
					}
				}
			}

			// Compute the score
			int ans = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					ans += (board[i][j] + 1) / 2;
				}

			// Compute the changes
			int changes = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (board[i][j] != oBoard[i][j])
						changes++;

			// Print
			out.printf("Case #%d: %d %d%n", ++cc, ans, changes);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (board[i][j] != oBoard[i][j])
						out.printf("%s %d %d%n", type2[board[i][j]], i + 1, j + 1);
		}
		out.close();
	}

	public static class TidalFlow {
		ArrayDeque<Edge> stk = new ArrayDeque<Edge>();
		int N, fptr, bptr, s, t, oo = 987654321;
		ArrayList<Edge>[] adjj;
		Edge[][] adj;
		int[] q, dist, pool;

		TidalFlow(int NN) {
			N = (t = (s = NN) + 1) + 1;
			adjj = new ArrayList[N];
			for (int i = 0; i < N; i++)
				adjj[i] = new ArrayList<Edge>();
			adj = new Edge[N][0];
			dist = new int[N];
			pool = new int[N];
			q = new int[N];
		}

		void add(int i, int j, int cap) {
			Edge fwd = new Edge(i, j, cap, 0);
			Edge rev = new Edge(j, i, 0, 0); // for bidirectional, set -cap
			adjj[i].add(rev.rev = fwd);
			adjj[j].add(fwd.rev = rev);
		}

		int augment() {
			Arrays.fill(dist, Integer.MAX_VALUE);
			pool[t] = dist[s] = fptr = bptr = 0;
			pool[q[bptr++] = s] = oo;
			while (bptr > fptr && q[fptr] != t)
				for (Edge e : adj[q[fptr++]]) {
					if (dist[e.i] < dist[e.j])
						pool[e.j] += e.carry = Math.min(e.cap - e.flow, pool[e.i]);
					if (dist[e.i] + 1 < dist[e.j] && e.cap > e.flow)
						dist[q[bptr++] = e.j] = dist[e.i] + 1;
				}
			if (pool[t] == 0)
				return 0;
			Arrays.fill(pool, fptr = bptr = 0);
			pool[q[bptr++] = t] = oo;
			while (bptr > fptr)
				for (Edge e : adj[q[fptr++]]) {
					if (pool[e.i] == 0)
						break;
					int f = e.rev.carry = Math.min(pool[e.i], e.rev.carry);
					if (dist[e.i] > dist[e.j] && f != 0) {
						if (pool[e.j] == 0)
							q[bptr++] = e.j;
						pool[e.i] -= f;
						pool[e.j] += f;
						stk.push(e.rev);
					}
				}
			int res = pool[s];
			Arrays.fill(pool, 0);
			pool[s] = res;
			while (stk.size() > 0) {
				Edge e = stk.pop();
				int f = Math.min(e.carry, pool[e.i]);
				pool[e.i] -= f;
				pool[e.j] += f;
				e.flow += f;
				e.rev.flow -= f;
			}
			return res;
		}

		int getFlow() {
			int res = 0, f = 1;
			// for(int i=0; i<N; i++) Collections.shuffle(adjj[i]);
			for (int i = 0; i < N; i++)
				adj[i] = adjj[i].toArray(adj[i]);
			while (f != 0)
				res += f = augment();
			return res;
		}

	}

	public static class Edge {
		int i, j, cap, flow, carry;
		Edge rev;

		Edge(int ii, int jj, int cc, int ff) {
			i = ii;
			j = jj;
			cap = cc;
			flow = ff;
		}
	}
}
