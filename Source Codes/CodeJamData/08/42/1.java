import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemB {
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int N = sc.nextInt();
			int M = sc.nextInt();
			int A = sc.nextInt();
			if (A > N*M) {
				pw.println("IMPOSSIBLE");
				continue;				
			}
			int x2 = 1;
			int y1 = M;
			while (y1 * x2 < A) x2++;
			int x1 = 1;
			int y2 = x2 * y1 - A;
			pw.println(0+" "+0+" "+x1+" "+y1+" "+x2+" "+y2);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemB()).doMain();
	}
}