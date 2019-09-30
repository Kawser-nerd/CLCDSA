import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "B-large";
	
	int x1, y1, x2, y2;
	int N, M;
	int t;
	long A;
	public void check() throws Exception
	{
		//if (Math.abs(x1*y2-x2*y1)==A)
			out.write("Case #"+t+": 0 0 "+x1+" "+y1+" "+x2+" "+y2+"\n");
		//else out.write("BUG\n");
	}
	
	public void solve() throws Exception {
		int tests = iread();
		main:for (t = 1; t <= tests; t++) {
			N = iread(); M = iread();
			A = lread();
			if (A>N*M)
			{
				out.write("Case #"+t+": IMPOSSIBLE\n");
				continue;
			}
			a:for (x1 = N; x1>=0; x1--)
				for (y2 = M; y2>=0; y2--)
				{
					if (x1*y2<A) continue a;
					int A1 = x1*y2-(int)A;
					if (A1==0)
					{
						x2 = 0;
						y1 = 0;
						check();
						continue main;
					}
					for (int u = 1; u*u<=A1; u++)
					{
						if (A1%u>0) continue;
						int v = (int)A1/u;
						if (u<=N&&v<=M)
						{
							x2 = u; y1 = v;
							check();
							continue main;
						}
						if (v<=N&&u<=M)
						{
							x2 = v; y1 = u;
							check();
							continue main;
						}
					}
				}
			
			/*test:for (x1=0;x1<=N; x1++)
				for (y1=0;y1<=M; y1++)
					for (x2=0;x2<=N;x2++)
						for (int y2=0;y2<=M; y2++)
							if (Math.abs(x1*y2-x2*y1)==A)
							{
								out.write("BUG\n");
								break test;
							}*/
			out.write("Case #"+t+": IMPOSSIBLE\n");
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
