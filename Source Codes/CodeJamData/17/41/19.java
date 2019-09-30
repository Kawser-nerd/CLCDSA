import java.io.*;
import java.util.*;

/*


*/
public class a {
	static final int STDIO = 0, SMALL = 1, LARGE = 2;
	static int inType = STDIO;
	static int outType = LARGE;
	
	static int n,p;
	static Integer[][][][] memo;

	public static void main(String[] args) throws IOException {
		Scanner in = getScanner();
		PrintWriter out = getPrintWriter();
		int maxT = in.nextInt();
		for (int curT = 1; curT <= maxT; curT++) {
			n = in.nextInt();
			p = in.nextInt();
			int[] cnts = new int[4];
			for(int i=0;i<n;i++) {
				cnts[in.nextInt()%p]++;
			}
			memo = new Integer[4][101][101][101];
			int ans = cnts[0] + go(0, cnts[1], cnts[2], cnts[3]);
			
			
			out.printf("Case #%d: ", curT);
			out.println(ans);
			//// OUTPUT

			if (inType != STDIO)
				System.out.println(curT + "/" + maxT);
		}

		out.close();
	}
	static int go(int leftover, int cnt1, int cnt2, int cnt3) {
		if(memo[leftover][cnt1][cnt2][cnt3] != null)
			return memo[leftover][cnt1][cnt2][cnt3];
		int ans = 0;
		
		if(cnt1 != 0) {
			int tmp = go((leftover+1)%p,cnt1-1,cnt2,cnt3);
			if(leftover == 0)
				tmp++;
			ans = Math.max(ans, tmp);
		}
		if(cnt2 != 0) {
			int tmp = go((leftover+2)%p,cnt1,cnt2-1,cnt3);
			if(leftover == 0)
				tmp++;
			ans = Math.max(ans, tmp);
		}
		if(cnt3 != 0) {
			int tmp = go((leftover+3)%p,cnt1,cnt2,cnt3-1);
			if(leftover == 0)
				tmp++;
			ans = Math.max(ans, tmp);
		}
		return memo[leftover][cnt1][cnt2][cnt3] = ans;
	}

	static final String PROBLEM_LETTER = "A";

	static Scanner getScanner() throws IOException {
		if (outType != STDIO)
			inType = outType;
		if (inType == SMALL)
			return new Scanner(new File(PROBLEM_LETTER + "-small-attempt0.in"));
		else if (inType == LARGE)
			return new Scanner(new File(PROBLEM_LETTER + "-large.in"));
		return new Scanner(System.in);
	}

	static PrintWriter getPrintWriter() throws IOException {
		if (outType == SMALL) {
			System.out.println("WRITING TO " + PROBLEM_LETTER + "-SMALL");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-small.out"));
		} else if (outType == LARGE) {
			System.out.println("WRITING TO " + PROBLEM_LETTER + "-LARGE");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-large.out"));
		}
		return new PrintWriter(System.out);
	}
}
