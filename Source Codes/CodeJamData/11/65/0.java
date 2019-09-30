import java.util.*;
import java.io.*;

public class ProblemE {
	final int MAX_STEPS = 1000;
	
	class Testcase {
		int A, M, V;
		double ans;
		int start;
		
		public Testcase() {
		}
		
		public Testcase(int seed) {
			Random rnd = new Random(seed);
		}
		
		public void loadInput(Scanner sc) {
			A = sc.nextInt();
			M = sc.nextInt();
			V = sc.nextInt();
		}
		
		double[][] memo;
		
		double solve(int cur, int stepsLeft) {
			if (cur <= 0)
				return 0.0;
			if (cur >= V)
				return 1.0;
			if (stepsLeft == 0)
				return 0.0;
			if (memo[cur][stepsLeft] > -0.5)
				return memo[cur][stepsLeft];
			
			double res = 0.0;
			for (int B=1; B <= Math.min(cur, M); B++) {
				int maxBets = 1;
				int tot = B;
				while (2 * tot <= M) {
					tot *= 2;
					maxBets++;
				}
				for (int play = 1; play <= maxBets; play++) {
					double curPrb = 1.0;
					double tmp = 0.0;
					int lose = 0, bet = B;
					for (int round = 0; round < play; round++) {
						tmp += curPrb * 0.5 * solve(cur + B, stepsLeft - 1);
						curPrb *= 0.5;
						lose += bet;
						bet *= 2;
					}
					tmp += curPrb * solve(cur - lose, stepsLeft - 1);
					res = Math.max(res, tmp);
				}
			}
			
//			System.out.println(cur+" "+stepsLeft+" "+res);
			memo[cur][stepsLeft] = res;
			return res;
		}
		
		public void solveSlow() {
			memo = new double[V][MAX_STEPS + 1];
			for (int i=0; i<V; i++)
				Arrays.fill(memo[i], -1.0);
				
			ans = solve(A, MAX_STEPS);
			
			for (int B=Math.min(A, M); B >= 1; B--) {
				double best = 0.0;
				int maxBets = 1;
				int tot = B;
				while (2 * tot <= M) {
					tot *= 2;
					maxBets++;
				}
				for (int play = 1; play <= maxBets; play++) {
					double curPrb = 1.0;
					double tmp = 0.0;
					int lose = 0, bet = B;
					for (int round = 0; round < play; round++) {
						tmp += curPrb * 0.5 * solve(A + B, MAX_STEPS - 1);
						curPrb *= 0.5;
						lose += bet;
						bet *= 2;
					}
					tmp += curPrb * solve(A - lose, MAX_STEPS - 1);
					best = Math.max(best, tmp);
				}
				if (best >= ans - 1e-12) {
					start = B;
					break;
				}
			}
		}
		
		public void solveFast() {
		}
		
		public void printSelf(PrintWriter pw) {
			pw.println(ans + " " + start);
		}
		
		public boolean sameAnswers(Testcase other) {
			return false;
		}
	}
	
	final String AFTER_CASE = " ";
	
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("solving case " + caseNum);
			
			Testcase tc = new Testcase();
			
			tc.loadInput(sc);
			tc.solveSlow();
			
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
		new ProblemE().go();
	}
}
