import java.io.*;
import java.util.*;

public class Bai2 {
	
	int m, n;
	int[][] a;
	int[][] Tx, Ty;
	int[][] Tp;
	
	String solve(int[][] a) {
		this.a = a;
		m = a.length;
		n = a[0].length;
		
		Tp = new int[m][n];
		Tx = new int[m][n];
		Ty = new int[m][n];
		
		for(int i=0;i<m;++i) {
			for(int j=0;j<n;++j) {
				Tp[i][j] = a[i][j] + (i > 0 ? Tp[i-1][j] : 0) + (j > 0 ? Tp[i][j-1] : 0) - ((i > 0 && j > 0) ? Tp[i-1][j-1] : 0);
				Tx[i][j] = a[i][j] * i + (i > 0 ? Tx[i-1][j] : 0) + (j > 0 ? Tx[i][j-1] : 0) - ((i > 0 && j > 0) ? Tx[i-1][j-1] : 0);
				Ty[i][j] = a[i][j] * j + (i > 0 ? Ty[i-1][j] : 0) + (j > 0 ? Ty[i][j-1] : 0) - ((i > 0 && j > 0) ? Ty[i-1][j-1] : 0);
			}
		}
		
		int bestk = 2;
		
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j) {
				
				int maxk = Math.min(i, j) + 1;
				for(int k=maxk;k>=bestk+1;--k) {
					
					int tx = Tx[i][j] - (i >= k ? Tx[i-k][j] : 0) - (j >= k ? Tx[i][j-k] : 0) + ((i >= k && j >= k) ? Tx[i-k][j-k] : 0);
					int ty = Ty[i][j] - (i >= k ? Ty[i-k][j] : 0) - (j >= k ? Ty[i][j-k] : 0) + ((i >= k && j >= k) ? Ty[i-k][j-k] : 0);
					int tp = Tp[i][j] - (i >= k ? Tp[i-k][j] : 0) - (j >= k ? Tp[i][j-k] : 0) + ((i >= k && j >= k) ? Tp[i-k][j-k] : 0);
					
					tp -= a[i][j] + a[i-k+1][j] + a[i][j-k+1] + a[i-k+1][j-k+1];
					tx -= a[i][j]*i + a[i-k+1][j]*(i-k+1) + a[i][j-k+1]*i + a[i-k+1][j-k+1]*(i-k+1);
					ty -= a[i][j]*j + a[i-k+1][j]*j + a[i][j-k+1]*(j-k+1) + a[i-k+1][j-k+1]*(j-k+1);
					
					if(tp * (2 * i - k + 1) == 2 * tx && tp * (2 * j - k + 1) == 2 * ty) {
						bestk = k;
						break;
					}
				}
			}
		
		if(bestk >= 3) return "" + bestk;
		else return "IMPOSSIBLE";
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		// Scanner sc = new Scanner(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("Blarge.out"));
		
		
		int ntest = sc.nextInt();
		
		for(int test=1;test<=ntest;++test) {
			
			int m = sc.nextInt();
			int n = sc.nextInt();
			int d = sc.nextInt();
			char[][] a = new char[m][];
			for(int i=0;i<m;++i)
				a[i] = sc.next().toCharArray();
			int[][] h = new int[m][n];
			for(int i=0;i<m;++i)
				for(int j=0;j<n;++j) {
					h[i][j] = a[i][j] - '0';
				}
			
			String res = new Bai2().solve(h);
			
			pw.print("Case #" + test + ": ");
			pw.print(res);
			pw.println();
		}
		pw.close();
		sc.close();
	}
}
