// this is to be run with -Xmx512m

import java.util.*;
import java.io.*;

public class ProblemC {
	int myCmp(String a, String b) {
		if (a.length() != b.length()) return a.length()-b.length();
		return a.compareTo(b);
	}
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int MAXNUM = 750;
		
		long was = System.currentTimeMillis();
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			// input
			int W = sc.nextInt(), Q = sc.nextInt();
			char[][] sq = new char[W][W];
			for (int i=0; i < W; i++) {
				String s = sc.next();
				for (int j=0; j < W; j++)
					sq[i][j] = s.charAt(j);
			}
			
			// solution
			String[][][] bestSol = new String[W][W][2*MAXNUM + 1];
			
			int maxLen = W * W * (2 * MAXNUM + 1);
			int[] qI = new int[maxLen];
			int[] qJ = new int[maxLen];
			int[] qNum = new int[maxLen];
			int qBeg = 0, qEnd = 0;
			
			for (int i=0; i < W; i++)
				for (int j=0; j < W; j++)
					if ('0' <= sq[i][j] && sq[i][j] <= '9') {
						qI[qBeg] = i;
						qJ[qBeg] = j;
						qNum[qBeg++] = sq[i][j] - '0' + MAXNUM;
						bestSol[i][j][sq[i][j] - '0' + MAXNUM] = "" + (char)sq[i][j];
					}
			
			int[] dx = new int[] {1, -1, 0, 0};
			int[] dy = new int[] {0, 0, 1, -1};
			
			while (qEnd < qBeg) {
				int curI = qI[qEnd];
				int curJ = qJ[qEnd];
				int curNum = qNum[qEnd++];
				for (int a=0; a < 4; a++)
					for (int b=0; b < 4; b++) {
						int ii = curI + dx[a], jj = curJ + dy[a];
						int iii = ii + dx[b], jjj = jj + dy[b];
						if (ii < 0 || ii >= W || jj < 0 || jj >= W ||
							iii < 0 || iii >= W || jjj < 0 || jjj >= W)
							continue;
						int nextI = iii, nextJ = jjj;
						int add = sq[iii][jjj] - '0';
						int nextNum = curNum;
						if (sq[ii][jj] == '+')
							nextNum += add;
						else
							nextNum -= add;
						if (nextNum < 0 || nextNum >= 2 * MAXNUM) continue;
						String sol = bestSol[curI][curJ][curNum] + "" + (char)sq[ii][jj] + (char)sq[iii][jjj];
						if (bestSol[nextI][nextJ][nextNum] == null) {
							qI[qBeg] = nextI;
							qJ[qBeg] = nextJ;
							qNum[qBeg++] = nextNum;
							bestSol[nextI][nextJ][nextNum] = sol;
						}
						if (myCmp(sol, bestSol[nextI][nextJ][nextNum]) < 0)
							bestSol[nextI][nextJ][nextNum] = sol;
					}
			}
			
			// output
			pw.println("Case #" + caseNum + ":");
			for (int i=0; i < Q; i++) {
				int want = sc.nextInt();
				String res = null;
				for (int x=0; x < W; x++)
					for (int y=0; y < W; y++)
						if (bestSol[x][y][MAXNUM + want] != null) {
							if (res == null) {
								res = bestSol[x][y][MAXNUM + want];
							} else if (myCmp(bestSol[x][y][MAXNUM + want], res) < 0)
								res = bestSol[x][y][MAXNUM + want];
						}
				pw.println(res);
			}
		}
		
		System.out.println(System.currentTimeMillis() - was);
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemC()).doMain();
	}
}