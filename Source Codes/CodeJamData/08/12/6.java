package round1;

import java.io.*;
import java.util.*;

public class B2 {
	
	static int N, M;
	static boolean[] MS;
	static Vector<int[]>[] likes;
	
	static void clear(int k) {
		for (int i = 0; i < M; i++) {
			int j = 0;
			while (j < likes[i].size()) {
				int[] t = likes[i].elementAt(j);
				if (t[0] == k && t[1] == 0) likes[i].remove(j);
				else j++;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		//BufferedReader in = new BufferedReader(new FileReader("B-small.in"));
		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		//PrintWriter out = new PrintWriter(new FileWriter("B-small-out"));
		PrintWriter out = new PrintWriter(new FileWriter("B-large-out"));
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter out = new PrintWriter(System.out);
		
		int T = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= T; i++) {
			N = Integer.parseInt(in.readLine());
			M = Integer.parseInt(in.readLine());
			MS = new boolean[N];
			likes = new Vector[M];
			
			for (int j = 0; j < M; j++) {
				likes[j] = new Vector<int[]>();
				
				String[] L = in.readLine().split(" ");
				int C = Integer.parseInt(L[0]);
				for (int k = 0; k < 2*C; k += 2)
					likes[j].add(new int[]{Integer.parseInt(L[k+1])-1, Integer.parseInt(L[k+2])});
			}
			
			boolean one_more = false, imp = false;
			
			do {
			one_more = false;
			for (int j = 0; j < M; j++) {
				if (likes[j].size() == 0) {
					imp = true;
					break;
				}
				if (likes[j].size() == 1 && likes[j].firstElement()[1] == 1) {
					if (!MS[likes[j].firstElement()[0]]) {
						MS[likes[j].firstElement()[0]] = true;
						clear(likes[j].firstElement()[0]);
						one_more = true;
						break;
					}
				}
			}
			} while(one_more);
			
			out.print("Case #" + i + ":");
			if (imp) out.println(" IMPOSSIBLE");
			else {
				for (int j = 0; j < N; j++)
					out.print(" " + (MS[j] ? 1 : 0));
				out.println();
			}
		}
		
		out.flush();

	}

}
