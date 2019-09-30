package r2_2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt();
			a = new int[n];
			for (int i = 0; i < n; i++) a[i] = in.nextInt();
			b = new int[n];
			for (int i = 0; i < n; i++) b[i] = in.nextInt();
			
			int[] p = new int[n];
			Arrays.fill(p, n+1);
			
			go(p, 1);
			for (int i = 0; i < n; i++) out.print(p[i] + " ");
			out.println();
		}
		
		out.flush();
	}
	
	static int[] a, b;
	
	static boolean go(int[] p, int d) {
		if (d > p.length) return true;
		for (int i = 0; i < p.length; i++) if (p[i] > p.length) {
			p[i] = d;
			int[][] q = solve(p);
			if (q[0][i] == a[i] && q[1][i] == b[i] && go(p, d+1)) return true;
			p[i] = p.length+1;
		}
		return false;
	}

	static int[][] solve(int[] p) {
		int[] inc = new int[p.length];
		int[] dec = new int[p.length];
		for (int i = 0; i < p.length; i++) {
			int max = 0;
			for (int j = 0; j < i; j++)
				if (p[j] < p[i] && inc[j] > max)
					max = inc[j];
			inc[i] = max+1;
		}
		for (int i = p.length-1; i >= 0; i--) {
			int max = 0;
			for (int j = p.length-1; j > i; j--)
				if (p[j] < p[i] && dec[j] > max)
					max = dec[j];
			dec[i] = max+1;
		}
		return new int[][]{inc, dec};
	}
}
