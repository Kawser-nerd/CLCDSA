import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemB {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			pw.print("Case #" + caseNum + ":");
			int N = sc.nextInt();
			int colCnt = 0;
			String[] cols = new String[N];
			int[] colId = new int[N];
			int[] st = new int[N];
			int[] fn = new int[N];
			for (int i=0; i < N; i++) {
				String c = sc.next();
				boolean find = false;
				for (int j=0; j < colCnt; j++)
					if (cols[j].equals(c)) {
						colId[i] = j;
						find = true;
						break;
					}
				if (!find) {
					cols[colCnt++] = c;
					colId[i] = colCnt - 1;
				}
				st[i] = sc.nextInt();
				fn[i] = sc.nextInt();
			}
			for (int i=0; i+1 < N; i++)
				for (int j=0; j+1 < N; j++)
					if (fn[j] > fn[j+1]) {
						int tmp = fn[j]; fn[j] = fn[j+1]; fn[j+1] = tmp;
						tmp = st[j]; st[j] = st[j+1]; st[j+1] = tmp;
						tmp = colId[j]; colId[j] = colId[j+1]; colId[j+1] = tmp;
					}
			int res = 10000;
			int[] _st = new int[N];
			int[] _fn = new int[N];
			int NN;
			int[] F = new int[N];
			for (int a=0; a < colCnt; a++)
				for (int b=a; b < colCnt; b++)
					for (int c=b; c < colCnt; c++) {
						NN = 0;
						for (int i=0; i < N; i++)
							if (colId[i] == a || colId[i] == b || colId[i] == c) {
								_st[NN] = st[i];
								_fn[NN] = fn[i];
								NN++;
							}
						for (int i=0; i < NN; i++) {
							if (_st[i] == 1) {
								F[i] = 1;
							} else {
								F[i] = 10000;
								for (int j=0; j < i; j++)
									if (_fn[j] >= _st[i] - 1)
										F[i] = Math.min(F[i], F[j] + 1);
							}
							if (_fn[i] == 10000)
								res = Math.min(res, F[i]);
						}
					}
			pw.println(res == 10000 ? " IMPOSSIBLE" : " " + res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemB()).doMain();
	}
}