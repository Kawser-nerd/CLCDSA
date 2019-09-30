import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {			
			pw.print("Case #" + caseNum + ": ");
			
			long L = sc.nextLong();
			
			int N = sc.nextInt();
			
			int[] B = new int[N];
			
			for (int i=0; i<N; i++)
				B[i] = sc.nextInt();
			
			Arrays.sort(B);
			
			int state = (int)(L % B[N-1]);
			
			int MOD = B[N-1];
			
			int[] best = new int[MOD];
			Arrays.fill(best, 1000000000);
			best[0] = 0;
			
			boolean[] known = new boolean[MOD];
		
			int[] Q = new int[2*MOD*N];
			int qBeg = MOD*N, qEnd = MOD*N;
			
			Q[qBeg++] = 0;
			
			while (qEnd < qBeg) {
				int x = Q[qEnd++];
				if (known[x]) continue;
				known[x] = true;
				
				for (int i=0; i<N-1; i++) {
					int next = x + B[i];
					if (next < MOD) {
						if (best[next] > best[x] + 1) {
							best[next] = best[x] + 1;
							Q[qBeg++] = next;
						}
					} else {
						if (best[next-MOD] > best[x]) {
							best[next-MOD] = best[x];
							Q[--qEnd] = next-MOD;
						}
					}
				}
			}
			
			if (best[state] == 1000000000)
				pw.println("IMPOSSIBLE");
			else
				pw.println(L / MOD + best[state]);
		
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}