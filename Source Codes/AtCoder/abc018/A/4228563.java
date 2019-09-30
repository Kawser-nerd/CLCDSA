import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
		//String s=sc.next();
		//int a=sc.nextInt();
		//int b=sc.nextInt();
		//int c=sc.nextInt();
		//int l=s.length();
		int x[]=new int[3];
		x[0]=sc.nextInt();
		x[1]=sc.nextInt();
		x[2]=sc.nextInt();
		int a[]=new int[3];
		a[0]=x[0];
		a[1]=x[1];
		a[2]=x[2];
		Arrays.sort(x);
		int ans[]=new int[3];
		for(int i=0;i<3;i++) {
			if(a[i]>x[1]) {
				ans[i]=1;
			}
			else if(a[i]==x[1]) {
				ans[i]=2;
				
			}
			else {
				ans[i]=3;
			}
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