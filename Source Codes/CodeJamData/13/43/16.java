import java.io.*;
import java.util.*;

public class erdos {
	static BufferedReader in;
	static StringTokenizer st;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("erdos.in"));
		out = new PrintWriter(new FileWriter("erdos.out"));
		
		int tt = nextInt();
		for (int t=1; t<=tt; t++) {
			out.printf("Case #%d:", t);
			
			int num = nextInt();
			
			int[] inc = new int[num];
			int[] dec = new int[num];
			HashSet<Integer>[] greater = new HashSet[num];
			for (int i=0; i<num; i++)
				greater[i] = new HashSet<Integer>();
			for (int i=0; i<num; i++)
				inc[i] = nextInt();
			for (int i=0; i<num; i++)
				dec[i] = nextInt();
			
			for (int i=0; i<num; i++) {
				boolean found = false;
				for (int j=i-1; j>=0; j--) {
					if (!found && inc[j]+1==inc[i]) {
						found = true;
						greater[i].add(j);
					} else if (inc[j]>=inc[i])
						greater[j].add(i);
				}
				
				found = false;
				for (int j=i+1; j<num; j++) {
					if (!found && dec[j]+1==dec[i]) {
						found = true;
						greater[i].add(j);
					} else if (dec[j] >= dec[i])
						greater[j].add(i);
				}
			}
			
			HashSet<Integer>[] gCopy = new HashSet[num];
			for (int i=0; i<num; i++) {
				gCopy[i] = new HashSet<Integer>(greater[i]);
			}
			
			//topo sort
			int[] sorted = new int[num];
			boolean[] vis = new boolean[num];
			for (int i=0; i<num; i++)
				for (int j=0; j<num; j++) {
					if (!vis[j] && gCopy[j].size() == 0) {
						vis[j] = true;
						for (HashSet<Integer> g : gCopy)
							g.remove(j);
						sorted[i] = j;
						break;
					}
				}
			
			//trans closure
			for (int i=0; i<num; i++) {
				int ind = sorted[i];
				HashSet<Integer> copy = new HashSet<Integer>(greater[ind]);
				for (int o : copy)
					greater[ind].addAll(greater[o]);
			}
			
			//if you're not less, you're greater
			for (int i=0; i<num; i++) {
				for (int j=i+1; j<num; j++) {
					if (!greater[i].contains(j))
						greater[j].add(i);
				}
			}
			
			//topo sort
			int[] ans = new int[num];
			for (int i=1; i<=num; i++)
				for (int j=0; j<num; j++) {
					if (ans[j]==0 && greater[j].size() == 0) {
						ans[j] = i;
						for (HashSet<Integer> g : greater)
							g.remove(j);
						break;
					}
				}
			
			for (int i=0; i<num; i++)
				out.print(" "+ans[i]);
			out.println();
		}
		
		out.close();
		in.close();
	}
}
