import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemA {
	int[] s = new int[20000];

	public void add(int pos) {
		while (pos < 20000) {
			s[pos]++;
			pos = (pos | (pos-1)) + 1;
		}
	}

	public int getSum(int pos) {
		int sum = 0;
		while (pos > 0) {
			sum += s[pos];
			pos &= pos - 1;
		}
		return sum;
	}

	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum<=caseCnt; caseNum++) {
			System.out.println(caseNum);
			pw.print("Case #" + caseNum + ": ");
			int N = sc.nextInt();
			int[] a = new int[N], b = new int[N], c = new int[N];
			for (int i=0; i < N; i++) {
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
				c[i] = sc.nextInt();
			}
			for (int i=0; i+1 < N; i++)
				for (int j=0; j+1 < N; j++)
					if (b[j] > b[j+1]) {
						int tmp=a[j]; a[j]=a[j+1]; a[j+1]=tmp;
						tmp=b[j]; b[j]=b[j+1]; b[j+1]=tmp;
						tmp=c[j]; c[j]=c[j+1]; c[j+1]=tmp;
					}
			int res = 0;
			for (int x=0; x < N; x++) {
				int A = a[x];
				Arrays.fill(s, 0);
				for (int y=0; y < N; y++) {
					if (a[y] > a[x]) continue;
					int B = b[y];
					int C = 10000 - A - B;
					if (C < 0) continue;
					add(c[y] + 1);
					res = Math.max(res, getSum(C + 1));
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
