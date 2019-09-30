import java.io.*;
import java.util.*;
import java.math.*;

public class Rotate {
	
	static Scanner in;
	static PrintWriter out;
	
	static char[][] a;

	static int[][] d = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
	static int n, k;

	static boolean inBoard(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < n;
	}

	static boolean test(char c, int x, int y) {
		metka:
		for (int[] dd : d) {
			
			for (int s=0; s<k; s++) {
				int nx = x + dd[0]*s;
				int ny = y + dd[1]*s;
				if (!inBoard(nx, ny) || a[nx][ny] != c) {
					continue metka;	
				}
			}

			return true;
		}	
		return false;
	}                     

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));

		int T = in.nextInt();
		for (int cas=1; cas<=T; cas++) {
			n = in.nextInt();
			k = in.nextInt();
			
			a = new char[n][];
			for (int i=0; i<n; i++) {
				a[i] = in.next().toCharArray();
			}

			for (int i=0; i<n ;i++) {
				for (int j=0; j<n; j++) {
					for (int l=n-1; l>0; l--) {
						if (a[i][l] == '.' && a[i][l-1] != '.') {
							a[i][l] = a[i][l-1];
							a[i][l-1] = '.';
						}
					}
				}
			}
			/*
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					out.print(a[i][j]);
				}
				out.println();
			}
			*/

			boolean okR = false;
			boolean okB = false;

			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					if (test('R', i, j)) {
						okR = true;
					}
					if (test('B', i, j)) {
						okB = true;
					}
				}
			}

			String ans = null;
			if (!okR && !okB) {
				ans = "Neither";
			}
			if (okR && !okB) {
				ans = "Red";
			}
			if (!okR && okB) {
				ans = "Blue";
			}
			if (okR && okB) {
				ans = "Both";
			}

			assert(ans != null);
			
			out.printf("Case #%d: %s%n", cas, ans);
		}

		out.close();	
	}
}