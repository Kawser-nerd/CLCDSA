import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static long count(long val, Integer arr[][]) {
		long ret = 0;
		int n = arr[0].length;
		Integer a[] = arr[1];
		for (int i = 0 ; i < n ; ++i) {
			long cur = arr[0][i];
			long need = val / cur;
			if (val % cur == 0) --need;
			int lo = 0, hi = n - 1;
			int ans = -1;
			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (a[mid] <= need) {
					ans = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			++ans;
			ret += ans;
		}
		return ret;
	}


	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt();
		Integer arr[][] = new Integer[2][n];
		long top = 0;
		for (int i = 0 ; i < n ; ++i) {
			arr[0][i] = sc.nextInt();
			top = Math.max(top, arr[0][i]);
		}

		for (int i = 0 ; i < n ; ++i) {
			arr[1][i] = sc.nextInt();
			top = Math.max(top, arr[1][i]);
		}
		Arrays.sort(arr[0]);
		Arrays.sort(arr[1]);
		long maxValue = 1L*top*top;
		long lo = 0, hi = maxValue;
		long ans = 0;
		while (lo <= hi) {
			long mid = lo + (hi - lo ) / 2;
			if (count(mid,arr) <= k - 1) {
				lo = mid + 1;
				ans = mid;
			} else {
				hi = mid - 1;
			}
		}
		//long res = 0;
//		for (int i = 0 ; i < n ; ++i) {
//			long cur = ans / arr[0][i];
//			 lo = 0; hi = n - 1;
//			 long nxt = 0;
//			 while (lo <= hi) {
//				 int mid = (int) (lo + (hi - lo) / 2);
//				 if (arr[1][mid] <= cur) {
//					 lo = mid + 1;
//					 nxt = arr[1][mid];
//				 } else {
//					 hi = mid - 1;
//				 }
//				 
//			 }
//			 res = Math.max(res, 1L*nxt * arr[0][i]);
//		}
		System.out.println(ans);
	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
}