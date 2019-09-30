import java.util.*;
import java.io.*;

public class Solution {
	long[][] partial(long[][] A) {
		int N = A.length;
		int M = A[0].length;
		long[][] res = new long[N][M];
		for (int i=0; i < N; i++)
			for (int j=0; j < M; j++) {
				res[i][j] = A[i][j];
				if (i > 0) res[i][j] += res[i-1][j];
				if (j > 0) res[i][j] += res[i][j-1];
				if (i > 0 && j > 0) res[i][j] -= res[i-1][j-1];
			}
		return res;
	}
	
	long findSum(int lx, int ly, int rx, int ry, long[][] A, long[][] sum) {
		long res = sum[rx][ry];
		if (lx > 0) res -= sum[lx-1][ry];
		if (ly > 0) res -= sum[rx][ly-1];
		if (lx > 0 && ly > 0) res += sum[lx-1][ly-1];
		
		res -= A[lx][ly];
		res -= A[lx][ry];
		res -= A[rx][ly];
		res -= A[rx][ry];
		
		return res;
	}
	
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			int R = sc.nextInt();
			int C = sc.nextInt();
			int D = sc.nextInt();
			String[] map = new String[R];
			for (int i=0; i < R; i++)
				map[i] = sc.next();
			
			long[][] m = new long[R][C];
			long[][] mx = new long[R][C];
			long[][] my = new long[R][C];
			
			for (int i=0; i < R; i++)
				for (int j=0; j < C; j++) {
					m[i][j] = D + map[i].charAt(j) - '0';
					mx[i][j] = m[i][j] * i;
					my[i][j] = m[i][j] * j;
				}
			
			long[][] sm = partial(m);
			long[][] smx = partial(mx);
			long[][] smy = partial(my);
			
			int res = 0;
			
			for (int sz=3; sz <= Math.min(R, C); sz++)
				for (int x=0; x + sz <= R; x++)
					for (int y=0; y + sz <= C; y++) {
						long sumM = findSum(x, y, x + sz - 1, y + sz - 1, m, sm);
						long sumMx = findSum(x, y, x + sz - 1, y + sz - 1, mx, smx);
						long sumMy = findSum(x, y, x + sz - 1, y + sz - 1, my, smy);
						
						if (2 * sumMx == (x + (x + sz - 1)) * sumM &&
							2 * sumMy == (y + (y + sz - 1)) * sumM)
							res = Math.max(res, sz);
					}
			
			pw.println("Case #" + caseNum + ": " + (res == 0 ? "IMPOSSIBLE" : res));
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).go();
	}
}
