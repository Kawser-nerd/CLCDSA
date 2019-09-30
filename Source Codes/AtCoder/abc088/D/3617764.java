import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int H = in.nextInt();
		int W = in.nextInt();
		int INF = 100000;
		int[][] s = new int[H][W];
		int alreadyBlack = 0;
		for(int i=0;i<H;i++) {
			String str = in.next();
			for(int j=0;j<W;j++) {
				if(str.charAt(j)=='.') s[i][j] = INF;
				else {
					s[i][j] = -1;
					alreadyBlack++;
				}
			}
		}
		in.close();
		Queue<int[]> que = new ArrayDeque<>();
		s[0][0] = 1;
		int[] start = {0,0};
		que.add(start);
		while(s[H-1][W-1]==INF && !que.isEmpty()) {
			int[] now = que.poll();
			int x = now[0];
			int y = now[1];
			if(x-1>=0 && y>=0 && s[x-1][y]!=-1 && s[x-1][y]>s[x][y]+1) {
				s[x-1][y] = s[x][y]+1;
				int[] tmp = {x-1,y};
				que.add(tmp);
			}
			if(x+1<H && y>=0 && s[x+1][y]!=-1 && s[x+1][y]>s[x][y]+1) {
				s[x+1][y] = s[x][y]+1;
				int[] tmp = {x+1,y};
				que.add(tmp);
			}
			if(x>=0 && y-1>=0 && s[x][y-1]!=-1 && s[x][y-1]>s[x][y]+1) {
				s[x][y-1] = s[x][y]+1;
				int[] tmp = {x,y-1};
				que.add(tmp);
			}
			if(x>=0 && y+1<W && s[x][y+1]!=-1 && s[x][y+1]>s[x][y]+1) {
				s[x][y+1] = s[x][y]+1;
				int[] tmp = {x,y+1};
				que.add(tmp);
			}
		}
		if(s[H-1][W-1]==INF) System.out.println(-1);
		else System.out.println(H*W-alreadyBlack-s[H-1][W-1]);
	}

}