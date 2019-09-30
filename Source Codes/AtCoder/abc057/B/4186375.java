import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
		int n=sc.nextInt();
		int m=sc.nextInt();
		int a[]=new int[n];
		int c[]=new int[m];
		int b[]=new int[n];
		int d[]=new int[m];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
		}
		for(int j=0;j<m;j++) {
			c[j]=sc.nextInt();
			d[j]=sc.nextInt();
		}
		int ans[]=new int[n];
		
		for(int i=0;i<n;i++) {
			int dis=400000000;
			ans[i]=60;
			for(int j=0;j<m;j++) {
				if(dis>Math.abs(a[i]-c[j])+Math.abs(b[i]-d[j])||(dis==Math.abs(a[i]-c[j])+Math.abs(b[i]-d[j])&&ans[i]>j+1)) {
					ans[i]=j+1;
					
					dis=Math.min(dis,Math.abs(a[i]-c[j])+Math.abs(b[i]-d[j]));
				}
			}	
			
		}
		for(int i=0;i<n;i++) {
			System.out.println(ans[i]);
		}
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