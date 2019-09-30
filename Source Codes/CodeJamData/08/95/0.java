import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemE {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum<=caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int N = sc.nextInt(), M = sc.nextInt();
			String[] s = new String[N];
			for (int i=0; i<N; i++) s[i] = sc.next();
			int[] cur = new int[1<<M], next = new int[1<<M];
			Arrays.fill(cur, -1000000);
			cur[0] = 0;
			for (int x=0; x<N; x++)
				for (int y=0; y<M; y++) {
					boolean canPut = (s[x].charAt(y) != '.');
					boolean canNotPut = (s[x].charAt(y) != '#');
					Arrays.fill(next, -1000000);
					for (int mask=0; mask<(1<<M); mask++) {
						int clearMask = mask & ((1<<M)-1-(1<<y));
						// not put
						if (canNotPut) {
							next[clearMask] = Math.max(next[clearMask], cur[mask]);
						}
						// put
						if (canPut) {
							clearMask |= (1<<y);
							int addScore = 4;
							if (y>0 && (mask & (1<<(y-1))) != 0) addScore-=2;
							if ((mask & (1<<y)) != 0) addScore-=2;
							next[clearMask] = Math.max(next[clearMask], cur[mask]+addScore);
						}
					}
					for (int mask=0; mask<(1<<M); mask++)
						cur[mask]=next[mask];
				}
			int res = -1000000;
			for (int mask=0; mask<(1<<M); mask++)
				res = Math.max(res, cur[mask]);
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemE()).doMain();
	}
}
