import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int K = sc.nextInt() - 1;
		int[] a = new int[N];
		int[] b = new int[N];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt() - 1;
		}
		for (int i = 0; i < b.length; i++) {
			b[i] = sc.nextInt() - 1;
		}
		int mod = K % 6;
		int[] mid = null;
		switch (mod) {
			case 0:
				mid = a;
				break;
			case 1:
				mid = b;
				break;
			case 2:
				mid = compose(b, inv(a));
				break;
			case 3:
				mid = inv(a);
				break;
			case 4:
				mid = inv(b);
				break;
			case 5:
				mid = compose(inv(b), a);
				break;
		}
		int[] left;
		if (K < 3) {
			left = id(N);
		} else {
			int total = 1 + ((K - 3) / 3) * 2;
			if (K % 3 != 0) total++;
			int[] base = compose(b, compose(inv(a), compose(inv(b), a)));
			left = eleva(base, total / 4);
			if (total % 4 >= 1) {
				left = compose(left, b);
			}
			if (total % 4 >= 2) {
				left = compose(left, inv(a));
			}
			if (total % 4 >= 3) {
				left = compose(left, inv(b));
			}
		}
		int[] ret = compose(left, compose(mid, inv(left)));
		for (int i = 0; i < ret.length; i++) {
			if (i > 0) out.print(" ");
			out.print(ret[i] + 1);
		}
		out.println();
		out.flush();
	}
	
	static int[] inv(int[] a) {
		int[] ret = new int[a.length];
		for (int i = 0; i < ret.length; i++) {
			ret[a[i]] = i;
		}
		return ret;
	}
	
	static int[] compose(int[] a, int[] b) {
		int[] ret = new int[a.length];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = a[b[i]];
		}
		return ret;
	}
	
	static int[] id(int n) {
		int[] ret = new int[n];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = i;
		}
		return ret;
	}
	
	static int[] eleva(int[] a, int e) {
		if (e == 0) return id(a.length);
		int[] tmp = eleva(a, e / 2);
		tmp = compose(tmp, tmp);
		if (e % 2 == 1) {
			tmp = compose(tmp, a);
		}
		return tmp;
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}