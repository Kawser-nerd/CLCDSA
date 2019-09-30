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
			ArrayList<Integer> l = new ArrayList<>();
			for(int i = 2; i <= 30000; i++) {
				if(i%2!=0 && i%3!=0 && i%5!=0) continue;
				l.add(i);
			}
			int n = readInt();
			while(true) {
				long gcd = 0;
				Collections.shuffle(l);
				long ans = 0;
				for(int i = 0; i < n; i++) {
					ans += l.get(i);
					gcd = gcd(gcd, l.get(i));
				}
				if(gcd == 1 && ans%30==0) break;
			}
			for(int i = 0; i < n; i++) {
				pw.print(l.get(i));
				if(i == n-1) pw.println();
				else pw.print(" ");
			}
		}
		exitImmediately();
	}

	public static long gcd(long a, long b) {
		if(a==0)return b;
		if(b==0)return a;
		return gcd(b, a%b);
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