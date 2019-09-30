import java.util.*;
import java.io.*;

public class Main {

	void solve (FastScanner in, PrintWriter out, Methods ms) {

		int n = in.nextInt();

		double max = Double.MIN_VALUE;
		for (int i=0; i<n; i++) {
			double sum = 0;
			for (int j=0; j<4; j++) {
				sum += in.nextDouble();
			}
			max = Math.max(max, sum+(in.nextDouble()*110.0/900.0));
		}
		
		out.println(String.format("%.5f", max));

	}



	public static void main(String[] args) {
		Main main = new Main();
		FastScanner in = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		Methods ms = new Methods();
		main.solve(in, out, ms);
		in.close();
		out.close();
	}

	static class Methods {

		public void print (Object... ar) {System.out.println(Arrays.deepToString(ar));}

		public void yesno (PrintWriter out, boolean b) {out.println(b?"Yes":"No");}

		public void YESNO (PrintWriter out, boolean b) {out.println(b?"YES":"NO");}

		public int max (int... ar) {Arrays.sort(ar); return ar[ar.length-1];}

		public int min (int... ar) {Arrays.sort(ar); return ar[0];}

		public int manhat (int x1, int y1, int x2, int y2) {
			int d = Math.abs(x1-x2)+Math.abs(y1-y2);
			return d;
		}

		public double euclid (double x1, double y1, double x2, double y2) {
			double d = Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
			return d;
		}

		public  boolean isPrime (int n) {
			if (n==2) return true;
			if (n<2 || n%2==0) return false;
			double d = Math.sqrt(n);
			for (int i=3; i<=d; i+=2) if(n%i==0){return false;}
			return true;
		}

		public boolean isPalindrome (String s) {
			int n = s.length();
			for (int i=0; i<n/2; i++) {
				if (s.charAt(i)!=s.charAt(n-i-1)) {return false;}
			}
			return true;
		}

	}

	static class FastScanner {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private  int length = 0, p = 0;

		public FastScanner (InputStream stream) {
			in = stream;
		}
		public boolean hasNextByte () {
			if (p < length) return true;
			else {
				p = 0;
				try {length = in.read(buffer);}
				catch (Exception e) {e.printStackTrace();}
				if (length <= 0) return false;
			}
			return true;
		}
		public int readByte () {
			if (hasNextByte() == true) return buffer[p++];
			return -1;
		}
		public boolean isPrintable (int n) {return 33<=n&&n<=126;}
		public void skip () {
			while (hasNextByte() && !isPrintable(buffer[p])) p++;
		}
		public boolean hasNext () {skip(); return hasNextByte();}
		public String next () {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int t = readByte();
			while (isPrintable(t)) {
				sb.appendCodePoint(t);
				t = readByte();
			}
			return sb.toString();
		}
		public String[] nextArray (int n) {
			String[] ar = new String[n];
			for (int i=0; i<n; i++) ar[i] = next();
			return ar;
		}
		public int nextInt () {return Math.toIntExact(nextLong());}
		public int[] nextIntArray (int n) {
			int[] ar = new int[n];
			for (int i=0; i<n; i++) ar[i] = nextInt();
			return ar;
		}
		public long nextLong () {
			if (!hasNext()) throw new NoSuchElementException();
			boolean minus = false;
			int temp = readByte();
			if (temp == '-') {
				minus = true;
				temp = readByte();
			}
			if (temp<'0' || '9'<temp) throw new NumberFormatException();
			long n = 0;
			while (isPrintable(temp)) {
				if ('0'<=temp && temp<='9') {
					n *= 10;
					n += temp - '0';
				}
				else throw new NumberFormatException();
				temp = readByte();
			}
			return minus? -n : n;
		}
		public double nextDouble () {
			return Double.parseDouble(next());
		}
		public void close () {
			try {in.close();}
			catch(Exception e){}
		}
	}

}