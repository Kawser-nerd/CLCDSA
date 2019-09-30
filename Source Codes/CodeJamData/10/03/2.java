import java.io.*;
import java.util.*;


public class C {


	public static void main(String args[]) throws Exception {
		//String inFile = args[0];
		//String inFile = "C-example.in";
		//String inFile = "C-small-attempt0.in";
		String inFile = "C-large.in";
		String outFile = inFile + ".out";
		LineNumberReader lin = new LineNumberReader(new InputStreamReader(new FileInputStream(inFile)));
		PrintWriter out = new PrintWriter(new File(outFile));
		int NCASE = Integer.parseInt(lin.readLine());
		for(int CASE = 1; CASE <= NCASE; CASE++) {
			out.print("Case #" + CASE + ": ");
			String l = lin.readLine();
			String ll[] = l.split(" ");
			int R = Integer.parseInt(ll[0]);
			int k = Integer.parseInt(ll[1]);
			int N = Integer.parseInt(ll[2]);
			int g[] = new int[N];
			l = lin.readLine();
			ll = l.split(" ");
			for(int i = 0; i < N; i++)
				g[i] = Integer.parseInt(ll[i]);
			int sum[] = new int[N];
			int nn[] = new int[N];
			for(int i = 0; i < N; i++) {
				int s = 0, j = 0, n;
				do {
					n = (i + j) % N;
					int z = g[n];
					if(s + z > k)
						break;
					s += z;
				} while(++j < N);
				sum[i] = s;
				nn[i] = n;
			}
			long e = 0;
			int n = 0;
			for(int i = 0; i < R; i++) {
				e += sum[n];
				n = nn[n];
			}
			out.println(
				e//y
			);
		}
		lin.close();
		out.close();
	}
}