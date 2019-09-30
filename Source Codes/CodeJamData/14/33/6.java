import java.io.*;
import java.math.*;
import java.util.*;

public class Enclosure
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		for(int caseId=1,totalCases=sc.nextInt();caseId<=totalCases;caseId++)
		{
			System.out.println("Case #"+caseId+": "+solve());
			
			//Add logic here
			
			System.out.flush();
		}
	}
	
	static int solve() {
		int N = sc.nextInt(), M = sc.nextInt(), K = sc.nextInt();
		int rows = Math.min(N, M), cols = Math.max(N, M);
		N = rows; M = cols;
		if(N == 1)
			return K;
		
		int best = K;
		for(rows = 2; rows <= N; rows++) {
			for(cols = 2; cols <= M; cols++) {
				int area = rows * cols, perimeter = 2 * (rows + cols - 2);
				if(area < K)
					continue;
				int[][] diag = new int[2][2];
				while(area > K) {
					int bi = -1, bj = -1;
					for(int i=0;i<2;i++) {
						for(int j=0;j<2;j++) {
							if(bi == -1 || diag[i][j] < diag[bi][bj]) {
								bi = i; bj = j;
							}
						}
					}
					diag[bi][bj]++;
					if(area - diag[bi][bj] >= K && valid(diag, rows, cols)) {
						area -= diag[bi][bj];
						perimeter--;
					} else
						break;
				}
				if(perimeter < best) {
					// A.apr(diag);
					// A.spr(rows+","+cols + ":" + area);
				}
				best = Math.min(best, perimeter);
			}
		}
		return best;
	}
	
	static boolean valid(int[][] diag, int rows, int cols) {
		boolean ok = true;
		for(int i=0;i<2;i++) {
			ok &= diag[i][0] + diag[i][1] <= cols;
			ok &= diag[0][i] + diag[1][i] <= rows;
		}
		return ok;
	}
}
