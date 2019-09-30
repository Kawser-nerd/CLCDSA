import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemA {
	int[] dx = new int[] {0, -1, 0, 1};
	int[] dy = new int[] {1, 0, -1, 0};
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			pw.print("Case #" + caseNum + ": ");
			int[] minX = new int[6500];
			int[] maxX = new int[6500];
			int[] minY = new int[6500];
			int[] maxY = new int[6500];
			Arrays.fill(minX, 10000);
			Arrays.fill(maxX, -10000);
			Arrays.fill(minY, 10000);
			Arrays.fill(maxY, -10000);
			int curX=3200, curY=3200;
			int dir=0;
			int L = sc.nextInt();
			long area = 0;
			for (int t=0; t<L; t++) {
				String s = sc.next();
				int cnt = sc.nextInt();
				for (int tt=0; tt<cnt; tt++)
					for (int ttt=0; ttt<s.length(); ttt++) {
						char c = s.charAt(ttt);
						if (c=='L') dir=(dir+1)%4;
						else
						if (c=='R') dir=(dir+3)%4;
						else {
							if (dir==0) {
								minX[curY] = Math.min(minX[curY], curX);
								maxX[curY] = Math.max(maxX[curY], curX);
							} else if (dir==1) {
								minY[curX-1] = Math.min(minY[curX-1], curY);
								maxY[curX-1] = Math.max(maxY[curX-1], curY);
								area -= curY;
							} else if (dir==2) {
								minX[curY-1] = Math.min(minX[curY-1], curX);
								maxX[curY-1] = Math.max(maxX[curY-1], curX);
							} else {
								minY[curX] = Math.min(minY[curX], curY);
								maxY[curX] = Math.max(maxY[curX], curY);
								area += curY;
							}
							curX += dx[dir];
							curY += dy[dir];
						}
					}
			}
			area = Math.abs(area);
			int tot = 0;
			for (int x=0; x < 6500; x++) {
				for (int y=0; y < 6500; y++)
					if ((minY[x] <= y && y < maxY[x]) ||
						(minX[y] <= x && x < maxX[y])) {
						tot++;
					}
			}
			pw.println(tot - area);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemA()).doMain();
	}
}
