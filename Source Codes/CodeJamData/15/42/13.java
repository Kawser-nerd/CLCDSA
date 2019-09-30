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

	static State[] list;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			double volume = readDouble();
			double temp = readDouble();
			list = new State[n];
			for(int i = 0; i < n; i++) {
				list[i] = new State(readDouble() / volume, readDouble() - temp);
			}
			Arrays.sort(list);
			if(list[0].vt > 0) {
				pw.println("IMPOSSIBLE");
				continue;
			}
			if(list[n-1].vt < 0) {
				pw.println("IMPOSSIBLE");
				continue;
			}
			double min = 0;
			double max = 1e9;
			for(int qqq = 0; qqq < 100; qqq++) {
				double mid = (min+max)/2;
				if(poss(mid)) {
					max = mid;
				}
				else {
					min = mid;
				}
			}
			pw.println(min);
		}
		pw.close();
	}

	public static boolean poss(double amt) {
		double volume = 0;
		double temp = 0;
		for(State out: list) {
			volume += out.v * amt;
			temp += out.vt * amt;
		}
		if(volume < 1) return false;
		if(temp == 0) return true;
		if(temp > 0) {
			for(int i = list.length-1; i >= 0; i--) {
				double maxCanRemove = amt;
				maxCanRemove = Math.min(maxCanRemove, (volume-1)/list[i].v);
			//	pw.println(temp + ": " + maxCanRemove + " " + maxCanRemove * list[i].vt);
				if(temp - maxCanRemove * list[i].vt <= 0) {
					return true;
				}
				temp -= maxCanRemove * list[i].vt;
				volume -= maxCanRemove * list[i].v;
			}
		}
		else {
			for(int i = 0; i < list.length; i++) {
				double maxCanRemove = amt;
				maxCanRemove = Math.min(maxCanRemove, (volume-1)/list[i].v);
			//	pw.println(temp + ": " + maxCanRemove + " " + maxCanRemove * list[i].vt);
				if(temp - maxCanRemove * list[i].vt >= 0) {
					return true;
				}
				temp -= maxCanRemove * list[i].vt;
				volume -= maxCanRemove * list[i].v;
			}
		}
		return false;
	}
	
	static class State implements Comparable<State> {
		public double v, vt;

		public State(double vIn, double tIn) {
			super();
			this.v = vIn;
			this.vt = vIn*tIn;
		}
		
		public int compareTo(State s) {
			return Double.compare(vt, s.vt);
		}
		public String toString() {
			return v + " " + vt;
		}
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
