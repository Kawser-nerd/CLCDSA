import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final long MOD = 1000000007;

	static void solve() throws IOException {
		int N = readInt();
		long A = readLong();
		long B = readLong();
		long[] a = readArrL(N);
		if (A == 1) {
			Arrays.sort(a);
			for (int i=0; i<N; i++) {
				System.out.print(a[i] + " ");
			}
			System.out.println();
		} else {
			int idx = 0;
			long max = a[0];
			for (int i=0; i<N; i++) {
				if (a[i] >= max) {
					idx = i;
					max = Math.max(max, a[i]);
				}
			}
			long j=0;
			for (; j<B; j++) {
				int idx2 = 0;
				long min = Long.MAX_VALUE;
				for (int i=0; i<N; i++) {
					if (a[i] < min) {
						idx2 = i;
						min = Math.min(min, a[i]);
					}
				}
				if (a[idx2]*A >= a[idx]) {
					break;
				}
				a[idx2] = a[idx2]*A;
			}
			if (j == B) {
				Arrays.sort(a);
				for (int i=0; i<N; i++) {
					System.out.print(a[i] + " ");
				}
				System.out.println();
			} else {
				long M = B - j;
				long t = M % N;
				long s = M / N;
				long p = pow(A, s+1);
				long q = pow(A, s);
				Arrays.sort(a);
				for (long i=t;i<N; i++) {
					System.out.print(((a[(int)i]*q)%MOD) + " ");
				}
				for (long i=0;i<t; i++) {
					System.out.print(((a[(int)i]*p)%MOD) + " ");
				}
				System.out.println();
			}
		}
	}

	static long pow(long a, long b) {
		long ans = 1;
		while(b>0) {
			if((b&1)!=0) {
				ans = (ans * a)%MOD;
			}
			b>>=1;
			a = (a*a)%MOD;
		}
		return ans;
	}


	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		tok = new StringTokenizer("");
		solve();
		out.close();
	}

	static String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine(), " .");
		}
		return tok.nextToken();
	}

	static int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	static long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}

	static int[] readArr(int n) throws IOException {
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = readInt();
		}
		return res;
	}

	static long[] readArrL(int n) throws IOException {
		long[] res = new long[n];
		for (int i = 0; i < n; i++) {
			res[i] = readLong();
		}
		return res;
	}

	static void readArr2(int[] A, int[] B) throws IOException {
		int n = A.length;
		for (int i = 0; i < n; i++) {
			A[i] = readInt();
			B[i] = readInt();
		}
	}

	static void readArrL2(long[] A, long[] B) throws IOException {
		int n = A.length;
		for (int i = 0; i < n; i++) {
			A[i] = readLong();
			B[i] = readLong();
		}
	}
}