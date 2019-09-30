import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
	
		MyScanner sc = new MyScanner();
		
		int p=sc.nextInt();
		int q=sc.nextInt();
		String a[]=new String[p];
		String b[]=new String[q];
		for(int i=0;i<p;i++) {
			a[i]=sc.next();
		}
		for(int i=0;i<q;i++) {
			b[i]=sc.next();
		}
		String ans="No";
		for(int i=0;i<=p-q&&ans!="Yes";i++) {
			for(int j=0;j<=p-q&&ans!="Yes";j++) {
				if(a[i].substring(j,j+q).equals(b[0])) {
					ans="Yes";
					for(int k=i;k<i+q;k++) {
						if(!a[k].substring(j,j+q).equals(b[k-i])) {
							
							ans="No";
						}
						
					}
				if(ans=="Yes") {
					break;
				}
				}
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