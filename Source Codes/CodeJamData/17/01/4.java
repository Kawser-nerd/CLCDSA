import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner input = new FastScanner();
		int n = input.nextInt();
		
		
		for (int x = 0; x < n; x++) {
			String in = input.next();
			int k = input.nextInt();
			char[] arr = in.toCharArray();
			int[] intArr = new int[in.length()];
			for(int a = 0; a < in.length(); a++){
				intArr[a] = (arr[a]=='+')?1:0;
			}
			
			int count = 0;
			for(int a = in.length()-1; a >= (k-1); a--){
				if(intArr[a] == 0){
					count++;
					for(int w = 0; w < k; w++){
						intArr[a-w] = 1-intArr[a-w];
					}
				}
			}

			
			String ans = "";
			boolean OK = true;
			for(int a = 0; a < k-1; a++){
				OK = OK && (intArr[a] == 1);
			}
			
			if(!OK){
				ans = "IMPOSSIBLE";
			}
			else{
				ans = count+"";
			}
			
			System.out.println("Case #" + (x+1) + ": " + ans);
		}
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(Reader in) {
			br = new BufferedReader(in);
		}

		public FastScanner() {
			this(new InputStreamReader(System.in));
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

		String readNextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextInt();
			}
			return a;
		}

		long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextLong();
			}
			return a;
		}
	}
}
