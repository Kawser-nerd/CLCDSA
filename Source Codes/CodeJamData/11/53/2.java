import java.util.*;
import java.math.*;
import java.io.*;

public class Solution {
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println("Processing case " + caseNum);
			pw.print("Case #" + caseNum + ": ");
			
			int R = sc.nextInt();
			int C = sc.nextInt();
			
			char[][] map = new char[R][C];
			for (int i=0; i < R; i++)
				map[i] = sc.next().toCharArray();
			
			int[][] bottom = new int[R*C][8];
			int[] bottomCnt = new int[R*C];
			
			int[][] top = new int[R*C][8];
			int[] topCnt = new int[R*C];
			
			for (int i=0; i < R; i++)
				for (int j=0; j < C; j++) {
					int di = 0, dj = 0;
					if (map[i][j] == '-') {
						di = 0; dj = 1;
					} else if (map[i][j] == '|') {
						di = 1; dj = 0;
					} else if (map[i][j] == '\\') {
						di = -1; dj = -1;
					} else if (map[i][j] == '/') {
						di = -1; dj = 1;
					}
					int x1 = (i + di + R) % R;
					int y1 = (j + dj + C) % C;
					int x2 = (i - di + R) % R;
					int y2 = (j - dj + C) % C;
										
					int id = i * C + j;
					int id1 = x1 * C + y1;
					int id2 = x2 * C + y2;
					
					bottom[id][bottomCnt[id]++] = id1;
					bottom[id][bottomCnt[id]++] = id2;
					top[id1][topCnt[id1]++] = id;
					top[id2][topCnt[id2]++] = id;
					
//					System.out.println(id+" "+id1+" "+id2);
				}
			
			int MOD = 1000003;
			int res = 1;
			
			boolean[] usedTop = new boolean[R*C];
			boolean[] usedBottom = new boolean[R*C];
			
			while (true) {
				int minDeg = 1000000;
				int vert = -1;
				for (int i=0; i < R*C; i++)
					if (!usedTop[i] && topCnt[i] < minDeg) {
						minDeg = topCnt[i];
						vert = i;
					}
				
//				System.out.println(minDeg + " " + vert);
				
				if (minDeg == 0) {
					res = 0;
					break;
				}
				
				if (minDeg == 1) {
					usedTop[vert] = true;
					int btm = top[vert][0];
					usedBottom[btm] = true;
					
					for (int i=0; i < bottomCnt[btm]; i++) {
						int v = bottom[btm][i];
						for (int j=0; j < topCnt[v]; j++)
							if (top[v][j] == btm) {
								top[v][j] = top[v][topCnt[v]-1];
								topCnt[v]--;
								break;
							}
					}
					continue;
				}
				
				if (minDeg > 2) {
					System.out.println("failure");
					System.exit(0);
				}
				
				int[] Q = new int[2*R*C];
				for (int i=0; i < R*C; i++)
					if (!usedBottom[i]) {
						res = (2 * res) % MOD;
						
						int qBeg = 0, qEnd = 0;
						Q[qBeg++] = i;
						usedBottom[i] = true;
						
						while (qEnd < qBeg) {
							int curV = Q[qEnd++];
							if (curV < R*C) {
								for (int x=0; x < bottomCnt[curV]; x++) {
									int wh = bottom[curV][x];
									if (!usedTop[wh]) {
										usedTop[wh] = true;
										Q[qBeg++] = wh + R*C;
									}
								}
							} else {
								curV -= R*C;
								for (int x=0; x < topCnt[curV]; x++) {
									int wh = top[curV][x];
									if (!usedBottom[wh]) {
										usedBottom[wh] = true;
										Q[qBeg++] = wh;
									}
								}
							}
						}
					}
				
				break;
			}
			
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).go();
	}
}
