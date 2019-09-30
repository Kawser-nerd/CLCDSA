import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "B-large";
	final int mod = 2*3*5*7;
	int[] a;
	int n;
	long[][] res;
	
	public long rec(int k, int m)
	{
		if (res[k][m]>=0)
			return res[k][m];
		long ans = 0;
		int m1 = 0;
		for (int t=k; t<n; t++)
		{
			m1 = (m1*10+a[t])%mod;
			if (t<n-1)
				ans += rec(t+1, (m+m1)%mod) + rec(t+1, (m+mod-m1)%mod);
			else
			{
				int s = (m+m1)%mod;
				if (s%2==0||s%3==0||s%5==0||s%7==0)
					ans++;
			}
		}
		res[k][m] = ans;
		return ans;
	}
	
	public void solve() throws Exception {
		int tests = iread();
		for (int t=1; t<=tests; t++)
		{
			String s = readword();
			n = s.length();
			a = new int[n];
			for (int i=0; i<n; i++)
				a[i] = s.charAt(i)-'0';
			res = new long[n+1][2*3*5*7];
			for (int i=0; i<=n; i++)
				Arrays.fill(res[i], -1);
			long ans = rec(0, 0);
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
