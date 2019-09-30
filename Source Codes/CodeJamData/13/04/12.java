import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemD {
	static final String IMP = "IMPOSSIBLE";
	
	static class Chest {
		int id;
		int type;
		List<Integer> keys;
		Chest(int i, int t, List<Integer> k) {
			id = i;
			type = t;
			keys = k;
		}
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int K = in.nextInt();
			int N = in.nextInt();
			
			int[] initial = new int[201];
			for (int i = 0 ; i < K ; i++) {
				initial[in.nextInt()]++;
			}
			
			Chest[] c = new Chest[N];
			for (int i = 0 ; i < N ; i++) {
				int t = in.nextInt();
				int k = in.nextInt();
				List<Integer> keys = new ArrayList<Integer>();
				for (int j = 0 ; j < k ; j++) {
					keys.add(in.nextInt());
				}
				c[i] = new Chest(i+1, t, keys);
			}
			out.println(String.format("Case #%d: %s", cn, solve(N, initial, c)));
		}
		out.flush();
	}
	
	private static String solve(int n, int[] initial, Chest[] c) {
		int ptn = (1<<n);
		String[] dp = new String[ptn];
		for (int i = 0 ; i < ptn ; i++) {
			dp[i] = "~";
		}
		dp[0] = "";
		
		
		for (int i = 0 ; i < ptn ; i++) {
			if (dp[i].equals("~")) {
				continue;
			}
			int[] num = initial.clone();
			for (int j = 0 ; j < n ; j++) {
				if ((i & (1<<j)) >= 1) {
					num[c[j].type]--;
					for (int k : c[j].keys) {
						num[k]++;
					}
				}
			}
			
			for (int j = 0 ; j < n ; j++) {
				if ((i & (1<<j)) == 0) {
					int ti = i | (1<<j);
					if (num[c[j].type] >= 1) {
						String toStat = dp[i] + " " + c[j].id;
						if (dp[ti].equals("~")) {
							dp[ti] = toStat;
						} else {
							String[] prv = dp[ti].substring(1).split(" ");
							String[] nxt = toStat.substring(1).split(" ");
							boolean isok = false;
							for (int k = 0 ; k < prv.length ; k++) {
								int pr = Integer.valueOf(prv[k]);
								int nx = Integer.valueOf(nxt[k]);
								if (nx < pr) {
									isok = true;
									break;
								} else if (nx > pr) {
									isok = false;
									break;
								}
							}
							if (isok) {
								dp[ti] = toStat;
							}
						}
					}
				}
			}
		}
		if (dp[ptn-1].equals("~")) {
			return IMP;
		}
		return dp[ptn-1].substring(1);
	}



	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
