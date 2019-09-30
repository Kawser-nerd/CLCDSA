import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

/*
			  br = new BufferedReader(new FileReader("input.txt"));
			  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
			  br = new BufferedReader(new InputStreamReader(System.in));
			  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int a = readInt();
			int b = readInt();
			road = init(n);
			while(a-- > 0) {
				int x = readInt()-1;
				int y = readInt()-1;
				merge(road, x, y);
			}
			rail = init(n);
			while(b-- > 0) {
				int x = readInt()-1;
				int y = readInt()-1;
				merge(rail, x, y);
			}
			int[] ret = new int[n];
			Map<Integer, ArrayList<Integer>> dp = new HashMap<>();
			for(int i = 0; i < n; i++) {
				int key = find(road, i);
				if(!dp.containsKey(key)) {
					dp.put(key, new ArrayList<>());
				}
				dp.get(key).add(i);
			}
			for(int out: dp.keySet()) {
				Map<Integer, ArrayList<Integer>> inner = new HashMap<>();
				for(int out2: dp.get(out)) {
					int key = find(rail, out2);
					if(!inner.containsKey(key)) {
						inner.put(key, new ArrayList<>());
					}
					inner.get(key).add(out2);
				}
				for(int out2: inner.keySet()) {
					for(int out3: inner.get(out2)) {
						ret[out3] = inner.get(out2).size();
					}
				}
			}
			for(int i = 0; i < n; i++) {
				pw.print(ret[i]);
				if(i == n-1) pw.println();
				else pw.print(" ");
			}
		}
		exitImmediately();
	}

	static int[] road;
	static int[] rail;

	public static int[] init(int x) {
		int[] ret = new int[x];
		for(int i = 0; i < x; i++) {
			ret[i] = i;
		}
		return ret;
	}

	public static int find(int[] p, int x) {
		return p[x] == x ? x : (p[x] = find(p, p[x]));
	}
	public static void merge(int[] p, int x, int y) {
		p[find(p, x)] = find(p, y);
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(readToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(readToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(readToken());
	}

	private static String readLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String readToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(readLine().trim());
		}
		return st.nextToken();
	}
}