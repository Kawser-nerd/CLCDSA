import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	int p;
	long[] val;
	long[] cur;

	long[] reduce(long[] cnt, long x) {
		
		int pos = Arrays.binarySearch(val, x);
		if (pos < 0 || cnt[pos] == 0) {
			return null;
		}
		
		cnt = cnt.clone();
		if (x == 0) {
			for (int i = 0; i < cnt.length; i++) {
				if (cnt[i] % 2 != 0) {
					return null;
				}
				cnt[i] /= 2;
			}
			return cnt;
		}
		if (x > 0) {
			for (int i = 0; i < cnt.length; i++) {
				if (cnt[i] == 0) {
					continue;
				}
				int j = Arrays.binarySearch(val, val[i] + x);
				if (j < 0) {
					return null;
				}
				if (cnt[j] < cnt[i]) {
					return null;
				}
				cnt[j] -= cnt[i];
			}
			return cnt;
		}

		for (int i = cnt.length - 1; i >= 0; i--) {
			if (cnt[i] == 0) {
				continue;
			}
			int j = Arrays.binarySearch(val, val[i] + x);
			if (j < 0) {
				return null;
			}
			if (cnt[j] < cnt[i]) {
				return null;
			}
			cnt[j] -= cnt[i];
		}
		return cnt;
	}

	boolean goPositive(long[] cnt, int idx, int n) {
		int zeroPos = -1;
		for (int i = 0; i < cnt.length; i++) {
			if (val[i] == 0) {
				zeroPos = i;
				break;
			}
		}
//		System.err.println(Arrays.toString(val) + " " + zeroPos);
		outer: for (int i = idx; i < n; i++) {
			if (cnt[zeroPos] > 1) {
				cnt = reduce(cnt, 0);
				if (cnt == null) {
					return false;
				}
				cur[i] = 0;
				continue outer;
			}
			for (int j = zeroPos + 1; j < val.length; j++) {
				if (cnt[j] > 0) {
					cnt = reduce(cnt, val[j]);
					if (cnt == null) {
						return false;
					}
					cur[i] = val[j];
					continue outer;
				}
			}
		}
		return true;
	}

	boolean go(long[] cnt, int idx, int n, int least) {
		
//		System.err.println(Arrays.toString(cnt));
		
		while (least < cnt.length && cnt[least] == 0) {
			least++;
		}
		
		if (idx == n) {
			for (int i = 0; i < n; i++) {
				out.print(cur[i] + " ");
			}
			out.println();
			return true;
		}

		if (least == cnt.length) {
			return false;
		}

		if (val[least] >= 0) {
			if (goPositive(cnt, idx, n)) {
				for (int i = 0; i < n; i++) {
					out.print(cur[i] + " ");
				}
				out.println();
				return true;
			}
			return false;
		}
		
//1
//9
//-4 -3 -2 -1 0 1 2 3 4
// 1  2  2  2 2 2 2 2 1

		long[] cnt2 = reduce(cnt, val[least]);
		if (cnt2 != null) {
			cur[idx] = val[least];
			if (go(cnt2, idx + 1, n, least)) {
				return true;
			}
		}

		if (go(cnt, idx, n, least + 1)) {
			return true;
		}

		return false;
	}

	void solve() throws IOException {
		p = nextInt();
		val = new long[p];
		long[] cnt = new long[p];
		long total = 0;
		for (int i = 0; i < p; i++) {
			val[i] = nextLong();
		}
		for (int i = 0; i < p; i++) {
			cnt[i] = nextLong();
			total += cnt[i];
		}

		int n = Long.numberOfTrailingZeros(total);

		cur = new long[n];
		go(cnt, 0, n, 0);
	}

	D() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("D-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("D-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("D-large.in"));
			out = new PrintWriter("D-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}