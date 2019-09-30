import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

public class Main {
	public static void main(String[] args) throws IOException {
		long prevTime = System.currentTimeMillis();
		new Main().run();
		System.err.println("Total time: " + (System.currentTimeMillis() - prevTime) + " ms");
		System.err.println("Memory status: " + memoryStatus());
	}

//	String inputFile = "sample.txt";
	String inputFile = "input/D-small-attempt0.in";
//	String inputFile = "input/D-large.in";
	
	String outputFile = "output.txt";
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
		solve();
		out.close();
	}
	
	
	void solve() throws IOException {
		for (int testCase = 1, testCases = nextInt(); testCase <= testCases; testCase++) {
			System.err.println("Case #" + testCase);
			solve(testCase);
		}
	}

	
	final int MAX_SERVERS = 4;
	final Trie[] tries = new Trie [MAX_SERVERS]; {
		for (int i = 0; i < tries.length; i++)
			tries[i] = new Trie(300);
	}
	
	int nServers;
	char[][] strings;
	
	int[] server;
	
	int maxNodes;
	int count;
	
	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		
		final int nStrings = nextInt();
		nServers = nextInt();
		strings = new char [nStrings][];
		for (int i = 0; i < nStrings; i++)
			strings[i] = nextToken().toCharArray();
		
		server = new int [nStrings];
		
		maxNodes = -1;
		count = 0;
		rec(0);

		out.println(maxNodes + " " + count);
	}
	
	void rec(int pos) {
		if (pos == strings.length) {
			update();
		} else {
			for (server[pos] = 0; server[pos] < nServers; server[pos]++) {
				rec(pos + 1);
			}
		}
	}

	void update() {
		for (int i = 0; i < nServers; i++)
			tries[i].clear();
		for (int i = 0; i < strings.length; i++)
			tries[server[i]].add(strings[i]);
		int nodes = 0;
		for (int i = 0; i < nServers; i++) {
			if (tries[i].cnt == 1) return;
			nodes += tries[i].cnt;
		}
		if (maxNodes < nodes) {
			maxNodes = nodes;
			count = 0;
		}
		if (maxNodes == nodes) {
			count++;
		}
	}

	static class Trie {
		int ROOT = 0;
		int ALPHA = 26;
		int[][] next;
		boolean[] term;
		int cnt = 1;
		
		Trie(int size) {
			next = new int [size + 1][ALPHA];
			term = new boolean [size + 1];
		}
		
		boolean add(char[] s) {
			int v = ROOT;
			for (char c : s) {
				if (next[v][make(c)] == ROOT)
					next[v][make(c)] = alloc();
				v = next[v][make(c)];
			}
			if (term[v])
				return false;
			return term[v] = true;
		}

		boolean contains(char[] s) {
			int v = ROOT;
			for (char c : s)
				if ((v = next[v][make(c)]) == ROOT)
					return false;
			return term[v];
		}
		
		int make(char c) {
			return c - 'A';
		}
		
		int alloc() {
			return cnt++;
		}
		
		void clear() {
			cnt = 1;
			for (final int[] row : next)
				fill(row, ROOT);
		}
	}
	
	
	/*************************************************************** 
	 * Input 
	 **************************************************************/
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
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
	
	int[] nextIntArray(int size) throws IOException {
		int[] ret = new int [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextInt();
		return ret;
	}
	
	long[] nextLongArray(int size) throws IOException {
		long[] ret = new long [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextLong();
		return ret;
	}
	
	double[] nextDoubleArray(int size) throws IOException {
		double[] ret = new double [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextDouble();
		return ret;
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
	
	/*************************************************************** 
	 * Output 
	 **************************************************************/
	void printRepeat(String s, int count) {
		for (int i = 0; i < count; i++)
			out.print(s);
	}
	
	void printArray(int[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(long[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array, String spec) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.printf(Locale.US, spec, array[i]);
		}
		out.println();
	}
	
	void printArray(Object[] array) {
		if (array == null || array.length == 0)
			return;
		boolean blank = false;
		for (Object x : array) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	@SuppressWarnings("rawtypes")
	void printCollection(Collection collection) {
		if (collection == null || collection.isEmpty())
			return;
		boolean blank = false;
		for (Object x : collection) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	/*************************************************************** 
	 * Utility
	 **************************************************************/
	static String memoryStatus() {
		return (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory() >> 20) + "/" + (Runtime.getRuntime().totalMemory() >> 20) + " MB";
	}
	
	static void checkMemory() {
		System.err.println(memoryStatus());
	}
	
	static long prevTimeStamp = Long.MIN_VALUE;
	
	static void updateTimer() {
		prevTimeStamp = System.currentTimeMillis();
	}
	
	static long elapsedTime() {
		return (System.currentTimeMillis() - prevTimeStamp);
	}
	
	static void checkTimer() {
		System.err.println(elapsedTime() + " ms");
	}
}
