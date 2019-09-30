import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemD {
	final int INF = -10000000;
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int k = sc.nextInt();
			String s = sc.next();
			int grCnt = s.length() / k;
			int[][] edgeCost = new int[k][k];
			int[][] nextCost = new int[k][k];
			for (int i=0; i < k; i++)
				for (int j=0; j < k ;j++) {
					edgeCost[i][j] = 0;
					nextCost[i][j] = 0;
					for (int t=0; t < grCnt; t++)
						if (s.charAt(t * k + i) == s.charAt(t * k + j))
							edgeCost[i][j]++;
					for (int t=0; t+1 < grCnt; t++)
						if (s.charAt(t * k + i) == s.charAt((t+1) * k + j))
							nextCost[i][j]++;
				}
			int res = 0;
			for (int st=0; st < k; st++) {
				int[][] F = new int[k][1<<k];
				for (int i=0; i < k; i++)
					Arrays.fill(F[i], INF);
				F[st][1<<st] = 0;
				for (int mask=0; mask < (1<<k); mask++)
					for (int cur=0; cur < k; cur++)
						for (int next=0; next < k; next++)
							if ((mask & (1<<next)) == 0)
								F[next][mask | (1<<next)] = Math.max(F[next][mask | (1<<next)], F[cur][mask] + edgeCost[cur][next]);
				for (int fn=0; fn < k; fn++)
					res = Math.max(res, F[fn][(1<<k)-1] + nextCost[fn][st]);
			}
			pw.println(s.length() - res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemD()).doMain();
	}
}