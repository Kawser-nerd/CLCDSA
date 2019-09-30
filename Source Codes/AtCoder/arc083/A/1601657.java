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

		int a=in.nextInt();
		int b=in.nextInt();
		int c=in.nextInt();
		int d=in.nextInt();
		int e=in.nextInt();
		int f=in.nextInt();
		ArrayList<Integer> water=new ArrayList<>();
		ArrayList<Integer> sugar=new ArrayList<>();
		for(int i=0;100*a*i<=f;i++)
		{
			for(int j=0;100*b*j<=f;j++)
			{
				water.add(100*a*i+100*b*j);
			}
		}
		for(int i=0;i*c<=f;i++)
		{
			for(int j=0;j*d<=f;j++)
			{
				sugar.add(c*i+d*j);
			}
		}
		double maxdensity=0;
		int sugarmax=0;
		int watermax=0;
		for(int i : water)
		{
			for(int j : sugar)
			{
				double waterrequired=(double)(j*100)/((double)e);
				if(waterrequired>i || (i+j)>f)
					continue;
				double tempdensity=(double)(100*j*1.0)/(double)(i+j);
				//out.println(tempdensity);
				if(tempdensity>=maxdensity)
				{
					maxdensity=tempdensity;
					sugarmax=j;
					watermax=i;
				}
			}
		}
		out.println((sugarmax+watermax)+" "+sugarmax);
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