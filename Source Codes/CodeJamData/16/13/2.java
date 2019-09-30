import java.io.*;
import java.util.*;

public class C {
			public static int[] out;
			public static Map<Integer, Set<Integer>> in;
			public static int n;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int p = 0; p < N; p++) {
			n = Integer.parseInt(br.readLine());

			out = new int[n];
			in = new HashMap<Integer, Set<Integer>>();
			for(int i = 0; i < n; i++) in.put(i,new HashSet<Integer>());

			String[] s = br.readLine().split(" ");
			for(int i = 0; i < n; i++) {
				int v = Integer.parseInt(s[i]);
				v--;
				out[i] = v;
				in.get(v).add(i);
			}

			int[] tree = new int[n];
			int at = 0;

			int ret = 0;

			for(int i = 0; i < n; i++) {
				int count = 1;
				int cur = out[i];
				Set<Integer> visited = new HashSet<Integer>();
				visited.add(i);
				while(!visited.contains(cur)) {
					count++;
					visited.add(cur);
					cur = out[cur];
				}
				if(cur == i) {
					ret = Math.max(ret, count);
					if(count == 2) {
						tree[at] = i;
						at++;
					}
				}
			}

			int ret2 = 0;
			for(int i = 0; i < at; i++) {
				ret2 += bfs(tree[i]);
			}



			pw.println("Case #" + (p+1) + ": " + Math.max(ret,ret2));
		}


		pw.flush();
		pw.close();

	}

	public static int bfs(int i) {
		int[] q = new int[n];
		int[] layer = new int[n];
		int full = 0;
		int done = 0;
		int maxlayer = 1;

		q[0] = i;
		layer[0] = 1;
		full++;
		while(done<full) {
			for(int nbr : in.get(q[done])) {
				if(nbr == out[i]) continue;
				q[full] = nbr;
				layer[full] = layer[done]+1;;
				maxlayer = Math.max(maxlayer, layer[full]);
				full++;
			}
			done++;
		}
		return maxlayer;
	}
}