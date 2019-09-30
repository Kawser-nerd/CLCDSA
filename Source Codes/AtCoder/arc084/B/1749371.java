/**
 * DA-IICT
 * Author : PARTH PATEL
 */
import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.fill;
import static java.lang.Math.*;
import static java.util.Arrays.sort;
import static java.util.Collections.sort;


public class Main{

	public static int mod = 1000000007;
	static FasterScanner in = new FasterScanner();
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {

		int k=in.nextInt();
		int[] distance=new int[k+1];
		Arrays.fill(distance, mod);
		Deque<Integer> queue=new LinkedList<>();
		distance[1]=0;
		queue.addLast(1);
		while(!queue.isEmpty())
		{
			int x=queue.poll();
			if(distance[(x+1)%k]>distance[x]+1)
			{
				distance[(x+1)%k]=distance[x]+1;
				queue.addLast((x+1)%k);
			}
			if(distance[(10*x)%k]>distance[x])
			{
				distance[(10*x)%k]=distance[x];
				queue.addFirst((10*x)%k);
			}
		}
		out.println(distance[0]+1);
		out.close();

	}

	public static long pow(long x, long n, long mod) {
		long res = 1;
		for (long p = x; n > 0; n >>= 1, p = (p * p) % mod) {
			if ((n & 1) != 0) {
				res = (res * p % mod);
			}
		}
		return res;
	}

	public static long gcd(long n1, long n2) {
		long r;
		while (n2 != 0) {
			r = n1 % n2;
			n1 = n2;
			n2 = r;
		}
		return n1;
	}

	public static long lcm(long n1, long n2) {
		long answer = (n1 * n2) / (gcd(n1, n2));
		return answer;
	}

	static class FasterScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int snumChars;

		public int read() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextLong();
			}
			return arr;
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}

}