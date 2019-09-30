import java.io.*;
import java.util.*;

/**
 * @author Iskander Akishev
 */
public class Alphabet {

	private final static String FILE_NAME = "B-small-attempt0";

	private static final int M = 10009;
	private static final int C = 26;


	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
		PrintWriter out = new PrintWriter(new File(FILE_NAME + ".out"));

		int numberOfTests = Integer.parseInt(in.readLine().trim());

		for (int caseNum = 1; caseNum <= numberOfTests; caseNum++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			String[] terms = st.nextToken().trim().split("\\+");
			int k = Integer.parseInt(st.nextToken().trim());

//			int[] f = new int[k + 1];
//			f[0] = 1;
//			for (int d = 1; d <= k; d++) {
//				f[d] = (f[d - 1] * d) % M;
//			}

			int[][] C = new int[k + 1][];
			for (int i = 0; i <= k; i++) {
				C[i] = new int[i + 1];
				C[i][0] = C[i][i] = 1;
				for (int j = 1; j < i; j++)
					C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
			}


			int m = terms.length;
			int n = Integer.parseInt(in.readLine().trim());
			int[][] words = new int[n][26];
			for (int i = 0; i < n; i++) {
				String wordStr = in.readLine().trim();
				for (char c : wordStr.toCharArray()) {
					words[i][c - 'a']++;
				}
//				for (int j = 0; j < m; j++) {
//					int vv = 1;
//					for (char c : terms[j].toCharArray()) {
//						vv *= [c - 'a'];
//						vv %= M;
//					}
//					v[j][i] = vv;
//				}
			}

			

			int[][] ans = new int[m][k + 1];
			for (int j = 0; j < m; j++) {
				char[] termChars = terms[j].toCharArray();
				long[] v = new long[n];
				for (int i = 0; i < n; i++) {
					for (char c : termChars) {
						v[i] <<= 16;
						v[i] |= words[i][c - 'a'];
					}
				}

				HashMap<Long, Integer>[] map = new HashMap[k + 1];
				for (int d = 0; d <= k; d++) {
					map[d] = new HashMap<Long, Integer>();
				}
				map[0].put(0L, 1);
				for (int i = 0; i < n; i++) {
					for (int d = k - 1; d >= 0; d--) {
						for (Map.Entry<Long, Integer> e : map[d].entrySet()) {
							for (int dd = d + 1; dd <= k; dd++) {
								long v2 = e.getKey() + (v[i] * (dd - d));
								Integer a2I = map[dd].get(v2);
								int a2 = ((a2I == null) ? 0 : a2I);
								a2 += (e.getValue() * C[dd][d]);
								a2 %= M;
								map[dd].put(v2, a2);
							}
						}
					}
				}
				for (int d = 1; d <= k; d++) {
					for (Map.Entry<Long, Integer> e : map[d].entrySet()) {
						long mask = e.getKey();
						
						int x = 1;
						for (int i = 0; i < termChars.length; i++) {
							int y = (int) mask & ((1 << 16) - 1);
							x *= y;
							x %= M;
							mask >>= 16;
						}
						if (mask != 0) throw new AssertionError();

						x *= e.getValue();
						ans[j][d] += x;
						ans[j][d] %= M;
					}
				}
			}


			System.out.println(caseNum);
			out.print("Case #" + caseNum + ":");
			for (int d = 1; d <= k; d++) {
				int sumAns = 0;
				for (int j = 0; j < m; j++) {
					sumAns += ans[j][d];
					sumAns %= M;
				}
				
//				for (int z = 1; z <= d; z++) {
//					sumAns *= z;
//					sumAns %= M;
//				}

				out.print(" " + sumAns);
			}
			out.println();
		}

		in.close();
		out.close();
	}
}