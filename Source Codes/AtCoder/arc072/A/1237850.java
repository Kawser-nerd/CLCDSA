//package ap;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;



public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InputReader scnr = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
int n=scnr.nextInt();
int ar[]=new int[n];
for(int i=0;i<n;i++){
	ar[i]=scnr.nextInt();
}
long ct1=0;
int sum=ar[0];
long ct=0;
sum=Math.min(-1, sum);
	ct+=Math.abs(sum-ar[0]);
	for(int i=1;i<n;i++){
		int temp=ar[i];
		temp=temp+sum;
		int x=temp;
		if(sum<0){
			temp=Math.max(temp,1);
			ct+=Math.abs(temp-x);
		sum=temp;
		}
		else{
			temp=Math.min(temp,-1);
			ct+=Math.abs(temp-x);
		sum=temp;
		}
	}
	sum=ar[0];
	sum=Math.max(1, sum);
	ct1+=Math.abs(sum-ar[0]);
	for(int i=1;i<n;i++){
		int temp=ar[i];
		temp=temp+sum;
		int x=temp;
		if(sum<0){
			temp=Math.max(temp,1);
			ct1+=Math.abs(temp-x);
		sum=temp;
		}
		else{
			temp=Math.min(temp,-1);
			ct1+=Math.abs(temp-x);
		sum=temp;
		}
	}
	out.println(Math.min(ct1, ct));
	


		
		
		
		out.close();
	}


	static class pair implements Comparable<pair> {
		int val;
		int index;

		@Override
		public int compareTo(pair arg0) {
			// TODO Auto-generated method stub
			return -1 * (this.val - arg0.val);
		}
	}

	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;

		public InputReader(InputStream st) {
			this.stream = st;
		}

		public int read() {
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
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
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

		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

	}

}