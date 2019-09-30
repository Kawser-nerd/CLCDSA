import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class CookiClickerAlpha {
    
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static private double C, F, X;
    static private final double D = 2.0;
    static private int N;

    static void solve() throws IOException {
    	N = 0;
    	C = nextDouble();
    	F = nextDouble();
    	X = nextDouble();
    	
    	double time = 0.0;
    	while(true) {
    		double t1 = getTime0(X), t2 = getTime1(X);
    		if (t1 < t2) {
    			time += t1;
    			break;
    		}
    		else {
    			time += getTime0(C);
    			N++;
    		}
    	}
    	
    	printCase();
    	out.println(time);
    }
  
    
    static double getTime0(double c) {
    	return c / (D + F * N);
    }
    
    static double getTime1(double c) {
    	return c / (D + F * (N + 1)) + getTime0(C);
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
			in = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter("B-large.out");
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
