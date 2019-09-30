import java.io.*;
import java.util.*;

public class _2016QualQD {

	public static void main(String args[]) throws Exception {
		InputReader in;
		PrintWriter w;
		boolean online = true;
		String fileName = "D-large";

		if (online) {
			in = new InputReader(new FileInputStream(new File(fileName + ".in")));
			w = new PrintWriter(new FileWriter(fileName + "Newout.txt"));
			//w = new PrintWriter(System.out);
		} else {
			in = new InputReader(System.in);
			w = new PrintWriter(System.out);
		}

		int T = in.nextInt();

		for (int t = 1; t <= T; t++) {
			
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();
			
			int min = k / c;
			if(k % c != 0)
				min++;
			
			w.print("Case #" + t + ":");
			
			if(s < min){
				w.println(" IMPOSSIBLE");
				continue;
			}
			
			ArrayList<Long> ans = new ArrayList<Long>();
			
			for(int i = 1; i <= (k/c); i++){
				long nowAns = get(k , c , c * (i - 1) + 1);
				ans.add(nowAns);
				w.print(" " + nowAns);
			}
			
			if(k % c != 0){
				int need = k % c;
				long here = get(k , need, 1 + k - (k % c));
				here = 1 + (here - 1) * pow(k, c - need);
				ans.add(here);
				w.print(" " + here);
			}
			
			if(pow(k , c) <= 500)
				System.out.println(check(ans, k , c));
			w.println();
		}

		w.close();
	}
	
	static long get(int k, int c, int s){
		long ans = 1;
		for(int i = 1, j = s; i <= c; i++, j++)
			ans += (j - 1) * pow(k, c - i);
		//System.out.println(k + " " + c + " " + s + " " + ans);
		return ans;
	}
	
	static long pow(long n, long c){
		if(c == 0)
			return 1;
		long ans = pow(n , c >> 1);
		ans *= ans;
		if( (c & 1) != 0)
			ans *= n;
		return ans;
	}
	
	static boolean check(ArrayList<Long> l, int k, int c){
		for(int i = 0; i < k; i++){
			StringBuilder s = new StringBuilder();
			for(int j = 0; j < k; j++)
				if(j == i)
					s.append('G');
				else
					s.append('L');
			//System.out.println(s);
			StringBuilder last = last(s , c);
			//System.out.println(last);
			boolean f = false;
			for(long x : l){
				if(last.charAt((int)(x-1)) == 'G'){
					f = true;
					break;
				}
			}
			if(!f)
				return false;
		}
		return true;
	}
	
	static ArrayList<Integer> pos(StringBuilder x, int c){
		StringBuilder l = last(x , c);
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for(int i = 0; i < l.length(); i++)
			if(l.charAt(i) == 'G')
				ans.add(i + 1);
		return ans;
	}
	
	static StringBuilder last(StringBuilder curr, int c){
		StringBuilder orig = new StringBuilder(curr);
		StringBuilder G = new StringBuilder();
		for(int i = 0; i < curr.length(); i++)
			G.append('G');
		for(int i = 2; i <= c; i++)
			curr = next(curr , orig, G);
		return curr;
	}
	
	static StringBuilder next(StringBuilder curr, StringBuilder orig, StringBuilder G){
		StringBuilder ans = new StringBuilder();
		for(int i = 0; i < curr.length(); i++)
			if(curr.charAt(i) == 'L')
				ans.append(orig);
			else
				ans.append(G);
		//System.out.println(curr + " " + ans);
		return ans;
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
