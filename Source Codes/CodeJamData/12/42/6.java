import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {
	
	final String problem = "B";
//	final String filename = problem + "-sample";
//	final String filename= problem+"-small-attempt0";
//	final String filename= problem+"-small-attempt1";
	final String filename= problem+"-large";
	
	int N;
	int[] x, y, r;
	boolean[] was;
	int count;
	
	void tryVertical(int W, int H, int left, int right, int bottom, int top) {
		//position of bottom
		int k = 0;
		for (int i=0; i<N; i++) {
			if (was[i]) continue;
			x[i] = left + r[i];
			if (x[i]<0) x[i] = 0;
			if (x[i]>W) x[i] = W;
			if (k==0)
				y[i] = bottom + r[i];
			else y[i] = top - r[i];
			if (y[i]<0) y[i] = 0;
			if (y[i]>H) y[i] = H;
			if (x[i]-r[i]<left) continue;
			if (x[i]+r[i]>right) continue;
			if (y[i]-r[i]<bottom) continue;
			if (y[i]+r[i]>top) continue;
			was[i] = true;
			if (k==0)
				bottom = y[i] + r[i];
			else top = y[i] - r[i];
			k++;
		}
		count += k;
	}
	
	final int INF = 1000000000;
	
	int firstLess(int x) {
		for (int i=0; i<N; i++)
			if (!was[i]&&r[i]<=x)
				return i;
		return -1;
	}
	
	boolean trySolve(int W, int H) {
		was = new boolean[N];
		count = 0;
		//first column
		tryVertical(W, H, -INF, r[0], -INF, INF);
		int second = firstLess(W-r[0]);
		if (second==-1)
			return count==N;
		tryVertical(W, H, W-r[second], INF, -INF, INF);
		int left = r[0], right = W-r[second];
		while (true) {
			second = firstLess((right-left)/2);
			if (second==-1)
				return count==N;
			tryVertical(W, H, left, left+2*r[second], -INF, INF);
			left+=2*r[second];
		}
	}
	
	public void solve() throws Exception {
		N = iread();
		int W = iread(), L = iread();
		x = new int[N];
		y = new int[N];
		r = new int[N];
		for (int i=0; i<N; i++) {
			r[i] = iread();
		}
		int[] ind = new int[N];
		int[] rev = new int[N];
		for (int i = 0; i < N; i++)
			ind[i] = i;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j + 1 < N - i; j++) {
				if (r[i] < r[i + 1]) {
					int t = r[i];
					r[i] = r[i + 1];
					r[i + 1] = t;
					t = ind[i];
					ind[i] = ind[i + 1];
					ind[i + 1] = t;
				}
			}
		}
		for (int i=0; i<N; i++)
			rev[ind[i]] = i;
		if (!trySolve(W, L)) {
			if (!trySolve(L, W)) {
				System.out.println("FAIL TEST");
				out.write("FAIL");
				return;
			}
			for (int i = 0; i < N; i++) {
				int t = x[i];
				x[i] = y[i];
				y[i] = t;
			}
		}
		for (int i = 0; i < N; i++) {
			if (x[i] < 0 || x[i] > W || y[i] < 0 || y[i] > L)
				System.out.println("FAIL TEST 2");
			for (int j = i + 1; j < N; j++)
				if (Math.max(Math.abs(x[j] - x[i]), Math.abs(y[j] - y[i])) < r[i] + r[j])
					System.out.println("FAIL TEST 3");
		}
		
		for (int i = 0; i < N; i++) {
			if (i > 0)
				out.write(" ");
			out.write(x[rev[i]] + " " + y[rev[i]]);
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