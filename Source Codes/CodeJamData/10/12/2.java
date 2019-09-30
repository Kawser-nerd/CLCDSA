import java.io.*;
import java.util.*;
import java.math.*;

public class Smooth {
	
	static Scanner in;
	static PrintWriter out;
	
	static int D, I, M, n;
	static int[] a;
	static int[][] d;

	static final int INF = Integer.MAX_VALUE / 4;

	static boolean relax(int i, int j, int v) {
		if (d[i][j] > v) {
			d[i][j] = v;
			return true;
		}
		return false;
	}            

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new File("output.txt"));

		int T = in.nextInt();
		for (int cas=1; cas<=T; cas++) {
			
			D = in.nextInt();
			I = in.nextInt();
            M = in.nextInt();
			n = in.nextInt();
			
			a = new int[n];
			for (int i=0; i<n; i++) {
				a[i] = in.nextInt();
			}

			d = new int[n+1][256];


			for (int i=1; i<=n; i++) {
				Arrays.fill(d[i], INF);
				boolean flag = true;
				while (flag) { 
    				flag = false;
    			    for (int j=0; j<256; j++) {
    					for (int l=Math.max(j-M, 0); l<=Math.min(255, j+M); l++) {
    						flag |= relax(i-1, l , d[i-1][j] + I);
    					}
    				}

    			}
    				
    			for (int j=0; j<256; j++) {
    					
    				relax(i, j, d[i-1][j] + D);
    					
    				for (int l=Math.max(j-M, 0); l<=Math.min(255, j+M); l++) {
    					relax(i, l , d[i-1][j] + Math.abs(a[i-1]-l));
    				}

    					

    			}
			}

			int ans = INF;
			for (int i=0; i<256; i++) {
				ans = Math.min(ans, d[n][i]);
			}
			
			out.printf("Case #%d: %d%n", cas, ans);
		}

		out.close();	
	}
}