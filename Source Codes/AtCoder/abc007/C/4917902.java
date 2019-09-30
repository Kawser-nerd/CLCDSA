import java.util.*;

class Main {
	public static void main(String[] args) {
		//data input
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt();
		int C = sc.nextInt();
		int sy = sc.nextInt();
		int sx = sc.nextInt();
		int gy = sc.nextInt();
		int gx = sc.nextInt();
		char[][] c = new char[R][C];
		int ans=0;
		for (int i=0;i<R;i++) {
			String S=sc.next();
			for (int j=0;j<C;j++) {
				c[i][j]=S.charAt(j);
			}
		}
		int[][] flag = new int[R][C];

		//DFS
		Queue<int[]> queue = new ArrayDeque<int[]>();
		int[] start = {sy,sx,0};
		queue.add(start);
		int[] dx = {1,-1,0,0};
		int[] dy = {0,0,1,-1};
		loop:while (!queue.isEmpty()) {
			int[] temp=queue.remove();
			int y=temp[0];
			int x=temp[1];
			int depth=temp[2];
			for (int i=0;i<4;i++) {
				if (flag[y+dy[i]-1][x+dx[i]-1]==0 && c[y+dy[i]-1][x+dx[i]-1]=='.') {
					flag[y+dy[i]-1][x+dx[i]-1]=1;
					int[] queue_add={y+dy[i],x+dx[i],depth+1};
					queue.add(queue_add);
				}
				if ((y+dy[i])==gy && (x+dx[i]==gx)) {
					ans=depth+1;
					break loop;
				}
			}
		}
		System.out.println(ans);
	}
}