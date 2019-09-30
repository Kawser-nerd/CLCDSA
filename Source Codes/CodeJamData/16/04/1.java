import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("d.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int k = readInt();
			int c = readInt();
			int s = readInt();
			if(s*c < k) {
				pw.println("IMPOSSIBLE");
				continue;
			}
			ArrayList<Long> list = new ArrayList<Long>();
			for(int i = 0; i < k; i += c) {
				long now = 0;
				for(int a = 0; a < c; a++) {
					now *= k;
					if(i+a < k) {
						now += (i+a);
					}
				}
				list.add(now);
			}
			StringBuilder sb = new StringBuilder();
			for(long out: list) {
				sb.append(out+1);
				sb.append(" ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
