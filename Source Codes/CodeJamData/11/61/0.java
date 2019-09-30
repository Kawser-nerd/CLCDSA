// to be run with -Xmx1024m

import java.util.*;
import java.io.*;

public class ProblemA {
	final long MOD = 1000003;
	final int MAX_LEN = 500000;
	
	final int MAX_RUNS = 100;
	
	long pow(long x, long y) {
		if (y == 0)	return 1;
		long res = pow(x, y/2);
		res = (res * res) % MOD;
		if (y % 2 == 1) res = (res * x) % MOD;
		return res;
	}
	
	long inv(long x) {
		return pow(x, MOD-2);
	}
	
	long[] fact, invfact;
	
	long[][][][] waysPrecalc;
	
	void precalc() {
		System.out.println("run precalc");

		fact = new long[MAX_LEN + 1];
		fact[0] = 1;
		for (int i=1; i<=MAX_LEN; i++)
			fact[i] = (i * fact[i-1]) % MOD;
		invfact = new long[MAX_LEN + 1];
		invfact[0] = 1;
		for (int i=1; i<=MAX_LEN; i++)
			invfact[i] = (inv(i) * invfact[i-1]) % MOD;
		
		int runs = MAX_RUNS;
		waysPrecalc = new long[runs + 1][runs + 2][runs + 1][runs + 2];
		for (int curRuns = 0; curRuns <= runs; curRuns++)
			for (int badPos = 0; badPos <= curRuns+1; badPos++) {
				int goodPos = curRuns + 1 - badPos;
				for (int newRuns = 1; curRuns + newRuns <= runs; newRuns++) {
					for (int parts=1; parts <= newRuns && parts <= curRuns + 1; parts++) {
						for (int badParts = 0; badParts <= parts && badParts <= badPos; badParts++) {
							int goodParts = parts - badParts;
							if (goodParts > goodPos) continue;
							
							long ways1 = comb(newRuns - 1, parts - 1);
							long ways2 = comb(badPos, badParts);
							long ways3 = comb(goodPos, goodParts);
							
							long ways = (ways1 * ways2 * ways3) % MOD;
							
							int newBadPos = badPos - badParts + newRuns - parts;
							
							waysPrecalc[curRuns][badPos][newRuns][newBadPos] = (waysPrecalc[curRuns][badPos][newRuns][newBadPos] + ways) % MOD; 
						}
					}
				}
			}
	}
	
	long comb(int N, int M) {
		long res = fact[N];
		res = (res * invfact[M]) % MOD;
		res = (res * invfact[N-M]) % MOD;
		return res;
	}
	
	class Testcase {
		long ans;
		
		public Testcase() {	
		}
		
		public Testcase(int seed) {
			Random rnd = new Random(seed);
		}
		
		String s;
		
		public void loadInput(Scanner sc) {
			s = sc.next();
		}
		
		public void solveSlow() {
		}
		
		public void solveFast() {
			int[] cnt = new int[26];
			int runs = 0;
			for (int i=0; i < s.length(); i++)
				cnt[s.charAt(i) - 'a']++;
			for (int i=0; i < s.length(); i++)
				if (i == 0 || s.charAt(i) != s.charAt(i-1))
					runs++;
						
			long[][][] F = new long[27][runs + 1][runs + 2];
			F[0][0][0] = 1; 
			
			for (int pos = 0; pos < 26; pos++) {
				System.out.println("pos = " + pos);
				for (int curRuns = 0; curRuns <= runs; curRuns++) {
					for (int badPos = 0; badPos <= curRuns+1; badPos++) {
						if (F[pos][curRuns][badPos] == 0) continue;
						if (cnt[pos] == 0) {
							F[pos + 1][curRuns][badPos] = F[pos][curRuns][badPos];
							continue;
						}
						for (int newRuns = 1; curRuns + newRuns <= runs; newRuns++) {
							if (newRuns > cnt[pos]) continue;
							long splitWays = comb(cnt[pos]-1, newRuns-1);
							for (int newBadPos = 0; newBadPos <= curRuns + newRuns + 1; newBadPos++) {
								long w = waysPrecalc[curRuns][badPos][newRuns][newBadPos];
								if (w == 0) continue;
								F[pos + 1][curRuns + newRuns][newBadPos] = (F[pos + 1][curRuns + newRuns][newBadPos] + F[pos][curRuns][badPos] * w * splitWays) % MOD;
							}
							
//							for (int parts=1; parts <= newRuns && parts <= curRuns + 1; parts++) {
//								for (int badParts = 0; badParts <= parts && badParts <= badPos; badParts++) {
//									int goodParts = parts - badParts;
//									if (goodParts > goodPos) continue;
//									
//									long ways1 = comb(newRuns - 1, parts - 1);
//									long ways2 = comb(badPos, badParts);
//									long ways3 = comb(goodPos, goodParts);
//									
//									long ways = (ways1 * ways2 * ways3) % MOD;
//									
//									int newBadPos = badPos - badParts + newRuns - parts;
//									
//									F[pos + 1][curRuns + newRuns][newBadPos] = (F[pos + 1][curRuns + newRuns][newBadPos] + F[pos][curRuns][badPos] * ways * splitWays) % MOD; 
//								}
//							}
						}
					}
				}
			}
			
			ans = F[26][runs][0];
		}
		
		public void printSelf(PrintWriter pw) {
			pw.println(ans);
		}
		
		public boolean sameAnswers(Testcase other) {
			return false;
		}
	}
	
	final String AFTER_CASE = " ";
	
	public void go() throws Exception {
		precalc();
		
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("solving case " + caseNum);
			
			Testcase tc = new Testcase();
			
			tc.loadInput(sc);
			tc.solveFast();
			
			pw.print("Case #" + (caseNum + 1) + ":");
			pw.print(AFTER_CASE);
			
			tc.printSelf(pw);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public void stresstest() {
		int it = 0;
		Random rnd = new Random();
		while (true) {
			it++;
			if (it % 1000 == 0)
				System.out.println(it + " iterations");
			
			int seed = rnd.nextInt();
			
			Testcase tc1 = new Testcase(seed);
			tc1.solveFast();
			
			Testcase tc2 = new Testcase(seed);
			tc2.solveSlow();
			
			if (!tc1.sameAnswers(tc2)) {
				System.out.println("ERROR: it failed");
				System.exit(0);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		new ProblemA().go();
	}
}
