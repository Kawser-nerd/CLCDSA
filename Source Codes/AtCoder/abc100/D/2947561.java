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
			int m = readInt();
			State[] l = new State[n];
			for(int i = 0; i < n; i++) {
				l[i] = new State(readLong(), readLong(), readLong());
			}
			long ret = 0;
			for(int mask = 0; mask < 8; mask++) {
				if((mask&1)!=0) for(int i = 0; i < n; i++) l[i].x *= -1;
				if((mask&2)!=0) for(int i = 0; i < n; i++) l[i].y *= -1;
				if((mask&4)!=0) for(int i = 0; i < n; i++) l[i].z *= -1;
				Arrays.sort(l);
				long xx = 0;
				long yy = 0;
				long zz = 0;
				for(int i = 0; i < m; i++) {
					xx += l[i].x;
					yy += l[i].y;
					zz += l[i].z;
				}
				ret = Math.max(ret, Math.abs(xx) + Math.abs(yy) + Math.abs(zz));
				if((mask&1)!=0) for(int i = 0; i < n; i++) l[i].x *= -1;
				if((mask&2)!=0) for(int i = 0; i < n; i++) l[i].y *= -1;
				if((mask&4)!=0) for(int i = 0; i < n; i++) l[i].z *= -1;
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public long x, y, z;

		public State(long x, long y, long z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}
		public long sum() {
			return x + y + z;
		}
		public int compareTo(State s) {
			return Long.compare(s.sum(), sum());
		}
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