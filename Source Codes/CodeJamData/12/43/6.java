import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {
	
	final String problem = "C";
//	final String filename = problem + "-sample";
//	final String filename= problem+"-small-attempt0";
//	final String filename= problem+"-small-attempt1";
	final String filename= problem+"-large";
	
	int N;
	int[] best;
	int[] h;
	boolean flag;

	public void rec(int left, int right) {
		if (left==right) return;
		int l = left;
		for (int x = left; x < right; x++) {
			if (best[x] == right) {
				rec(l, x);
				l = x + 1;
			} else if (best[x] > right)
				flag = false;
		}
		for (int x = left; x < right; x++) {
			h[x] = h[x] - (right - x + 1);
		}
	}

	public void solve() throws Exception {
		int N = iread();
		best = new int[N];
		for (int i = 0; i + 1 < N; i++)
			best[i] = iread()-1;
		h = new int[N];
		flag = true;
		rec(0, N - 1);
		if (!flag) {
			out.write("Impossible");
			return;
		}
		//testing
		for (int i=0; i+1<N; i++) {
			int b = i+1;
			for (int j=i+2; j<N; j++)
			{
				if ((h[j] - h[i])*(long)(b-i) > (h[b]-h[i])*(long)(j-i)) {
					b = j;
				}
			}
			if (b!=best[i])
				System.out.println("FAIL");
		}
		
		int min = 0;
		for (int i=0; i<N; i++)
			min = Math.min(min, h[i]);
		for (int i = 0; i < N; i++) {
			if (i > 0)
				out.write(" ");
			out.write((h[i] - min) + "");
		}
	}
	public void solve_gcj() throws Exception
	{
		int tests = iread();
		for (int test=1; test<=tests; test++)
		{
			out.write("Case #"+test+": ");
			solve();
			out.write("\n");
		}
	}
	
	public void run() {
		try {
//			in = new BufferedReader(new InputStreamReader(System.in));
//			out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename+".in"));
			out = new BufferedWriter(new FileWriter(filename+".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}
	public static void main(String[] args) {
		try{
			Locale.setDefault(Locale.US);
		} catch (Exception e)
		{
			
		}
		new Thread(new Main()).start();
		//new Thread(null, new Main(), "1", 1<<25).start();
	}
}