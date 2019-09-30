import java.io.*;
import java.text.DecimalFormat;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	
	double x[];
	double y[];
	double z[];
	double p[];
	public void solve() throws Exception {
		int n = iread();
		x = new double[n];
		y = new double[n];
		z = new double[n];
		p = new double[n];
		for(int i = 0; i < n; i++) {
			x[i] = dread();
			y[i] = dread();
			z[i] = dread();
			p[i] = dread();
		}
		double res = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				double dis = Math.abs(x[i]-x[j]) + Math.abs(y[i] - y[j]) + Math.abs(z[i] - z[j]);
				dis = dis / (p[i] + p[j]);
				res = Math.max(dis, res);
			}
		}
		DecimalFormat df = new DecimalFormat("0.0000000");
		out.write(df.format(res) + "\n");
	}
	
	public int iread() throws IOException {
		return Integer.parseInt(readword());
	}
	
	public double dread() throws IOException {
		return Double.parseDouble(readword());
	}
	
	public long lread() throws IOException {
		return Long.parseLong(readword());
	}
	
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) {
			c = in.read();
		}
		if( c < 0 ) return "";
		StringBuilder builder = new StringBuilder();
		while( c > ' ' ) {
			builder.append((char)c);
			c = in.read();
		}
		return builder.toString();
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader("input.txt"));
			out = new BufferedWriter( new FileWriter("output.txt"));
			int tn = iread();
			for(int tc = 1; tc <= tn; tc++) {
				out.write("Case #" + tc + ": ");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}

}
