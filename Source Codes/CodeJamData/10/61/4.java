import java.util.*;
import java.io.*;
import java.math.*;

public class SolveEasy {
	Scanner sc;
	PrintWriter pw;
	int caseCnt, caseNum;
	
	int[] c;
	
	void inputData() throws Exception  {
		String s = sc.next();
		c = new int[s.length()];
		for (int i=0; i<s.length(); i++)
			c[i] = s.charAt(i)-'A';
	}
	
	int res;
	
	void solveProblem() {
		int N = c.length;
		
		int[][][] dp = new int[N][N][3];
		int[][] memo = new int[N][N];
		
		for (int i=0; i < N; i++) {
			int j = i;
			for (int col=0; col<3; col++) {
				dp[i][j][col] = c[i] == col ? 0 : 1;				
			}
			
			memo[i][j] = 1;
		}
		
		for (int l=2; l<=N; l++) {
			for (int i=0; i + l <= N; i++) {
				int j = i + l - 1;
				
				memo[i][j] = 1000000;
				
				for (int col=0; col<3; col++) {
					dp[i][j][col] = 1000000;
					if (c[i] == col) dp[i][j][col] = Math.min(dp[i][j][col], dp[i+1][j][col]);
					for (int k=i; k < j; k++)
						dp[i][j][col] = Math.min(dp[i][j][col], memo[i][k] + dp[k+1][j][col]);
				}
				
				memo[i][j] = Math.min(dp[i][j][0], dp[i][j][1]);
				memo[i][j] = Math.min(memo[i][j], dp[i][j][2]);
				memo[i][j]++;
			}
		}
		
		res = memo[0][N-1] * 2 + N;
	}
	
	void outputData() {
		pw.print("Case #" + caseNum + ": ");
		
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