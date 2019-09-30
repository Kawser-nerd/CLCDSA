import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	PrintWriter out;
	
	static final String problem = "A-large";
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	
	void solveOne() {
		int r = in.nextInt();
		int c = in.nextInt();
		
		char ar[][] = new char[r][];
		
		for (int i = 0; i < r; i++) {
			ar[i] = in.next().toCharArray();
			asserT(ar[i].length == c);
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				// try place
				if (ar[i][j] == '#') {
					if (i == r - 1 || j == c - 1) {
						out.println("Impossible");
						return;
					}
					if (ar[i][j + 1] == '#' && ar[i + 1][j] == '#' && ar[i + 1][j + 1] == '#') {
						ar[i][j] = '/';
						ar[i][j + 1] = '\\';
						ar[i + 1][j] = '\\';
						ar[i + 1][j + 1] = '/';
					} else {
						out.println("Impossible");
						return;
					}
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (char val : ar[i]) {
				out.print(val);
			}
			out.println();
		}
	}
	
	void solve() {
		int nTests = in.nextInt();
		for (int i = 0; i < nTests; i++) {
			out.println("Case #"+(i+1)+":");
			solveOne();
		}
	}
	
	void run() {
		try {
			in = new Scanner(new FileReader("C:\\roundC\\" + problem + ".in"));
			out = new PrintWriter(new FileWriter("C:\\roundC\\" + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}