package aditsu.gcj.croptriangles;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CropTrianglesBig {
	private String getPath(final String file) {
		return "src/" + getClass().getPackage().getName().replace('.', '/') + '/' + file;
	}

	private BufferedReader getReader(final String file) throws IOException {
		return new BufferedReader(new FileReader(getPath(file)));
	}

	private PrintWriter getWriter(final String file) throws IOException {
		return new PrintWriter(getPath(file));
	}

	private PrintWriter getWriter() throws IOException {
		return getWriter("result.txt");
	}

	private static int toInt(final String s) {
		return Integer.parseInt(s);
	}
	
	private void go() throws IOException {
		final BufferedReader br = getReader("A-large.in");
		final PrintWriter w = getWriter();
		
		final int N = toInt(br.readLine());
		for (int i = 0; i < N; ++i) {
			final Scanner sc = new Scanner(br.readLine());
			final int n = sc.nextInt();
			final long a = sc.nextLong();
			final long b = sc.nextLong();
			final long c = sc.nextLong();
			final long d = sc.nextLong();
			final long x0 = sc.nextLong();
			final long y0 = sc.nextLong();
			final long m = sc.nextLong();
			final int[][] count = new int[3][3];
			for (int i1 = 0; i1 < 3; ++i1) {
				for (int i2 = 0; i2 < 3; ++i2) {
					count[i1][i2] = 0;
				}
			}
			long x = x0;
			long y = y0;
			for (int j = 0; j < n; ++j) {
				count[(int)x % 3][(int)y % 3]++;
				x = (a * x + b) % m;
				y = (c * y + d) % m;
			}
			long r = 0;
			for (int i1 = 0; i1 < 9; ++i1) {
				final int x1 = i1 % 3;
				final int y1 = i1 / 3;
				for (int i2 = 0; i2 < 9; ++i2) {
					final int x2 = i2 % 3;
					final int y2 = i2 / 3;
					final int x3 = (9 - x1 - x2) % 3;
					final int y3 = (9 - y1 - y2) % 3;
					final int i3 = y3 * 3 + x3;
					long q1 = count[x1][y1];
					long q2 = count[x2][y2];
					if (i1 == i2) {
						q2--;
					}
					long q3 = count[x3][y3];
					if (i1 == i3) {
						q3--;
					}
					if (i2 == i3) {
						q3--;
					}
					r += q1 * q2 * q3;
				}
			}
			w.println("Case #" + (i + 1) + ": " + r / 6);
		}
		w.flush();
	}

	public static void main(final String... args) throws IOException {
		new CropTrianglesBig().go();
	}
}
