import java.util.*;
import java.io.*;

public class StockCharts {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			// input
			
			System.out.println("solving case " + caseNum);
			
			int n = sc.nextInt(), k = sc.nextInt();
			
			int[][] price = new int[n][k];
			
			for (int i=0; i < n; i++) 
				for (int j=0; j < k; j++)
					price[i][j] = sc.nextInt();
			
			// solution
			
			int[][] fl = new int[2*n+2][2*n+2];
			int[][] cp = new int[2*n+2][2*n+2];
			
			for (int i=1; i<=n; i++) cp[0][i] = 1;
			for (int i=n+1; i<=2*n; i++) cp[i][2*n+1] = 1;
			
			for (int i=0; i < n; i++)
				for (int j=0; j < n; j++) {
					boolean less = true;
					for (int t=0; t < k; t++)
						if (price[i][t] >= price[j][t])
							less = false;
					if (less) cp[i+1][j+n+1] = 1;
				}
			
			int res = n;
			while (true) {
				int[] q = new int[2*n+2];
				int qBeg = 0, qEnd = 0;
				int[] prev = new int[2*n+2];
				Arrays.fill(prev, -1);
				prev[0] = 0;
				q[qBeg++] = 0;
				while (qEnd < qBeg) {
					int curV = q[qEnd++];
					for (int i=0; i < 2*n+2; i++)
						if (fl[curV][i] < cp[curV][i] && prev[i] == -1) {
							prev[i] = curV;
							q[qBeg++] = i;
						}
				}
				if (prev[2*n+1] == -1) break;
				res--;
				int x=2*n+1;
				while (x>0) {
					fl[prev[x]][x]++;
					fl[x][prev[x]]--;
					x = prev[x];
				}
			}
			
			// output
			pw.println("Case #" + caseNum + ": " + res);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new StockCharts()).doMain();
	}
}