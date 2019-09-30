package aditsu.gcj.mousetrap;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Mousetrap {
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
		final BufferedReader br = getReader("C-small-attempt0.in");
		final PrintWriter w = getWriter();
		
		final int t = toInt(br.readLine());
		for (int i = 0; i < t; ++i) {
			final int k = toInt(br.readLine());
			final Scanner sc = new Scanner(br.readLine());
			final int n = sc.nextInt();
			final int[] ind = new int[n];
			for (int j = 0; j < n; ++j) {
				ind[j] = sc.nextInt();
			}
			final int[] c = new int[k];
			int q = -1;
			final int[] s = new int[k];
			Arrays.fill(s, 0);
			for (int j = 0; j < k; ++j) {
				final int m = j % (k - j);
				for (int x = 0; x <= m; ++x) {
					do {
						q = (q + 1) % k;
					} while (s[q] == 1);
				}
				c[q] = j;
//				System.out.println(q + "->" + j);
				s[q] = 1;
			}
			w.print("Case #" + (i + 1) + ":");
			for (int j = 0; j < n; ++j) {
				w.print(" " + (c[ind[j] - 1] + 1));
			}
			w.println();
		}
		w.flush();
	}

	public static void main(final String... args) throws IOException {
		new Mousetrap().go();
	}
}
