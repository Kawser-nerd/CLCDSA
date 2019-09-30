import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "A";
	//	final String filename = problem + "-sample";

//	 final String filename= problem+"-small-attempt0";
//	 final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	int res = 0;

	void check(char[] a) {
		int white = 0, black = 0, blank = 0;
		for (int i = 0; i < 4; i++)
			if (a[i] == 'X')
				white++;
			else if (a[i] == 'O')
				black++;
			else if (a[i] == '.')
				blank++;
		if (blank != 0)
			res |= 4;
		else {
			if (white == 0)
				res |= 1;
			if (black == 0)
				res |= 2;
		}
	}

	public void solve() throws Exception {
		char[][] t = new char[4][];
		for (int i = 0; i < 4; i++) {
			t[i] = readword().toCharArray();
		}
		res = 0;
		for (int i = 0; i < 4; i++) {
			check(t[i]);
			check(new char[] { t[0][i], t[1][i], t[2][i], t[3][i] });
		}
		check(new char[] { t[0][0], t[1][1], t[2][2], t[3][3] });
		check(new char[] { t[0][3], t[1][2], t[2][1], t[3][0] });
		if ((res & 1) != 0)
			out.write("O won");
		else if ((res & 2) != 0)
			out.write("X won");
		else if ((res & 4) != 0)
			out.write("Game has not completed");
		else
			out.write("Draw");
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
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
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}