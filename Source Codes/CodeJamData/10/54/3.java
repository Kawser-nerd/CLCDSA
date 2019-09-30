import java.util.*;
import java.io.*;
import java.math.*;

public class Sol_Slow {
	int cnt;
	int B;
	
	int[] A = new int[100];
	
	int[][] M = new int[100][20];
	
	boolean[] was = new boolean[30];
	
	void go(int left, int last, int pos) {
		if (left==0) {
			int maxLen = 0;
			for (int i=0; i<pos; i++) {
				Arrays.fill(M[i], -1);
				int len = 0;
				int tmp = A[i];
				while (tmp>0) {
					M[i][len++] = tmp % B;
					tmp /= B;
				}
				maxLen = Math.max(len, maxLen);
			}
			
			for (int col=0; col<maxLen; col++) {
				Arrays.fill(was, false);
				for (int i=0; i<pos; i++) {
					if (M[i][col] == -1) continue;
					if (was[M[i][col]])
						return;
					was[M[i][col]] = true;
				}
			}
			
			cnt++;
			
			return;
		}
		for (A[pos]=last+1; A[pos]<=left; A[pos]++)
			go(left-A[pos], A[pos], pos+1);
	}
	
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {			
			pw.print("Case #" + caseNum + ": ");
			
			int N = sc.nextInt();
			int B = sc.nextInt();
			
			cnt = 0;
			this.B = B;
			go(N, 0, 0);
			
			pw.println(cnt);
		
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Sol_Slow()).doMain();
	}
}