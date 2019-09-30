import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int tc = nextInt();
		for (int tn = 1; tn <= tc; tn++) {
			int n = nextInt();
			int m = nextInt();
			char[][] q = new char[n][];
			for (int i = 0; i < n; i++)
				q[i] = nextLine().toCharArray();
			
			boolean ok = true;
			tile: while (true) {
				int minI = -1, minJ = -1;
				findMin: for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						if (q[i][j] == '#') {
							minI = i;
							minJ = j;
							break findMin;
						}
				
				if (minI == -1)
					break;

				for (int i = minI; i < minI + 2; i++)
					for (int j = minJ; j < minJ + 2; j++) 
						if (!(i >= 0 && i < n && j >= 0 && j < m) || q[i][j] != '#') {
							ok = false;
							break tile;
						}  

				q[minI][minJ] = q[minI + 1][minJ + 1] = '/';
				q[minI + 1][minJ] = q[minI][minJ + 1] = '\\';
			}

			out.println("Case #" + tn + ":");
			if (!ok)
				out.println("Impossible");
			else {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++)
						out.print(q[i][j]);
					out.println();
				}
			}
		}
		in.close();
		out.close();
	}

	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
