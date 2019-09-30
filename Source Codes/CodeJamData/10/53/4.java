import java.util.*;
import java.io.*;
import java.math.*;

public class Sol_slow {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {			
			pw.print("Case #" + caseNum + ": ");
			
			int C = sc.nextInt();
			
			int[] A = new int[C];
			int[] B = new int[C];
			
			int N = 0;
			
			for (int i=0; i<C; i++) {
				A[i] = sc.nextInt();
				B[i] = sc.nextInt();
				N += B[i];
			}
			
			int[] x = new int[N];
			
			int pos = 0;
			for (int i=0; i<C; i++)
				for (int j=0; j < B[i]; j++)
					x[pos++] = A[i];
			
			int cnt=0;
			while (true) {
				boolean find = false;
				Arrays.sort(x);
				for (int i=0; i+1 < N; i++)
					if (x[i]==x[i+1]) {
						x[i]--;
						x[i+1]++;
						find = true;
						cnt++;
						break;
					}
				if (!find) break;
			}
			
			pw.println(cnt);
		
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Sol_slow()).doMain();
	}
}