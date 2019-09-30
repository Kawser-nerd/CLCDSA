import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Task {
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
		new Task().run();
		out.close();
	}
	
	static BufferedReader br;
	static PrintWriter out;
	StringTokenizer st;
	static String taskName = "";
	
	String nline() {
		try {
			return br.readLine();
		} catch (Exception exc) {
			return  null;
		}
	}
	
	String ns() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(nline());
			}
			return st.nextToken();
		} catch (Exception exc) {
			return null;
		}
	}
	
	int ni() {
		return Integer.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}
	
	void pf(String format, Object ... obj) {
		out.printf(format, obj);
	}
	
	void pln() {
		out.println();
	}
	
	void pt(Object obj) {
		out.print(obj);
	}
	
	int[] make0(int[] ds) {
		int n = ds.length;
		for (int from = n - 2; from >= 0; from--) {
			int bestAt = -1;
			for (int i = from + 1; i < n; i++)
				if (ds[i] > ds[from])
					if (bestAt == -1 || ds[bestAt] > ds[i])
						bestAt = i;
			if (bestAt != -1) {
				int temp = ds[bestAt];
				ds[bestAt] = ds[from];
				ds[from] = temp;
				Arrays.sort(ds, from + 1, n);
				return ds;
			}
		}
		return null;
	}
	
	int[] make1(int[] ds) {
		int n = ds.length;
		int[] arr = new int[n + 1];
		for (int i = 1; i <= n; i++)
			arr[i] = ds[i - 1];
		Arrays.sort(arr);
		for (int i = 0; i <= n; i++) {
			if (arr[i] != 0) {
				arr[0] = arr[i];
				arr[i] = 0;
				return arr;
			}
		}
		return null;
	}
	
	void run() {
		//Place your code here
		int T = ni();
		for (int t = 1; t <= T; t++) {
			String s = ns();
			int[] ds = new int[s.length()];
			for (int i = 0; i < s.length(); i++)
				ds[i] = s.charAt(i) - '0';
			
			int[] res = make0(ds);
			if (res == null)
				res = make1(ds);
			
			out.printf("Case #%d: ", t);
			for (int i = 0; i < res.length; i++)
				out.print(res[i]);
			out.println();
			
		}
		
	}
}