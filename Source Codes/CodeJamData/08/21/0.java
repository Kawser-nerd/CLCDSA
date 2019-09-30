import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemA {
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			long n = sc.nextLong();
			long A = sc.nextLong();
			long B = sc.nextLong();
			long C = sc.nextLong();
			long D = sc.nextLong();
			long x0 = sc.nextLong();
			long y0 = sc.nextLong();
			long M = sc.nextLong();
			long[][] cnt = new long[3][3];
			Set<String> points = new HashSet<String>();
			long X = x0, Y = y0;
			for (int i=0; i < n; i++) {
				if (!points.contains(X+" "+Y)) {
					points.add(X+" "+Y);
					cnt[(int)(X%3)][(int)(Y%3)]++;
					X = (A * X + B) % M;
					Y = (C * Y + D) % M;
				}
			}
			long res = 0;
			for (int i=0; i < 9; i++)
				for (int j=i; j < 9; j++)
					for (int k=j; k < 9; k++) {
						if ((i/3+j/3+k/3) % 3 != 0) continue;
						if ((i%3+j%3+k%3) % 3 != 0) continue;
						long ci = cnt[i/3][i%3];
						long cj = cnt[j/3][j%3];
						long ck = cnt[k/3][k%3];
						if (i<j && j<k) {
							res += ci*cj*ck;
						} else if (i==j && j<k) {
							res += (ci * (cj - 1) * ck) / 2;
						} else if (i < j && j == k) {
							res += (ci * cj * (ck - 1)) / 2;
						} else {
							res += (ci * (cj - 1) * (ck - 2)) / 6;
						}
					}
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemA()).doMain();
	}
}
