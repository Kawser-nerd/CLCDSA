import java.io.*;
import java.util.*;

public class _2016QualQA {

	public static void main(String args[]) throws Exception {
		InputReader in;
		PrintWriter w;
		boolean online = true;
		String fileName = "A-large";

		if (online) {
			in = new InputReader(new FileInputStream(new File(fileName + ".in")));
			w = new PrintWriter(new FileWriter(fileName + "out.txt"));
		} else {
			in = new InputReader(System.in);
			w = new PrintWriter(System.out);
		}

		int T = in.nextInt();

		for (int t = 1; t <= T; t++) {
			
			int n = in.nextInt();
			String ans = "INSOMNIA";			
			
			if(n != 0){
				boolean d[] = new boolean[10];
				int done = 0;
				int b = Integer.parseInt("90" + Integer.toString(n));
				for(int i = n; i <= b ; i += n){
					char s[] = Long.toString(i).toCharArray();
					for(char x : s){
						if(!d[x - '0']){
							done++;
							d[x - '0'] = true;
						}
					}
					if(done == 10){
						ans = Long.toString(i);
						break;
					}
				}
			}
			
			w.println("Case #" + t + ": " + ans);
		}

		w.close();
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
