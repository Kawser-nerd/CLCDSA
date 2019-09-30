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
			String s = readToken();
			int ret = s.length()-1;
			for(char ch = 'a'; ch <= 'z'; ch++) {
				if(s.indexOf(ch) == -1) continue;
				String curr = s;
				int ans = 0;
				while(!valid(curr)) {
					StringBuilder sb = new StringBuilder();
					for(int i = 0; i < curr.length()-1; i++) {
						if(curr.charAt(i) == ch || curr.charAt(i+1) == ch) {
							sb.append(ch);
						}
						else {
							sb.append('?');
						}
					}
					curr = sb.toString();
					ans++;	
				}
				ret = Math.min(ret, ans);
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	public static boolean valid(String s) {
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) != s.charAt(0)) return false;
		}
		return true;
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