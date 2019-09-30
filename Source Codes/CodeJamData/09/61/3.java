import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
	/*	PrintWriter out = new PrintWriter(new File("aa.in"));
		out.println(50);
		for (int tests = 1; tests <= 50; tests++) {
			out.println("1000000000 50");
			for (int jj = 0; jj < 50; jj++) {
				out.print(50);
				for (int kk = 1; kk < 50; kk++)
					out.print(" " + kk * 200);
				out.println();
			}
		}
		out.close();
		return;
		*/
		long x = System.currentTimeMillis();
	    Scanner in = new Scanner(new File("a2.in"));
	    PrintWriter out = new PrintWriter(new File("a2.out"));
	    
	    int tn = in.nextInt(), tt, n, t, i, j, k, M;
	    int [][] d = new int[55][55];
	    int [] c = new int[55], b = new int[55];
	    int [] cnt;
	    BigInteger [][] dp = new BigInteger[55][55];
	    for (tt = 1; tt <= tn; tt++) {
	    	M = 0;
		    BigInteger ans = BigInteger.ZERO;
	    	n = in.nextInt(); t = in.nextInt();
	    	for (i = 0; i < t; i++) {
	    		c[i] = in.nextInt();
	    		for (j = 1; j < c[i]; j++) {
	    			d[i][j] = in.nextInt();
	    			d[i][j]--;
	    			M = Math.max(M, d[i][j]+1);
	    		}
	    	}
	    	int L = Math.min(n, M);
	    	BigInteger prevsum = BigInteger.ZERO;
	    	int [] prev = new int[55];
	    	for (i = 0; i < prev.length; i++) prev[i] = -1;
	    	for (k = 0; k < L; k++) {
	    		for (i = 0; i < t; i++) {
	    			b[i] = 0;
	    			for (j = 0; j < c[i]; j++) {
	    				if (k >= d[i][j]) b[i]++;
	    			}
	    		//	out.println(b[i]+",");
	    		}
	    		for (i = 0; i < t; i++)
	    			if (b[i] != prev[i]) break;
	    		if (i == t) {
	    			ans = ans.add(prevsum);
	    			continue;
	    		}
	    		//out.flush();
	    		dp[0][0] = BigInteger.ONE;
	    		for (i = 1; i <= t; i++) {
	    			BigInteger b1 = BigInteger.valueOf(b[i-1]);
	    			BigInteger b2 = BigInteger.valueOf(n-b[i-1]);
	    			for (j = 0; j <= i; j++) {
	    				dp[i][j] = BigInteger.ZERO;
	    				if (j > 0) 
	    					dp[i][j] = dp[i][j].add(dp[i-1][j-1].multiply(b1));
	    				if (i > j)
	    					dp[i][j] = dp[i][j].add(dp[i-1][j].multiply(b2));
	    			}
	    		}
	    		BigInteger sum = BigInteger.ZERO;
	    		for (j = 0; j <= t; j++)
	    			sum = sum.add(dp[t][j].multiply(BigInteger.valueOf(j*j)));
	    		ans = ans.add(sum);
	    		for (i = 0; i < t; i++)
	    			prev[i] = b[i];
	    		prevsum = sum;
	    	}
	    	if (L < n) {
	    		for (i = 0; i < t; i++) {
	    			b[i] = c[i];
	    		}
	    		dp[0][0] = BigInteger.ONE;
	    		for (i = 1; i <= t; i++)
	    			for (j = 0; j <= i; j++) {
	    				dp[i][j] = BigInteger.ZERO;
	    				if (j > 0) 
	    					dp[i][j] = dp[i][j].add(dp[i-1][j-1].multiply(BigInteger.valueOf(b[i-1])));
	    				if (i > j) dp[i][j] = dp[i][j].add(dp[i-1][j].multiply(BigInteger.valueOf(n-b[i-1])));
	    			}
	    		BigInteger sum = BigInteger.ZERO;
	    		for (j = 0; j <= t; j++)
	    			sum = sum.add(dp[t][j].multiply(BigInteger.valueOf(j*j)));
	    		ans = ans.add(sum.multiply(BigInteger.valueOf(n-L)));
	    	}
	    	BigInteger o = BigInteger.valueOf(n).pow(t);
	    	BigInteger g = ans.gcd(o);
	    	o = o.divide(g);
	    	ans = ans.divide(g);
	    	out.print("Case #"+tt+": ");
	    	out.print(ans.divide(o)+"+");
	    	out.print(ans.mod(o)+"/"+o);
	    	out.println();
	    	long y = System.currentTimeMillis();
//	    	out.println(y-x);
	    	
	    	out.flush();
	//    	break;
	    }
	    
	    out.close();
	}
}
