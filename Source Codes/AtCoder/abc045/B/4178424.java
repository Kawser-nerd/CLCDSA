import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
		String s_a=sc.next();
		String s_b=sc.next();
		String s_c=sc.next();
		int la=s_a.length();
		int lb=s_b.length();
		int lc=s_c.length();
		int a=la;
		int b=lb;
		int c=lc;
		char turn='a';
		String ans=null;
		boolean end=false;
		while(!end) {
			switch(turn) {
			case('a'):
				if(a==0) {
					end=true;
					ans="A";
					break;
				}
				turn=s_a.charAt(la-a);
				a--;
				
				break;
				
				
			case('b'):
				if(b==0) {
					end=true;
					ans="B";
					break;
				}
				turn=s_b.charAt(lb-b);
				b--;
				
				break;
			
			case('c'):
				if(c==0) {
					end=true;
					ans="C";
					break;
				}
				turn=s_c.charAt(lc-c);
				c--;
		
				break;
			}
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