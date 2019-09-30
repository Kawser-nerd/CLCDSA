import java.awt.*;
import java.util.*;

class Main{
	static int[] dx={0,1,0,-1},dy={-1,0,1,0};
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);

		int h=s.nextInt(),w=s.nextInt();
		char[][] f=new char[h][w];

		for(int i=0;i<h;++i)
			s.next().getChars(0,w,f[i],0);

		Point start=null,end=null;

		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				if(f[i][j]=='s')
					start=new Point(j,i);
				if(f[i][j]=='g')
					end=new Point(j,i);
			}
		}

		int[][] g=new int[h][w];
		g[start.y][start.x]=3;

		ArrayDeque<Point> q=new ArrayDeque<>();
		q.add(start);

		while(!q.isEmpty()){
			Point poll=q.pollFirst();
			for(int d=0;d<4;++d) {
				int y=poll.y+dy[d];
				int x=poll.x+dx[d];
				if(0<=y&&y<h&&0<=x&&x<w) {
					if(f[y][x]=='g') {
						System.out.println("YES");
						return;
					}
					
					if(f[y][x]=='.'&&g[poll.y][poll.x]>g[y][x]) {
						q.addFirst(new Point(x,y));
						g[y][x]=g[poll.y][poll.x];
					}
					if(f[y][x]=='#'&&g[poll.y][poll.x]-1>g[y][x]) {
						q.addLast(new Point(x,y));
						g[y][x]=g[poll.y][poll.x]-1;
					}
				}
			}
		}

		System.out.println("NO");
	}
}