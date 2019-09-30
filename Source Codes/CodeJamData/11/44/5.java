import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		Thread thread = new Thread(new Main());
		thread.start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (int) (st.nval);
	}

	long nextLong(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (long) (st.nval);
	}

	BigInteger nextBI(StreamTokenizer st) throws IOException {
		st.nextToken();
		return new BigInteger(st.sval);
	}

	String nextString(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.sval;
	}

	double nextDouble(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.nval;
	}

	Map<Long, double[]> res = new HashMap<Long, double[]>();

	public void run1() throws IOException {
		InputStream inputStream = new FileInputStream("input.txt");
		// InputStream inputStream = System.in;
		Scanner sc = new Scanner(new InputStreamReader(inputStream));
		// StreamTokenizer st = new StreamTokenizer(inputStream);
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(inputStream));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		case_cycle: for (int tn = 1; tn <= tN; tn++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			boolean[][] arr = new boolean[n][n];
			for (int i = 0; i < m; i++) {
				String[] s = sc.next().split(",");
				int a = Integer.parseInt(s[0]);
				int b = Integer.parseInt(s[1]);
				arr[a][b] = arr[b][a] = true;
			}
			int[] dist = new int[n];
			boolean[] was = new boolean[n];
			Arrays.fill(dist, 10000000);
			dist[0] = 0;
			for (int k = 1; k < n; k++) {
				int best = -1;
				for (int i = 0; i < n; i++) {
					if (!was[i] && (best == -1 || dist[best] > dist[i])) {
						best = i;
					}
				}
				if (best == -1)
					break;
				was[best] = true;
				for (int i = 0; i < n; i++) {
					if (arr[i][best])
						dist[i] = Math.min(dist[i], dist[best] + 1);
				}
			}
			if (dist[1] == 1) {
				int r = 0;
				for (int j = 1; j < n; j++) {
					if (arr[0][j])
						r++;
				}
				pw.format("Case #%d: 0 %d\n", tn, r);
				continue case_cycle;
			}
			int[][] res = new int[n][n];
			for (int[] a : res) {
				Arrays.fill(a, -1);
			}
			for (int i = 0; i < n; i++) {
				if (dist[i] == 1) {
					res[0][i] = 0;
					for (int j = 0; j < n; j++) {
						if (j != 0 && j != i && (arr[0][j] || arr[i][j]))
							res[0][i]++;
					}
				}
			}
			for (int d = 2; d < dist[1]; d++) {
				for (int u = 0; u < n; u++) {
					if (dist[u] == d) {
						for (int v = 0; v < n; v++) {
							if (dist[v] == d - 1 && arr[u][v]) {
								res[v][u] = 0;
								for (int prev = 0; prev < n; prev++)
									if (dist[prev] == d - 2) {
										int tmp = res[prev][v];
										for (int i = 0; i < n; i++) {
											if (arr[i][u] && !arr[i][v]
													&& !arr[i][prev])
												tmp++;
										}
										tmp--;
										res[v][u] = Math.max(res[v][u], tmp);
									}
							}
						}
					}
				}
			}
			int re = 0;
			for (int i = 0; i < n; i++) {
				if (dist[i] == dist[1] - 1 && arr[i][1]) {
					for (int j = 0; j < n; j++) {
						re = Math.max(re, res[j][i]);
					}
				}
			}
			pw.format("Case #%d: %d %d\n", tn, dist[1] - 1, re);
		}
		pw.close();
	}

	private class SumHolder {
		int[][] arr;
		int n;
		int[][] first;
		int[][] second;

		SumHolder(int[][] arr1) {
			arr = arr1;
			int r = arr1.length;
			int c = arr1[0].length;
			first = new int[r + 1][c];
			second = new int[r + 1][c + 1];
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++) {
					first[i + 1][j] = first[i][j] + arr[i][j];
				}
			for (int i = 0; i <= r; i++)
				for (int j = 0; j < c; j++) {
					second[i][j + 1] = second[i][j] + first[i][j];
					// System.out.println(i + " " + j + " " + second[i][j]);
				}
		}

		int get(int l1, int r1, int l2, int r2) {
			return second[r1][r2] + second[l1][l2] - second[l1][r2]
					- second[r1][l2];
		}
	}
}
