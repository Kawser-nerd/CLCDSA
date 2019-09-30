import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*

4
11 5 16 5 0 0
3 1 3 2 2 0
3 1 3 2 1 0
2 1 5 1 1 1

1
3 1 3 2 2 0

*/
public class c {
	static final int STDIO = 0, SMALL = 1, LARGE = 2;
	static int inType = STDIO;
	static int outType = SMALL;

	static int cureHealth, b, d;
	public static void main(String[] args) throws IOException {
		Scanner in = getScanner();
		PrintWriter out = getPrintWriter();
		int maxT = in.nextInt();
		for (int curT = 1; curT <= maxT; curT++) {
			int hd = in.nextInt(), ad = in.nextInt(), hk = in.nextInt(), ak = in.nextInt();
			cureHealth = hd;
			b = in.nextInt();
			d = in.nextInt();
			
			ans = inf;
			debuff(hd,ad,hk,ak,0);
			
			out.printf("Case #%d: ", curT);
			if(ans == inf)
				out.print("IMPOSSIBLE");
			else
				out.print(ans);
			
			out.println();
			if (inType != STDIO)
				System.out.println(curT + "/" + maxT);
		}

		out.close();
	}
	static int inf = (int) 1e8;
	static int ans;
	static void debuff(int hd, int ad, int hk, int ak, int turn) {
		for(int debuffAmt=0;debuffAmt <= 300;debuffAmt++) {
			buff(hd,ad,hk,ak,turn);
			if(hd - Math.max(0,(ak-d)) <= 0) {
				// cure
				turn++;
//				if(turn > ans) return;
				hd = cureHealth;
				hd -= ak;
				if(hd <= 0) break;
			}

			turn++;
//			if(turn > ans) return;
			ak -= d;
			if(ak < 0) ak = 0;
			
			hd -= ak;
			if(hd <= 0) break;
		}
	}
	static void buff(int hd, int ad, int hk, int ak, int turn) {
		for(int buffAmt=0;buffAmt <= 300;buffAmt++) {
			attack(hd,ad,hk,ak,turn);
			if(hd - ak <= 0) {
				// cure
				turn++;
//				if(turn > ans) return;
				hd = cureHealth;
				hd -= ak;
				if(hd <= 0) break;
			}
			
			turn++;
//			if(turn > ans) return;
			ad += b;

			hd -= ak;
			if(hd <= 0) break;
		}
	}
	static void attack(int hd, int ad, int hk, int ak, int turn) {
		for(int attackAmt=0;attackAmt <= 300;attackAmt++) {
			if(hd - ak <= 0 && hk-ad > 0) {
				// cure
				turn++;
				if(turn > ans) return;
				hd = cureHealth;
				hd -= ak;
				if(hd <= 0) break;
			}
//			if(turn > ans) return;
			turn++;
//			if(turn > ans) return;
			hk -= ad;
			if(hk <= 0) {
				ans = Math.min(ans, turn);
//				System.out.println("Won with " + hd + "," + ad + "," + hk + "," + ak + "," + turn);
				break;
			}
			hd -= ak;
			if(hd <= 0) break;
		}
	}

	
	static final String PROBLEM_LETTER = "C";
	static Scanner getScanner() throws IOException {
		if (outType != STDIO)
			inType = outType;
		if (inType == SMALL)
			return new Scanner(new File(PROBLEM_LETTER + "-small-attempt1.in"));
		else if (inType == LARGE)
			return new Scanner(new File(PROBLEM_LETTER + "-large.in"));
		return new Scanner(System.in);
	}

	static PrintWriter getPrintWriter() throws IOException {
		if (outType == SMALL) {
			System.out.println("WRITING TO " + PROBLEM_LETTER +  "-SMALL");
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
