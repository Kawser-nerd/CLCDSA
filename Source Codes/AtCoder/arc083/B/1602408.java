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

		int n=in.nextInt();
		long[][] distance=new long[n+1][n+1];
		long[][] distance2=new long[n+1][n+1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				distance[i][j]=in.nextLong();
				distance2[i][j]=distance[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					distance2[i][j]=min(distance2[i][j], distance2[i][k]+distance2[k][j]);
				}
			}
		}
		boolean ispossible=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(distance[i][j]!=distance2[i][j])
				{
					ispossible=false;
					break;
				}
			}
		}
		if(!ispossible)
		{
			out.println("-1");
			out.flush();
			return;
		}
		long answer=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				answer+=distance[i][j];
				for(int k=1;k<=n;k++)
				{
					if(k==i || k==j)
						continue;
					if(distance[i][k]+distance[k][j]==distance[i][j])
						{
						answer-=distance[i][j];
						break;
						}
				}
			}
		}
		out.println(answer/2);
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