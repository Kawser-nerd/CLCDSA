import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
	int n=sc.nextInt();
	int x[]=new int[n];
	int y[]=new int[n];
	int h[]=new int[n];
	int ansx=0;
	int ansy=0;
	int ansh=0;
	
	for (int i = 0; i < n; i++) {
		x[i]=sc.nextInt();
		y[i]=sc.nextInt();
		h[i]=sc.nextInt();
	}
	int tall=0;
	boolean top;
	
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			top=true;
			for (int k = 0; k < n; k++) {
				if(h[k]!=0) {
					if(tall==0) {
						tall=Math.abs(i-x[k])+Math.abs(j-y[k])+h[k];
					}else if(tall!=Math.abs(i-x[k])+Math.abs(j-y[k])+h[k]){
						top=false;
						
					}
				
				}
				
				if(k==n-1&&top){
					for(int g=0;g<n;g++) {
						if(h[g]!=Math.max(tall-Math.abs(i-x[g])-Math.abs(j-y[g]),0)) {
						top=false;
						
						}
					}
					if(top){
					ansx=i;
					ansy=j;
					ansh=tall;
				
					}
				}
				if(k==n-1){
					tall=0;
				}
			}
			
		}
	}
	System.out.println(ansx+" "+ansy+" "+ansh);
		
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