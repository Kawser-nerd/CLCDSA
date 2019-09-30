import java.util.*;
import java.io.*;

public class CrazyRows {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println("solving case " + caseNum);
			// input
			int N = sc.nextInt();
			char[][] a = new char[N][N];
			for (int i=0; i < N; i++) {
				String s = sc.next();
				for (int j=0; j < N; j++)
					a[i][j] = s.charAt(j);
			}
			
			// solution
			int res = 0;
			for (int i=0; i < N; i++) {
				int last = -1;
				for (int j=0; j < N; j++)
					if (a[i][j] == '1') last = j;
				if (last <= i) continue;
				int chng = -1;
				for (int k=N-1; k > i; k--) {
					int last1 = -1;
					for (int j=0; j < N; j++)
						if (a[k][j] == '1') last1 = j;
					if (last1 <= i) chng = k;
				}
				res += (chng - i);
				for (int j=0; j < N; j++) {
					char tmp = a[chng][j];
					for (int k=chng; k > i; k--)
						a[k][j] = a[k-1][j];
					a[i][j] = tmp;
				}
			}
			
			// output
			pw.println("Case #" + caseNum + ": " + res);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new CrazyRows()).doMain();
	}
}