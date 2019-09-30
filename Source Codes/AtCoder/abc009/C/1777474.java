import java.util.*;
import java.io.*;

public class Main {
	private static IO io = new IO();
	private static String S;
	private static char c[];

	public static void main(String[] args) {
		int n = io.nextInt();
		int k = io.nextInt();
		S = io.next();
		c = S.toCharArray();
		Arrays.sort(c);

		/*
		 * ?????????????(??????c????????????)????????????' '??????
		 * ??? k=3, S="program" (-> agmoprr) ????
		 * ???3???"aro"??????????4????????? ????????gmpr
		 * ??g???????????
		 * g??????????????????1????S??????????
		 * ???prog"ram"????????mpr????????????2????????????g????????????
		 */

		StringBuilder sb = new StringBuilder();
		root: for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[j]!=' ' && count(sb, c[j]) <= k) {
					sb.append(c[j]);
					c[j] = ' ';
					continue root;
				}
			}
		}

		System.out.println(sb.toString());
	}

	// T????ch?????????????????T????????????????S?????????????????
	private static int count(StringBuilder T, char ch) {
		int ans = 0;

		// ?????????????????????????????
		for (int i=0; i<T.length(); i++) {
			if (S.charAt(i)!=T.charAt(i)) ans++;
		}
		if (ch!=S.charAt(T.length())) ans++;

		// ???????????????????S?????????????????
		int a[] = new int[26];
		// ??????????????????
		for (char b:c) if (b!=' ') a[b-'a']++;
		// ch??????????????????????
		a[ch-'a']--;
		// ??????????????????????????????????
		// ?????????????????
		for (int i = T.length()+1; i < S.length(); i++) {
			int in = S.charAt(i)-'a';
			if (a[in]>0) a[in]--;
			else ans++;
		}
		return ans;
	}

	private static class IO extends PrintWriter {
		private final InputStream in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		public IO() { this(System.in);}
		public IO(InputStream source) { super(System.out); this.in = source;}
		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			}else{
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}
		private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
		private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
		private static boolean isNewLine(int c) { return c == '\n' || c == '\r';}
		private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
		private void skipNewLine() { while(hasNextByte() && isNewLine(buffer[ptr])) ptr++;}
		public boolean hasNext() { skipUnprintable(); return hasNextByte();}
		public boolean hasNextLine() { skipNewLine(); return hasNextByte();}
		public String next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public char[] nextCharArray(int len) {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			char[] s = new char[len];
			int i = 0;
			int b = readByte();
			while(isPrintableChar(b)) {
				if (i == len) {
					throw new InputMismatchException();
				}
				s[i++] = (char) b;
				b = readByte();
			}
			return s;
		}
		public String nextLine() {
			if (!hasNextLine()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(!isNewLine(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public long nextLong() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while(true){
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				}else if(b == -1 || !isPrintableChar(b)){
					return minus ? -n : n;
				}else{
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
		public int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
				throw new NumberFormatException();
			}
			return (int) nl;
		}
		public char nextChar() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			return (char) readByte();
		}
		public double nextDouble() { return Double.parseDouble(next());}
		public int[] arrayInt(int n) { int[] a = new int[n]; for(int i=0;i<n;i++) a[i] = nextInt(); return a;}
		public long[] arrayLong(int n) { long[] a = new long[n]; for(int i=0;i<n;i++) a[i] = nextLong(); return a;}
		public double[] arrayDouble(int n) { double[] a = new double[n]; for(int i=0;i<n;i++) a[i] = nextDouble(); return a;}
		public void arrayInt(int[]... a) {for(int i=0;i<a[0].length;i++) for(int j=0;j<a.length;j++) a[j][i] = nextInt();}
		public int[][] matrixInt(int n,int m) { int[][] a = new int[n][]; for(int i=0;i<n;i++) a[i] = arrayInt(m); return a;}
		public char[][] charMap(int n,int m) { char[][] a = new char[n][]; for(int i=0;i<n;i++) a[i] = nextCharArray(m); return a;}
		public void close() {
			super.close();
			try {
				in.close();
			} catch (IOException ignored) {}
		}
	}
}