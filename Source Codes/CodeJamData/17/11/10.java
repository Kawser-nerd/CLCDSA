import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner input = new FastScanner();
		int n = input.nextInt();
		for (int x = 0; x < n; x++) {
			int rows = input.nextInt();
			int columns = input.nextInt();
			char[][] arr = new char[rows][columns];
			for(int a  = 0; a < rows; a++){
				String ra = input.next();
				for(int b = 0; b < columns; b++){
					arr[a][b] = ra.charAt(b);
				}
			}
			for(int k = 0; k < 50; k++){
				for(int a = 0; a < rows-1; a++){
					for(int b = 0; b < columns; b++){
						if(arr[a][b] != '?' && arr[a+1][b] == '?'){
							arr[a+1][b] = arr[a][b];
						}
					}
				}
			}
			for(int k = 0; k < 50; k++){
				for(int a = rows-1; a >= 1; a--){
					for(int b = 0; b < columns; b++){
						if(arr[a][b] != '?' && arr[a-1][b] == '?'){
							arr[a-1][b] = arr[a][b];
						}
					}
				}
			}
			for(int k = 0; k < 50; k++){
				for(int a = 0; a < rows; a++){
					for(int b = 0; b < columns-1; b++){
						if(arr[a][b] != '?' && arr[a][b+1] == '?'){
							arr[a][b+1] = arr[a][b];
						}
					}
				}
			}
			for(int k = 0; k < 50; k++){
				for(int a = 0; a < rows; a++){
					for(int b = columns-1; b >= 1; b--){
						if(arr[a][b] != '?' && arr[a][b-1] == '?'){
							arr[a][b-1] = arr[a][b];
						}
					}
				}
			}
			
			
			System.out.println("Case #" + (x+1) + ":");
			for(int a = 0; a < rows; a++){
				System.out.println(arr[a]);
			}
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
