import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
		String s=sc.next();
		StringBuffer buf = new StringBuffer();
		
		int l=s.length();
		for(int i=0;i<l;i++) {
			switch(s.charAt(i)){
			case('1'):
				buf.append("1");
				break;
			case('0'):
				buf.append("0");
				break;
			case('B'):
				int a=buf.length();
				if(a!=0) {
					buf.deleteCharAt(a-1);
				}
				break;
			}
			
				
			
		}
		String ans = buf.toString();
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