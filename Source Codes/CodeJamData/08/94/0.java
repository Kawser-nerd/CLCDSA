import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemD {
	int[][] calcDst(String[] map, int stx, int sty) {
		int N = map.length, M = map[0].length();
		int[][] res = new int[N][M];
		for (int i=0; i<N; i++) Arrays.fill(res[i], -1);
		int[] qx = new int[N*M], qy = new int[N*M];
		int qBeg=0, qEnd=0;
		int[] dx = new int[] {-1, 1, 0, 0};
		int[] dy = new int[] {0, 0, -1, 1};
		qx[qBeg] = stx; qy[qBeg++] = sty;
		res[stx][sty] = 0;
		while (qEnd < qBeg) {
			int curx = qx[qEnd], cury = qy[qEnd++];
			for (int i=0; i<4; i++)
				if (curx+dx[i]>=0 && curx+dx[i]<N && cury+dy[i]>=0 &&
					cury+dy[i]<M && res[curx+dx[i]][cury+dy[i]]==-1 &&
					map[curx+dx[i]].charAt(cury+dy[i]) != '.') {
					qx[qBeg] = curx+dx[i];
					qy[qBeg++] = cury+dy[i];
					res[curx+dx[i]][cury+dy[i]] = res[curx][cury]+1;
				}
		}
		return res;
	}

	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum<=caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int N = sc.nextInt();
			int M = sc.nextInt();
			String[] map = new String[N];
			for (int i=0; i<N; i++) map[i] = sc.next();
			int tx1=0, ty1=0;
			int tx2=-1, ty2=-1;
			for (int i=0; i<N; i++) for (int j=0; j<M; j++)
				if (i+j>0 && map[i].charAt(j)=='T') {
					tx2=i; ty2=j;
				}
			if (tx2==-1 && ty2==-1) {
				int[][] dst1 = calcDst(map, tx1, ty1);
				int ans=0;
				for (int i=0; i<N; i++) for (int j=0; j<M; j++)
					if (map[i].charAt(j) != '.') {
						ans += dst1[i][j];
					}
				pw.println(ans);
				continue;
			}
			int[][] dst1 = calcDst(map, tx1, ty1);
			int[][] dst2 = calcDst(map, tx2, ty2);
			int ans = 0;
			int[][] price = new int[N][M];
			for (int i=0; i<N; i++) for (int j=0; j<M; j++)
				if (map[i].charAt(j) != '.') {
					ans += Math.min(dst1[i][j], dst2[i][j]);
					price[i][j] = dst1[i][j] - Math.min(dst1[i][j], dst2[i][j]);
				}
			int[][] cost = new int[N][M];
			boolean[][] used = new boolean[N][M];
			for (int i=0; i<N; i++) Arrays.fill(cost[i], 1000000000);
			cost[0][0] = price[0][0];
			while (true) {
				int minValue = 1000000000;
				int minX = -1, minY = -1;
				for (int i=0; i<N; i++) for (int j=0; j<M; j++)
					if (cost[i][j]<minValue && !used[i][j]) {
						minValue = cost[i][j];
						minX = i;
						minY = j;
					}
				used[minX][minY] = true;
				if (minX==tx2 && minY==ty2) break;
				int[] dx = new int[] {-1, 1, 0, 0};
				int[] dy = new int[] {0, 0, -1, 1};
				for (int i=0; i<4; i++)
					if (minX+dx[i]>=0 && minX+dx[i]<N && minY+dy[i]>=0 &&
						minY+dy[i]<M && map[minX+dx[i]].charAt(minY+dy[i]) != '.' &&
						cost[minX+dx[i]][minY+dy[i]]>minValue + price[minX+dx[i]][minY+dy[i]])
						cost[minX+dx[i]][minY+dy[i]] = minValue + price[minX+dx[i]][minY+dy[i]];
			}
			pw.println(ans + cost[tx2][ty2]);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemD()).doMain();
	}
}