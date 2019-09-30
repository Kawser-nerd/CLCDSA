import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Oppa implements Runnable {
	public static void main(String[] args) throws IOException {
		new Thread(new Oppa()).start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {

		}
	}

	private void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("bonus.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("bonus.out"));
		int T = sc.nextInt();sc.nextLine();
		String s = "welcome to code jam";
		for (int tn = 1; tn <= T; tn++) {
			String a = sc.nextLine();
			int n = a.length();
			int m = s.length();
			int[][] res = new int[n + 1][m + 1];
			for(int i = 0; i <= n; i++) res[i][0] = 1;
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= m; j++) {
					res[i][j] = res[i-1][j];
					if(s.charAt(j - 1) == a.charAt(i - 1)) res[i][j] += res[i-1][j-1];
					res[i][j] %= 10000;
				}
			String r = "" + res[n][m];
			while(r.length() < 4) r = "0" + r;
			pw.printf("Case #%d: ", tn);
			pw.println(r);
		}
		pw.close();
	}
	
	private int[] get(int[] cur, int[][][] next) {
		if(next[cur[0]][cur[1]][0] == cur[0] && next[cur[0]][cur[1]][1] == cur[1]) {
			return cur;
		}
		return next[cur[0]][cur[1]] = get(next[cur[0]][cur[1]], next);
	}
}
