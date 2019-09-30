import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class MinesweeperMaster {
    
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static int M, R, C, B;
	static char[][] board;
	static final char MINE = '*', EMPTY = '.', CLICK = 'c';


    static void solve() throws IOException {
    	R = nextInt();
    	C = nextInt();
    	M = nextInt();
    	B = R * C - M;
    	
    	setBoard();
    	
    	printlnCase();
    	
    	if (R == 1 || C == 1) printBoard();
    	else if (R == 2 || C == 2) {
    		if (B == 1 || (B > 2 && B % 2 == 0)) printBoard();
    		else out.println("Impossible");
    	}
    	else {
    		if (B >= 2 * (R + C - 2)) printBoard();
    		else if (B == 2 || B == 3 || B == 5 || B == 7) out.println("Impossible");
    		else printBoard();
    	}
    	
    	
    }
  
    static void printBoard() {
    	for (int i = 0; i < R; i++) {
    		for (int j = 0; j < C; j++) {
    			out.print(board[i][j]);
    		}
    		out.println();
    	}
    }
    
    static void setBoard() {
    	
    	board = new char[R][C];
    	
    	for (int i = 0; i < R; i++) {
    		for (int j = 0; j < C; j++) board[i][j] = MINE;
    	}
    	
    	
    	if (R == 1) {
    		for (int i = 0; i < B; i++) board[0][i] = EMPTY;
    	}
    	else if (C == 1) {
    		for (int i = 0; i < B; i++) board[i][0] = EMPTY;
    	}
    	else if (R == 2) {
    		for (int i = 0; i < B / 2; i++) {
    			board[0][i] = EMPTY;
    			board[1][i] = EMPTY;
    		}
    	}
    	else if (C == 2) {
    		for (int i = 0; i < B / 2; i++) {
    			board[i][0] = EMPTY;
    			board[i][1] = EMPTY;
    		}
    	}
    	else {
    		int m = 2, n = 2;
    		while (m * n < B) {
    			if (m < R && n < C) {
    				if (m < n) m++;
    				else n++;
    			}
    			else if (m < R) m++;
    			else n++;
    		}
    		
    		for (int i = 0; i < m; i++) {
    			board[i][0] = EMPTY;
    			board[i][1] = EMPTY;
    		}
    		for (int j = 0; j < n; j++) {
    			board[0][j] = EMPTY;
    			board[1][j] = EMPTY;
    		}
    		
    		int count = B - 2 * (m + n - 2);
    		for (int i = 2; i < m && count > 0; i++) {
    			for (int j = 2; j < n && count > 0; j++) {
    				board[i][j] = EMPTY;
    				count--;
    			}
    		}
    	}
    	
    	board[0][0] = CLICK;
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
			in = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter("C-large.out");
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
