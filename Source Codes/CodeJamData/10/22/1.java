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
			
			int N = sc.nextInt(), K = sc.nextInt();
			long B = sc.nextLong(), T = sc.nextInt();
			
			long[] X = new long[N];
			long[] V = new long[N];
			
			boolean[] can = new boolean[N];
			
			for (int i=0; i<N; i++) X[i] = sc.nextLong();
			
			for (int i=0; i<N; i++) {
				V[i] = sc.nextLong();
				can[i] = X[i] + T * V[i] >= B;
			}
			
			int good = 0;
			int swaps = 0;
			
			for (int i=N-1; i>=0; i--)
				if (can[i] && good < K) {
					good++;
					for (int j=i+1; j<N; j++) if (!can[j]) swaps++;
				}
			
			if (good < K) pw.println("IMPOSSIBLE"); else pw.println(swaps);
			
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