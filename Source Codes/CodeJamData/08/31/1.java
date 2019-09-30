import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "A-large";
	
	public void solve() throws Exception {
		int tests = iread();
		for (int t=1; t<=tests; t++)
		{
			int P = iread(), K = iread(), L = iread();
			long[] a = new long[L];
			for (int i=0; i<L; i++)
				a[i] = -iread();
			Arrays.sort(a);
			long ans = 0;
			for (int i=0; i<L; i++)
				ans+=(-a[i])*(i/K+1);
			out.write("Case #"+t+": "+ans+"\n");
		}
	}

	public void run() {
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
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
		//Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}
