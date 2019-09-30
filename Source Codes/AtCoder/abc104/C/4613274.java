import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

	void solve (FastScanner in, PrintWriter out) {

		int n = in.nextInt(), goal = in.nextInt();
		Problem[] p = new Problem[n];
		for (int i=0; i<n; i++) {
			p[i] = new Problem(in.nextLong(), (i+1)*100, in.nextLong());
		}

		long min = Long.MAX_VALUE;
		for (int i=0; i<(1<<n); i++) {

			int num = 0;
			long sum = 0L;

			int rightMost = -1;

			for (int j=n-1; j>=0; j--) {
				if ((1&i>>j) == 1) {
					sum += p[j].num * p[j].score + p[j].bonus;
					num += p[j].num;
				}
				else if ((1&i>>j) == 0 && rightMost == -1) {
					rightMost = j;
				}
			}

			if (sum >= goal) {
				min = Math.min(min, num);
				continue;
			}
			else if (rightMost != -1){
				if ((goal-sum+p[rightMost].score-1)/p[rightMost].score > p[rightMost].num) continue;
				else {
					min = Math.min(min, num + (goal-sum+p[rightMost].score-1)/p[rightMost].score);
				}
			}


		}
		
		
		
		out.println(min);

	}

	static class Problem {
		long num, score, bonus;
		Problem (long a, long b, long c) {
			num = a; score = b; bonus = c;
		}
	}

	public static void print (Object... ar) {
		System.out.println(Arrays.deepToString(ar));
	}



	public static void main(String[] args) {
		Main main = new Main();
		FastScanner in = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		main.solve(in, out);
		in.close();
		out.close();
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