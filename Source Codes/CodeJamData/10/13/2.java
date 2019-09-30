import java.io.*;
import java.util.*;
import java.math.*;

public class Game {
	
	static Scanner in;
	static PrintWriter out;
	
	static int a1, a2, b1, b2;

	static boolean isWin(int a, int b) {
		if (a < b) {
			return isWin(b, a);
		}
		if (b == 0) {
			return true;
		}
		if (!isWin(b, a%b)) {
			return true;
		}
		if (a/b == 1) {
			return false;
		}
		return true;
	}

	static int MAX = 1000010;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));
		
		int[] w = new int[MAX];
		int[] e = new int[MAX];
		w[1] = 1;
		e[1] = 2;
		for (int i=2; i<MAX; i++) {
			if (isWin(i, w[i-1])) {
				w[i] = w[i-1]+1;
			} else {
				w[i] = w[i-1];
			}
			e[i] = w[i] + i;
		}

		/*
		int n = 100;

		int[][] p = new int[n][n];
		
		for (int i=0; i<n; i++) {
			p[i][0] = p[0][i] = 1;
		}

		for (int i=1; i<n; i++) {
			for (int j=1; j<=i; j++) {
				for (int c = i-j; c >= 0; c -= j) {
					if (p[j][c] == 0) {
						p[j][i] = p[i][j] = 1;
					}
				}
			}
		}

		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				out.print(p[i][j]);
			}
			out.println();
		}
		
			
		int[] st = new int[n];
		for (int i=1; i<n; i++) {
			while (p[i][st[i]] == 1) {
				st[i]++;
			}	
		}

		for (int i=1; i<n; i++) {
			out.println(st[i] + " " + w[i]);
		}
		*/

		int T = in.nextInt();
		for (int cas=1; cas<=T; cas++) {
			
			int a1 = in.nextInt();
			int a2 = in.nextInt();
			int b1 = in.nextInt();
			int b2 = in.nextInt();

			long count = 0;

			for (int a=a1; a<=a2; a++) {
				int u = Math.max(b1, w[a]);
				int v = Math.min(b2+1, e[a]);
				count += (b2-b1+1) - Math.max(v-u, 0);
			}

			
			out.printf("Case #%d: %d%n", cas, count);
		}

		out.close();	
	}
}