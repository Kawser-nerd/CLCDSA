import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "C-large";
	
	double max = 1000000.0;
	
	public void solve() throws Exception {
		int tests = iread();
		main:for (int t = 1; t <= tests; t++) {
			int N = iread();
			int[] x = new int[N], y = new int[N], z = new int[N], p = new int[N];
			for (int i=0; i<N; i++)
			{
				x[i] = iread(); y[i] = iread(); z[i] = iread(); p[i] = iread();
			}
			
			double low = 0.0, high = max*4.0;
			loop:while (high-low>5e-8)
			{
				double r = (low+high)/2.0;
				double[] bounds = new double[8];
				Arrays.fill(bounds, Double.MAX_VALUE);
				for (int i=0; i<N; i++)
				{
					for (int k=0; k<8; k++)
					{	
						double R = r*p[i];
						if ((k&1)>0) R-=x[i];
						else R+=x[i];
						if ((k&2)>0) R-=y[i];
						else R+=y[i];
						if ((k&4)>0) R-=z[i];
						else R+=z[i];
						bounds[k] = Math.min(bounds[k], R);
					}
					for (int k=0; k<4; k++)
						if (bounds[k]<-bounds[7-k])
						{
							low = r;
							continue loop;
						}
				}
				high = r;
			}
			double ans = (low+high)/2.0;
			DecimalFormat df = new DecimalFormat("0.########");
			out.write("Case #"+t+": "+df.format(ans)+"\n");
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
		Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}
