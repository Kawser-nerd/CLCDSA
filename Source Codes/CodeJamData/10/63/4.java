import java.util.*;
import java.io.*;
import java.math.*;

public class SolveEasy {
	Scanner sc;
	PrintWriter pw;
	int caseCnt, caseNum;

	int numPeople, maxSpent;
	
	void inputData() throws Exception  {
		numPeople = sc.nextInt();
		maxSpent = sc.nextInt();
	}
	
	int res;
	
	void solveProblem() {
		res = 1000;
		
		int[][][] dp = new int[61][31][21];
		for (int A=0; A<=60; A++)
			for (int B=0; B<=30; B++)
				for (int C=0; C<=20; C++) {
					dp[A][B][C] = 1000;
					if (maxSpent >= 1) {
						int best = -1;
						best = Math.max(best, A == 0 ? -1 : dp[A-1][B][C]);
						dp[A][B][C] = Math.min(dp[A][B][C], best + 1);
					}
					if (maxSpent >= 2) {
						int best = -1;
						best = Math.max(best, A < 2 ? -1 : dp[A-2][B][C]);
						best = Math.max(best, B < 1 ? -1 : dp[A][B-1][C]);
						dp[A][B][C] = Math.min(dp[A][B][C], best + 1);
					}
					if (maxSpent >= 3) {
						int best = -1;
						best = Math.max(best, A < 3 ? -1 : dp[A-3][B][C]);
						best = Math.max(best, A < 1 || B < 1 ? -1 : dp[A-1][B-1][C]);						
						best = Math.max(best, C < 1 ? -1 : dp[A][B][C-1]);
						dp[A][B][C] = Math.min(dp[A][B][C], best + 1);
					}
					
					if (dp[A][B][C] >= numPeople && A + B + C < res) {
						res = A + B + C;
					}
				}
	}
	
	void outputData() {
		pw.print("Case #" + caseNum + ": ");
		
		// some code here
		pw.print(res);
		
		pw.println();
	}
	
	public void go() throws Exception {
		sc = new Scanner(new FileReader("input.txt"));
		pw = new PrintWriter(new FileWriter("output.txt"));
		
		caseCnt = sc.nextInt();
		for (caseNum=1; caseNum <= caseCnt; caseNum++) {
			inputData();
			solveProblem();
			outputData();
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new SolveEasy()).go();
	}
}