import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class BFF {
	public static void main(String [] args) throws IOException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		
		int cs = input.nextInt();
		for(int c = 1; c <= cs; c++) {
			cycle = -1;
			int sz = input.nextInt();
			ArrayList<Integer>[] adj = new ArrayList[sz+1];
			ArrayList<Integer> ref1 = new ArrayList<Integer>();
			ArrayList<Integer> ref2 = new ArrayList<Integer>();
			
			for(int i = 1; i < adj.length; i++)
				adj[i] = new ArrayList<Integer>();
			for(int x = 1; x <= sz; x++) {
				int temp = input.nextInt();
				adj[temp].add(x);
				if(adj[x].contains(temp)) {
					ref1.add(temp);
					ref2.add(x);
				}
			}
			int tot = 0;
			for(int i = 0; i < ref1.size(); i++) {
				tot += dfs(ref1.get(i), ref2.get(i), ref1.get(i), adj, 0) + dfs(ref2.get(i), ref1.get(i), ref2.get(i), adj, 0);
			}
			for(int i = 1; i < adj.length; i++)
				dfs(i, -1, i, adj, 1);
			out.printf("Case #%d: %d%n", c, Math.max(cycle, tot));
		}
		out.close();
	}
	static int cycle = -1;
	public static int dfs(int a, int b, int st, ArrayList<Integer>[] adj, int ct) {
		if(adj[a].size() == 0)
			return 1;
		int max = 0;
		for(int x : adj[a])
			if(x != b && x != st)
				max = Math.max(max, dfs(x, b, st, adj, ct+1));
			else if(x == st)
				cycle = Math.max(cycle, ct);
		return 1 + max;
	}
}
