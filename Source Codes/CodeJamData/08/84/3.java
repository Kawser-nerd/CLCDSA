import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemD {
	int[][] mul(int[][] a, int[][] b) {
		int L = a.length;
		long[][] tmp = new long[L][L];
		for (int i=0; i < L; i++)
			for (int j=0; j < L; j++)
				for (int k=0; k < L; k++) {
					tmp[i][k] += a[i][j] * b[j][k];
				}
		int[][] res = new int[L][L];
		for (int i=0; i<L; i++)
			for (int j=0; j<L; j++)
				res[i][j] = (int)(tmp[i][j] % 30031);
		return res;
	}

	int[][] pow(int[][] a, int d) {
		int L = a.length;
		if (d == 0) {
			int[][] res = new int[L][L];
			for (int i=0; i<L; i++)
				for (int j=0; j<L; j++)
					res[i][j] = (i==j?1:0);
			return res;
		}
		int[][] res = pow(a, d/2);
		res = mul(res, res);
		if (d%2==1) res = mul(res, a);
		return res;
	}

	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			pw.print("Case #" + caseNum + ":");
			int N = sc.nextInt();
			int K = sc.nextInt();
			int P = sc.nextInt();
			int sz = 1<<(P-1);
			int[][] mat = new int[sz][sz];
			for (int x=0; x<sz; x++) {
				int mask = 2*x+1;
				for (int i=0; i < P; i++) if ((mask & (1<<i)) != 0) {
					int newMask = mask - (1<<i);
					if (newMask >= (1<<(P-1)))
						newMask -= (1<<(P-1));
					mat[newMask][x] = 1;
				}
			}
			mat = pow(mat, N - K);
			int mask=0;
			for (int i=K-1; i>=0; i--)
				mask+=(1<<i);
			pw.println(" "+mat[mask/2][mask/2]);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemD()).doMain();
	}
}