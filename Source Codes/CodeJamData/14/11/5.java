import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class ProblemA {

	static final String IMP = "NOT POSSIBLE";
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int N = in.nextInt();
			int L = in.nextInt();
			char[][] flow = new char[N][];
			for (int i = 0 ; i < N ; i++) {
				flow[i] = in.next().toCharArray();
			}
			char[][] req = new char[N][];
			for (int i = 0 ; i < N ; i++) {
				req[i] = in.next().toCharArray();
			}
			out.println(String.format("Case #%d: %s", cn, solve(flow, req)));
		}
		out.flush();
	}
	
	private static String solve(char[][] flow, char[][] req) {
		int N = flow.length;
		int L = flow[0].length;
		int minimumFlip = Integer.MAX_VALUE;
		for (int i = 0 ; i < N ; i++) {
			for (int j = 0 ; j < N ; j++) {
				boolean[] needFlip = change(flow[i], req[j]);
				if (candoit(flow, req, needFlip)) {
					int fliped = 0;
					for (int k = 0 ; k < L ; k++) {
						if (needFlip[k]) {
							fliped++;
						}
					}
					minimumFlip = Math.min(minimumFlip, fliped);
				}
			}
		}
		return (minimumFlip == Integer.MAX_VALUE) ? IMP : String.format("%d", minimumFlip);
	}


	private static boolean candoit(char[][] flow, char[][] req, boolean[] needFlip) {
		int N = flow.length;
		int L = needFlip.length;
		Set<String> flows = new HashSet<String>();
		for (int i = 0 ; i < N ; i++) {
			StringBuilder gainFlow = new StringBuilder(); 
			for (int j = 0 ; j < L ; j++) {
				if (needFlip[j]) {
					gainFlow.append((flow[i][j] == '1') ? '0' : '1');
				} else {
					gainFlow.append(flow[i][j]);
				}
			}
			flows.add(gainFlow.toString());
		}
		
		
		Set<String> reqs = new HashSet<String>();
		for (int i = 0 ; i < N ; i++) {
			reqs.add(String.valueOf(req[i]));
		}

		for (String f : flows) {
			if (reqs.contains(f)) {
				reqs.remove(f);
			}
		}
		return reqs.size() == 0;
	}


	private static boolean[] change(char[] flow, char[] req) {
		int L = flow.length;
		boolean[] change = new boolean[L];
		for (int i = 0 ; i < L ; i++) {
			if (flow[i] != req[i]) {
				change[i] = true;
			}
		}
		return change;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
