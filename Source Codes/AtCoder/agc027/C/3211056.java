import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		HashMap<Integer, ArrayList<Integer>> es = new HashMap<>();
		char[] s = new char[n+1];
		int[] degA = new int[n+1];
		int[] degB = new int[n+1];
		String str = sc.next();
		for(int i=1; i<=n; i++) es.put(i, new ArrayList<>());
		for(int i=1; i<=n; i++) {
			s[i] = str.charAt(i-1);
		}
		for(int _i=0; _i<m; _i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			es.get(a).add(b);
			es.get(b).add(a);
			if(s[a]=='A') {
				degA[b]++;
			} else {
				degB[b]++;
			}
			if(s[b]=='A') {
				degA[a]++;
			} else {
				degB[a]++;
			}
		}
		ArrayDeque<Integer> q = new ArrayDeque<>();
		boolean[] removed = new boolean[n+1];
		for(int i=1; i<=n; i++) {
			if(degA[i]<1||degB[i]<1) {
				q.add(i);
				removed[i] = true;
			}
		}
		while(!q.isEmpty()) {
			int v = q.poll();
			for(int next : es.get(v)) {
				if(s[v]=='A') {
					degA[next]--;
				} else {
					degB[next]--;
				}
				if(degA[next]<1||degB[next]<1) {
					if(!removed[next]) {
						q.add(next);
						removed[next] = true;
					}
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(!removed[i]) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
 	}

	static void printArray(int[] a) {
		int n=a.length;
		for(int i=0; i<n; i++) {
			if(i==0) System.out.print(a[i]);
			else System.out.print(" "+a[i]);
		}
		System.out.println();
	}

	static class MyScanner
	{
		BufferedReader br;
		StringTokenizer st;
		public MyScanner(InputStream s) 
		{
			br=new BufferedReader(new InputStreamReader(s));
		}
		public String nextLine() throws IOException
		{
			return br.readLine();
		}
		public String next() throws IOException
		{
			while(st==null || !st.hasMoreTokens())
				st=new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int nextInt() throws IOException
		{
			return Integer.parseInt(next());
			
		}
		public double nextDouble() throws IOException
		{
			return Double.parseDouble(next());
		}
		public boolean ready() throws IOException
		{
			return br.ready();
		}
		public long nextLong() throws IOException
		{
			return Long.parseLong(next());
		}
	}
}