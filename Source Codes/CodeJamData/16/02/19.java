import java.io.*;
import java.util.*;

public class _2016QualQB {

	public static void main(String args[]) throws Exception {
		InputReader in;
		PrintWriter w;
		boolean online = true;
		String fileName = "B-large";

		if (online) {
			in = new InputReader(new FileInputStream(new File(fileName + ".in")));
			w = new PrintWriter(new FileWriter(fileName + "out.txt"));
		} else {
			in = new InputReader(System.in);
			w = new PrintWriter(System.out);
		}

		int T = in.nextInt();

		for (int t = 1; t <= T; t++) {
			
			char s[] = in.readString().toCharArray();
			int c = 1;
			for(int i = 1; i < s.length; i++)
				if(s[i] != s[i - 1])
					c++;
			
			int ans = 0;
			
			if(c % 2 == 0){
				if(s[0] == '-')
					ans = c - 1;
				else
					ans = c;
			}
			else{
				if(s[0] == '-')
					ans = c;
				else
					ans = c - 1;
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
