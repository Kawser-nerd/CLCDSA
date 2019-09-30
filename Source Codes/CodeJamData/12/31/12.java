import java.io.*;
import java.util.*;


public class A {
	
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-small.out"));
		int T = Integer.parseInt(in.readLine());
		for(int i=0; i<T; i++) {
			boolean adj[][] = new boolean[1005][1005];
			int N;
			String s = in.readLine();
			StringTokenizer st = new StringTokenizer(s);
			N = Integer.parseInt(st.nextToken());
			for(int r=0; r<N; r++) {
				s = in.readLine();
				st = new StringTokenizer(s);
				int M = Integer.parseInt(st.nextToken());
				for(int c=0; c<M; c++) {
					int d = Integer.parseInt(st.nextToken())-1;
					adj[r][d] = true;
				}
			}
			boolean ans = false;
			
			for(int n=0; n<N; n++) {
				
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(n);
				boolean v[] = new boolean[N];
				while(!q.isEmpty()) {
					int x = q.pollFirst();
					if(v[x]) { ans = true; break; }
					v[x] = true;
					for(int m=0; m<N; m++) {
						if(adj[x][m]) {
							q.addFirst(m); 
						}
					}
				}
			}
			
			
			out.println("Case #"+(i+1)+": "+(ans?"Yes":"No"));
		}
		out.close();
	}
}
