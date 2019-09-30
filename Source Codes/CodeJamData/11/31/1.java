import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

//	String inputFile = "sample.txt";
//	String inputFile = "input/A-small-attempt0.in";
	String inputFile = "input/A-large.in";
	
	String outputFile = "output.txt";
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
	
		for (int testCase = 1, testCount = nextInt(); testCase <= testCount; testCase++) {
			solve(testCase);
		}
		
		out.close();
	}

	/* Solving */
	
	int N;
	int M;
	char[][] map;
	
	void solve(int testCase) throws IOException {
		/* Input */
		N = nextInt();
		M = nextInt();
		map = new char [N][];
		for (int i = 0; i < N; i++)
			map[i] = nextToken().toCharArray();
		
		/* Solution */
		lp: for (;;) {
			for (int i = 0; i + 1 < N; i++)
				for (int j = 0; j + 1 < M; j++) {
					if (map[i][j] == '#') {
						if (replace(i, j)) {
							continue lp;
						} else {
							break lp;
						}
					}
				}
			break;
		}
		
		boolean ok = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == '#')
					ok = false;
		
		/* Output */
		out.println("Case #" + testCase + ":");
		if (ok) {
			for (char[] s : map)
				out.println(s);
		} else {
			out.println("Impossible");
		}
	}
	
	
	boolean replace(int i, int j) {
		if (map[i][j] != '#') return false;
		if (map[i + 1][j] != '#') return false;
		if (map[i][j + 1] != '#') return false;
		if (map[i + 1][j + 1] != '#') return false;
		map[i][j] = map[i + 1][j + 1] = '/';
		map[i + 1][j] = map[i][j + 1] = '\\';
		return true;
	}


	/*************************************************************** 
	 * Input 
	 **************************************************************/
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
