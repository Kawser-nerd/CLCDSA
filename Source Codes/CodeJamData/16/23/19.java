package r1b2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int k = in.nextInt();
			String[][] s = new String[k][2];
			Map<String, Integer> o1 = new HashMap<>();
			Map<String, Integer> o2 = new HashMap<>();
			for (int i = 0; i < k; i++) {
				s[i][0] = in.next();
				o1.putIfAbsent(s[i][0], o1.size());
				s[i][1] = in.next();
				o2.putIfAbsent(s[i][1], o2.size());
			}
			
			m = o1.size();
			n = o2.size();
			graph = new boolean[m][n];
			seen = new boolean[n];
			matchL = new int[m];
			matchR = new int[n];
			for (int i = 0; i < k; i++) {
				int l = o1.get(s[i][0]);
				int r = o2.get(s[i][1]);
				graph[l][r] = true;
			}
			
			int mm = maximumMatching();
			int ans = mm + (o1.size() - mm) + (o2.size() - mm);
			ans = k - ans;
			out.println(ans);
		}

		out.flush();
	}
	
	static int m, n;
	static boolean[][] graph;
	static boolean seen[];
	static int matchL[];   //What left vertex i is matched to (or -1 if unmatched)
	static int matchR[];   //What right vertex j is matched to (or -1 if unmatched)

	static int maximumMatching() {
		//Read input and populate graph[][]
		//Set m to be the size of L, n to be the size of R
		Arrays.fill(matchL, -1);
		Arrays.fill(matchR, -1);

		int count = 0;
		for (int i = 0; i < m; i++) {
			Arrays.fill(seen, false);
			if (bpm(i)) count++;
		}
		return count;
	}
	
	static boolean bpm(int u) {
        //try to match with all vertices on right side
        for (int v = 0; v < n; v++) {
            if (!graph[u][v] || seen[v]) continue;
            seen[v] = true;
            //match u and v, if v is unassigned, or if v's match on the left side can be reassigned to another right vertex
            if (matchR[v] == -1 || bpm(matchR[v])) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }
}
