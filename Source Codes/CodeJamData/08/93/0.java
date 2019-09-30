import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemC {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum<=caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int R = sc.nextInt(), C = sc.nextInt();
			int[] S = new int[R];
			for (int i=0; i<R; i++)
				for (int j=0; j<C; j++) {
					int x = sc.nextInt();
					S[i] += x;
				}
			int sum = -1;
			int[] var = new int[R];
			Arrays.fill(var, -1000000);
			var[2] = S[1] - S[0];
			for (int i=5; i<R; i+=3) {
				var[i] = S[i-1] - S[i-2] + var[i-3];
			}
			var[R-3] = S[R-2] - S[R-1];
			for (int i=R-6; i>=0; i-=3) {
				var[i] = var[i+3] - S[i+2] + S[i+1];
			}
			if (var[R/2] != -1000000) sum = var[R/2];
			else if (var[R/2-1] != -1000000 && var[R/2+1] != -1000000)
				sum = S[R/2] - var[R/2-1] - var[R/2+1];
			else System.out.println("failure");
			if (sum % 3 == 0) {
				sum = sum / 3;
			} else if (sum % 3 == 1) {
				sum = (sum - 4) / 3 + 2;
			} else if (sum % 3 == 2) {
				sum = (sum - 2) / 3 + 1;
			}
			pw.println(sum);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemC()).doMain();
	}
}
