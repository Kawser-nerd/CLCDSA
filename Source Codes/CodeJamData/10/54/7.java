import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class D {
	static boolean SAMPLE;
	Scanner sc;
	
	long M = 1000000007;
	
	HashMap<Entry, Long> dp;
	int B;
	
	long dp(int[] used, int k, int N) {
		if (N == 0) return 1;
		Entry e = new Entry(used, k, N);
		if (dp.containsKey(e)) return dp.get(e);
		long res = 0;
		for (int i = k + 1; i <= N; i++) {
			int i2 = i;
			int[] used2 = used.clone();
			boolean ok = true;
			for (int j = 0; i2 > 0; j++) {
				int a = i2 % B;
				i2 /= B;
				if ((used[j] >> a & 1) != 0) ok = false;
				used2[j] |= 1 << a;
			}
			if (ok) res = (res + dp(used2, i, N - i)) % M;
		}
		dp.put(e, res);
		return res;
	}
	
	void solve(int caseID) {
		int N = sc.nextInt();
		B = sc.nextInt();
		dp = new HashMap<Entry, Long>();
		int n = 1, d = 1;
		while (n <= N) {
			n *= B;
			d++;
		}
		System.out.println(dp(new int[d], 0, N));
	}
	
	class Entry {
		int[] is;
		int k, N;
		Entry(int[] is, int k, int N) {
			this.is = is;
			this.k = k;
			this.N = N;
		}
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + k;
			result = prime * result + N;
			result = prime * result + Arrays.hashCode(is);
			return result;
		}
		public boolean equals(Object obj) {
			Entry other = (Entry)obj;
			if (k != other.k) return false;
			if (N != other.N) return false;
			if (!Arrays.equals(is, other.is)) return false;
			return true;
		}
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (!SAMPLE) System.err.printf("%03d/%03d %.3f/%.3f%n", caseID, caseN, t, t / (caseID - 1) * caseN);
			System.out.printf("Case #%d: ", caseID);
			solve(caseID);
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("sample")) {
			try {
				System.setIn(new FileInputStream("D.in"));
				SAMPLE = true;
			} catch (IOException e) {
			}
		}
		new D().run();
	}
}
