import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemA {
	final int INF = 1000000000;
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int M = sc.nextInt(), V = sc.nextInt();
			int[] G = new int[M+1], C = new int[M+1], I = new int[M+1];
			for (int i=1; i<=M; i++)
				if (2*i <= M) {
					G[i] = sc.nextInt();
					C[i] = sc.nextInt();
				} else {
					I[i] = sc.nextInt();
				}
			int[][] F = new int[M+1][2];
			for (int i=M; i>=1; i--)
				if (2*i <= M) {
					F[i][0] = INF;
					F[i][1] = INF;
					// and gate
					if (G[i] == 1) {
						F[i][0] = Math.min(F[2*i][0]+F[2*i+1][0], F[i][0]);
						F[i][0] = Math.min(F[2*i][0]+F[2*i+1][1], F[i][0]);
						F[i][0] = Math.min(F[2*i][1]+F[2*i+1][0], F[i][0]);
						F[i][1] = Math.min(F[2*i][1]+F[2*i+1][1], F[i][1]);
						if (C[i] == 1) {
							F[i][0] = Math.min(F[2*i][0]+F[2*i+1][0]+1, F[i][0]);
							F[i][1] = Math.min(F[2*i][0]+F[2*i+1][1]+1, F[i][1]);
							F[i][1] = Math.min(F[2*i][1]+F[2*i+1][0]+1, F[i][1]);
							F[i][1] = Math.min(F[2*i][1]+F[2*i+1][1]+1, F[i][1]);
						}
					} else
					// or gate
					{
						F[i][0] = Math.min(F[2*i][0]+F[2*i+1][0], F[i][0]);
						F[i][1] = Math.min(F[2*i][0]+F[2*i+1][1], F[i][1]);
						F[i][1] = Math.min(F[2*i][1]+F[2*i+1][0], F[i][1]);
						F[i][1] = Math.min(F[2*i][1]+F[2*i+1][1], F[i][1]);
						if (C[i] == 1) {
							F[i][0] = Math.min(F[2*i][0]+F[2*i+1][0]+1, F[i][0]);
							F[i][0] = Math.min(F[2*i][0]+F[2*i+1][1]+1, F[i][0]);
							F[i][0] = Math.min(F[2*i][1]+F[2*i+1][0]+1, F[i][0]);
							F[i][1] = Math.min(F[2*i][1]+F[2*i+1][1]+1, F[i][1]);
						}
					}
				} else {
					F[i][I[i]] = 0;
					F[i][1-I[i]] = INF;
				}
			if (F[1][V] >= INF) pw.println("IMPOSSIBLE");
			else pw.println(F[1][V]);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemA()).doMain();
	}
}
