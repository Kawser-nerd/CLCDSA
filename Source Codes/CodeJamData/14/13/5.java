import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class ProblemC {

	static final int THRESHOLD = 162245;
	
	static final String GOOD = "GOOD";
	static final String BAD = "BAD";
	
	// 244919:9,9
	// 243219:11,20
	
	
	static class ResultSet {
		int idx;
		int rot;
		String answer;
		ResultSet(int i, int r) {
			idx = i;
			rot = r;
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// benchmark();
		
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int T = in.nextInt();
		ResultSet[] rs = new ResultSet[T];
		for (int cn = 1 ; cn <= T ; cn++) {
			int N = in.nextInt();
			int[] a = new int[N];
			for (int i = 0 ; i < N ; i++) {
				a[i] = in.nextInt();
			}
			rs[cn-1] = new ResultSet(cn-1, count(a));
		}
		Arrays.sort(rs, new Comparator<ResultSet>() {
			@Override
			public int compare(ResultSet o1, ResultSet o2) {
				return o1.rot - o2.rot;
			}
		});
		for (int i = 0 ; i < rs.length / 2 ; i++) {
			rs[i].answer = BAD;
		}
		for (int i = rs.length / 2 ; i < rs.length ; i++) {
			rs[i].answer = GOOD;
		}
		Arrays.sort(rs, new Comparator<ResultSet>() {
			@Override
			public int compare(ResultSet o1, ResultSet o2) {
				return o1.idx - o2.idx;
			}
		});
		for (int cn = 1 ; cn <= T ; cn++) {
			out.println(String.format("Case #%d: %s", cn, rs[cn-1].answer));
		}
		out.flush();
	}
	
	
	public static int benchmark() {
		int goodMax = Integer.MIN_VALUE;
		int badMin = Integer.MAX_VALUE;
		int goodMin = Integer.MAX_VALUE;
		int badMax = Integer.MIN_VALUE;
		for (int i = 0 ; i < 1000 ; i++) {
			int g = good();
			int b = bad();
			goodMin = Math.min(goodMin, g);
			badMax = Math.max(badMax, b);
			goodMax = Math.max(goodMax, g);
			badMin = Math.min(badMin, b);
		}
		debug(goodMin,goodMax);
		debug(badMin,badMax);
		debug("th",(goodMin+badMax)/2);
		int th = (goodMin+badMax)/2;
		

		int goodMiss = 0;
		int badMiss = 0;
		for (int i = 0 ; i < 120 ; i++) {
			if (Math.random() < 0.5) {
				if (good() < th) {
					goodMiss++;
				}
			} else {
				if (bad() > th) {
					badMiss++;
				}
			}
		}
		debug(goodMiss,badMiss);
		
		return th;
	}
	
	
	public static int good() {
		int[] a = new int[1000];
		for (int i = 0 ; i < 1000 ; i++) {
			a[i] = i;
		}
		int n = a.length;
		for (int i = 0 ; i < n ; i++) {
			int s = i + (int)(Math.random() * (n-1-i));
			int t = a[i];
			a[i] = a[s];
			a[s] = t;
		}
		return count(a);
	}

	
	public static int bad() {
		int[] a = new int[1000];
		for (int i = 0 ; i < 1000 ; i++) {
			a[i] = i;
		}
		int n = a.length;
		for (int i = 0 ; i < n ; i++) {
			int s = (int)(Math.random() * n);
			int t = a[i];
			a[i] = a[s];
			a[s] = t;
		}
		return count(a);
	}
	
	public static int count(int[] a) {
		int n = a.length;
		int cnt = 0;
		for (int i = 0 ; i < n/2 ; i++) {
			cnt += Math.abs(a[i] - i);
//			for (int j = i+1 ; j < n ; j++) {
//				if (a[i] > a[j]) {
//					cnt++;
//				}
//			}
		}
		return cnt;
	}
	
	
	
	
	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
