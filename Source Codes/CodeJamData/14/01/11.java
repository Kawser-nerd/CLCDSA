import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class MagicTrick {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static int[][] b1 = new int[4][4];
	static int[][] b2 = new int[4][4];
	static String[] res = {"Volunteer cheated!", "Bad magician!"};


    static void solve() throws IOException {
    	int r1 = nextInt();
    	read(b1);
    	int r2 = nextInt();
    	read(b2);
    	
    	int count = 0, num = 0;
    	for (int i : b1[r1 - 1]) {
    		for (int j : b2[r2 - 1]) {
    			if (i == j) {
    				count++;
    				num = i;
    			}
    		}
    	}
    	
    	printCase();
    	if (count == 0) out.println(res[0]);
    	else if (count == 1) out.println(num);
    	else out.println(res[1]);
    }
    
    static void read(int[][] b) throws IOException {
    	for (int i = 0; i < 4; i++) {
    		for (int j = 0; j < 4; j++) b[i][j] = nextInt();
    	}
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
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			out = new PrintWriter("A-small-attempt0.out");
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
