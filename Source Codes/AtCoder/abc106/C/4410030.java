import java.io.*;
import java.util.*;
import java.lang.*;
public class Main {
		
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		String s=sc.next();
		long k=sc.nextLong();
		int i;
		int l=s.length();
		int ans=1;
		
		for(i=0;i<l;i++) {
			if(k==0) {
				break;
						
			}
			if(ans==1&&s.charAt(i)!='1') {
				ans=s.charAt(i)-'0';
				
			}
			k--;
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