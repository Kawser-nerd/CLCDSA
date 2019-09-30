import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	long MOD = 1000000007;
	
	int M, N;
	char[][] S;
	
	void read() {
		M = sc.nextInt();
		N = sc.nextInt();
		S = new char[M][];
		for (int i = 0; i < M; i++) S[i] = sc.next().toCharArray();
	}
	
	long[][] comb;
	
	void solve() {
		comb = new long[1100][1100];
		comb[0][0] = 1;
		for (int i = 1; i < comb.length; i++) {
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
			}
		}
		T t = new T();
		for (int i = 0; i < M; i++) t.add(S[i], 0);
		int[] res = t.rec();
		System.out.printf("%d %d%n", res[0], res[1]);
	}
	
	
	class T {
		boolean has;
		int size;
		T[] ts = new T[26];
		void add(char[] cs, int p) {
			size++;
			if (p < cs.length) {
				int i = cs[p] - 'A';
				if (ts[i] == null) ts[i] = new T();
				ts[i].add(cs, p + 1);
			} else {
				has = true;
			}
		}
		int[] rec() {
			int k = min(size, N);
			int num = k;
			long[] dp = new long[k + 1];
			if (has) dp[1] = k;
			else dp[0] = 1;
			for (int i = 0; i < 26; i++) if (ts[i] != null) {
				int[] tmp = ts[i].rec();
				num += tmp[0];
				int k2 = min(ts[i].size, N);
				long[] dp2 = new long[k + 1];
				for (int j = k2; j <= k; j++) {
					for (int h = max(0, j - k2); h <= j; h++) {
						dp2[j] = (dp2[j] + dp[h] * comb[k - h][j - h] % MOD * comb[h][k2 - (j - h)] % MOD * tmp[1]) % MOD;
					}
				}
				dp = dp2;
			}
			return new int[]{num, (int)dp[k]};
		}
	}
	
	int max;
	long count;
	
	void search(int[] is, int p) {
		if (p == M) {
			int size = 0;
			for (int i = 0; i < N; i++) {
				TreeSet<String> set = new TreeSet<String>();
				for (int j = 0; j < M; j++) if (is[j] == i) {
					for (int k = 0; k < S[j].length; k++) set.add(new String(S[j], 0, k + 1));
				}
				if (set.size() == 0) return;
				size += set.size() + 1;
			}
			if (max < size) {
				max = size;
				count = 1;
			} else if (max == size) {
				count++;
			}
		} else {
			for (int i = 0; i < N; i++) {
				is[p] = i;
				search(is, p + 1);
			}
		}
	}
	
	void solveSmall() {
		max = 0;
		count = 0;
		search(new int[M], 0);
		System.out.printf("%d %d%n", max, count % MOD);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (D.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new D().run();
	}
}
