import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.math.*;

public class Main implements Runnable {
	BufferedReader in;
	PrintWriter out;  
	StringTokenizer st = new StringTokenizer("");
	long mod = 100003;
	
	public static void main(String [] args) throws Exception {
		new Thread(new Main()).start();
	}


	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter("out.txt");

			int mn = 503;
			long [][] cnk = new long[mn][mn];
			for (int i = 0; i < mn; i++)
				for (int j = 0; j <= i; j++) {
					if (i == j || j == 0) cnk[i][j]	= 1;
					else cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % mod;
				}

			long [][] d = new long[mn][mn];
			for (int n = 2; n < mn; n++) {
				d[n][1] += 1; // n --> first
				for (int t = 2; t <= n - 1; t++) {
					for (int i = 0; i <= Math.min(t - 2, n - t - 1); i++) {
						d[n][t] = (d[n][t] + cnk[n-t-1][i] * d[t][t-i-1]) % mod;
					}
				}
			}

			
			long [] ans = new long [mn];
			for (int n = 0; n < mn; n++) {
				for (int t = 1; t < n; t++)
					ans[n] = (ans[n] + d[n][t]) % mod;
			}


			int T = nextInt();
			for (int cases = 0; cases < T; cases++) {
			        int n = nextInt();
			        out.println("Case #" + (cases + 1) + ": " + ans[n]);
			}


			out.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	 boolean seekForToken() {
 		try {
			while (!st.hasMoreTokens()) {
				String s = in.readLine();
				if (s == null) {
				 	return false;
				}
			 	st = new StringTokenizer(s);
			}
			return true;
		}
		catch (IOException e) {
		 	e.printStackTrace();
		 	return false;
		}
 	}

 	 int nextInt() {
		return Integer.parseInt(nextToken());
 	}

 	 long nextLong() {
		return Long.parseLong(nextToken());
 	}

 	 double nextDouble() {
		return Double.parseDouble(nextToken());
 	}

 	 BigInteger nextBigInteger() {
 	 	return new BigInteger(nextToken());
 	}

 	 String nextToken() {
 	 	seekForToken();
 	 	return st.nextToken();
 	}

}
