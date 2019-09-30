/*
 * ?????:LCM ?????:GCD
 *
 * ?? GCD(i,K) = GCD(i%K, K) ???????? ???N=53, K=10???
 * 1?53??10????2???? 2, 12, 22, 32, 42, 52 ?6??????????
 * ?GCD(2,10) = GCD(12,10) = ... = GCD(52,10) = 2
 * LCM(a,b) = a*b/GCD(a,b)???????????????6?????K?LCM???
 * ?2*10/2 + 12*10/2 + ... + 52*10/2
 * ?= (2 + 12 + ... + 52)*10/2  =  162*10/2 (?????????)
 * ?????0?K-1??????r?????1?N??K???????r????????l???????LCM(i,K)??????
 * ?????????O(KlogK)????????????K<=100?????????????????
 *
 * GCD(i,K)?K???????????K<=10^9???K????????1344???????GCD(i,K)???1?N???????????
 * ???N=41, K=12??? ??GCD(i,12)=1??????i(1, 5, 7, ...)???
 * ?(1?N??)-(1?N??2???????)-(1?N??3???????)+(??????????6?????)
 * ??????LCM(a,b) = a*b/GCD(a,b)???LCM(i,12)??????12/1??????????
 *
 * ??GCD(i,12)=2??????i??????? i=2j (j=1..20)?????
 * ?GCD(i,12) = 2*GCD(j,6)
 * ????GCD(j,6)=1???j???????LCM(j,6)???2?????????GCD(i,K)=1?????????
 *
 * ???K???d?????? "GCD(i,K)=d?????i???????LCM(i,K)??"?
 * ???? "GCD(j,K/d)=1?????j(1..N/d)???????LCM(j,K/d)???d?" ???????????
 */

import java.util.*;
import java.io.*;

public class Main {
    private static IO io = new IO();
    
    public static void main(String[] args) {

    	int N = io.nextInt();
    	int K = io.nextInt();
    	int M = 1000000007;

    	// K???????
    	List<Integer> div = new ArrayList<>();
	for (int i = 1; i <= Math.sqrt(K); i++) {
		if (K%i==0) {
			div.add(i);
			if (i!=K/i) div.add(K/i);
		}
	}
	Collections.sort(div);

	long ans = 0;
	long sum[] = new long[div.size()];
	for (int i = div.size()-1; i >= 0; i--) {
		int d = div.get(i);
		int dmax = N/d*d;	// 1..N???????d???
		sum[i] = (long)(d+dmax)*(N/d)/2;
		// ?????????????d??????????sum?????
		for (int j = i+1; j < div.size(); j++) {
			if (div.get(j)%d==0) sum[i] -= sum[j];
		}
		ans = (ans + sum[i]/d)%M;
	}

	ans = (ans*K)%M;
	System.out.println(ans);

    }

    private static class IO extends PrintWriter {
		private final InputStream in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;
		IO() {
			this(System.in);
		}
		IO(InputStream source) {
			super(System.out);
			this.in = source;
		}
		boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
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
		int readByte() {
			if (hasNextByte()) return buffer[ptr++];
			else return -1;
		}
		boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}
		boolean isNewLine(int c) {
			return c == '\n' || c == '\r';
		}
		void skipUnprintable() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
		}
		void skipNewLine() {
			while (hasNextByte() && isNewLine(buffer[ptr])) ptr++;
		}
		boolean hasNext() {
			skipUnprintable();
			return hasNextByte();
		}
		boolean hasNextLine() {
			skipNewLine();
			return hasNextByte();
		}
		String next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		char[] nextCharArray(int len) {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			char[] s = new char[len];
			int i = 0;
			int b = readByte();
			while (isPrintableChar(b)) {
				if (i == len) {
					throw new InputMismatchException();
				}
				s[i++] = (char) b;
				b = readByte();
			}
			return s;
		}
		String nextLine() {
			if (!hasNextLine()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isNewLine(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		long nextLong() {
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
			while (true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
		int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
				throw new NumberFormatException();
			}
			return (int) nl;
		}
		char nextChar() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			return (char) readByte();
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		int[] arrayInt(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}
		long[] arrayLong(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) a[i] = nextLong();
			return a;
		}
		double[] arrayDouble(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; i++) a[i] = nextDouble();
			return a;
		}
		void arrayInt(int[]... a) {
			for (int i = 0; i < a[0].length; i++) for (int j = 0; j < a.length; j++) a[j][i] = nextInt();
		}
		int[][] matrixInt(int n, int m) {
			int[][] a = new int[n][];
			for (int i = 0; i < n; i++) a[i] = arrayInt(m);
			return a;
		}
		char[][] charMap(int n, int m) {
			char[][] a = new char[n][];
			for (int i = 0; i < n; i++) a[i] = nextCharArray(m);
			return a;
		}
		public void close() {
			super.close();
			try {
				in.close();
			} catch (IOException ignored) {
			}
		}
	}
}