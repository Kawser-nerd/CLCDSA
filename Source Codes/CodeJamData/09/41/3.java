import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "A-large";

	public void solve() throws Exception {
		int T = iread();
		for (int ntest = 1; ntest <= T; ntest++) {
			int N = iread();
			int[][] a = new int[N][N];
			for (int i = 0; i < N; i++)
			{
				String s = readword();
				for (int j = 0; j < N; j++)
					a[i][j] = s.charAt(j)-'0';
			}
			int[] x = new int[N];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (a[i][j] == 1)
						x[i] = j;
			
			int ans = 0;
			for (int i=0; i<N; i++)
			{
				int t = -1;
				for (int j=i; j<N; j++)
					if (x[j]<=i)
					{
						t = j;
						break;
					}
				ans += t-i;
				int m = x[t];
				for (int j=t-1; j>=i; j--)
					x[j+1] = x[j];
				x[i] = m;
			}
			out.write("Case #"+ntest+": "+ans+"\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
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
		// Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}