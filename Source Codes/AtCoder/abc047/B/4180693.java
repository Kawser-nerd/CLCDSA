import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
		int w =sc.nextInt();
		int h=sc.nextInt();
		int n=sc.nextInt();
		int x[]=new int[n];
		int y[]=new int[n];
		int a[]=new int[n];
		int x_l=w;
		int x_r=0;
		int y_b=h;
		int y_t=0;
		for(int i=0;i<n;i++) {
			x[i]=sc.nextInt();
			y[i]=sc.nextInt();
			a[i]=sc.nextInt();
			switch(a[i]) {
				case(1):
						if(x[i]>x_r) {
							x_r=x[i];
						}			
						break;
			
				case(2):
						if(x[i]<x_l) {
							x_l=x[i];
						}
						break;
			
				case(3):
						if(y[i]>y_t){
							y_t=y[i];
						}
						break;
			
				case(4):
						if(y[i]<y_b) {
							y_b=y[i];
						}
						break;
		
			}
		}
		
		int ans=0;
		if(!(y_t>=y_b||x_l<=x_r)) {
			ans=(x_l-x_r)*(y_b-y_t);
		}
		
		
		System.out.println(ans);
		
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