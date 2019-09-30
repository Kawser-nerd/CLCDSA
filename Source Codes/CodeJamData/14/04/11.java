import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class DeceitfulWar {
    
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static int n;
	static double[] naomi, ken;


    static void solve() throws IOException {
    	n = nextInt();
    	Assert.check(n > 0);
    	naomi = new double[n];
    	ken = new double[n];
    	read(naomi);
    	read(ken);
    	
    	printCase();
    	out.printf("%d %d", getScore2(), getScore1());
    	out.println();
    }
  
    static void read(double[] A) throws IOException {
    	for (int i = 0; i < n; i++) A[i] = nextDouble();
    	Arrays.sort(A);
    }
    
    // score when both are playing War
    static int getScore1() {
    	int i = n - 1, j = n - 1;
    	while(i >= 0) {
    		if (ken[j] > naomi[i]) j--;
    		i--;
    	}
    	return j + 1;
    }
    
    // socre for deceitful War
    static int getScore2() {
    	int i = 0, j = 0, s = 0;
    	while (i < n) {
    		if (naomi[i] > ken[j]) {
    			s++;
    			j++;
    		}
    		i++;
    	}
    	return s;
    }
    
    static class Assert{
    	static void check(boolean e){
    		if(!e) throw new Error();
    	}
    }

	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new FileReader("D-large.in"));
			out = new PrintWriter("D-large.out");
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}
