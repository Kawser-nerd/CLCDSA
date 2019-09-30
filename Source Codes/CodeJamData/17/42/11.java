import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int numSeat = readInt();
			int numCustomer = readInt();
			int tickets = readInt();
			int[][] data = new int[tickets][2];
			for(int i = 0; i < data.length; i++) {
				data[i][0] = readInt()-1;
				data[i][1] = readInt()-1;
			}
			int[] perCustomer = new int[numCustomer];
			int[] perSeat = new int[numSeat];
			for(int[] out: data) {
				perCustomer[out[1]]++;
				perSeat[out[0]]++;
			}
			int ret = 0;
			for(int out: perCustomer) {
				ret = Math.max(ret, out);
			}
			{
				int now = 0;
				for(int i = 0; i < perSeat.length; i++) {
					now += perSeat[i];
					ret = Math.max(ret, (now + i) / (i+1));
				}
			}
			int error = 0;
			for(int out: perSeat) {
				error += Math.max(0, out - ret);
			}
			pw.println(ret + " " + error);
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
