import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		a=a%b;
		String ans="NO";
		for(int i=1;i<=b;i++) {
			if(a*i%b==c) {
				ans="YES";
			}
		}
		System.out.println(ans);
	}
	
	
	
//----------------------------------------------------------
	static int l_min(int[] a) {
		Arrays.sort(a);
		return a[0];
	}
	static int l_max(int[] a) {
		int l=a.length;
		Arrays.sort(a);
		return a[l-1];
	}
	public static PrintWriter out;

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

	}
	

}