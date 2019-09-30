import java.awt.Point;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;
public class Main{
	static int INF=10000;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		Queue<Point> que =new ArrayDeque<>();
		int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1};
		int h=sc.nextInt();int w=sc.nextInt();
		int sx=sc.nextInt()-1;int sy=sc.nextInt()-1;
		int gx=sc.nextInt()-1;int gy=sc.nextInt()-1;
		int dist [][] = new int[h][w];
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)dist[i][j]=INF;
		char f[][]=new char[h][w];
		for(int i=0;i<h;i++) {
			f[i]=sc.next().toCharArray();
		}
		dist[sx][sy]=0;
		que.add(new Point(sx,sy));
		while(!que.isEmpty()) {
			Point p=que.poll();
			if(p.x==gx&&p.y==gy)break;
			for(int i=0;i<4;i++) {
				int nx=p.x+dx[i];int ny=p.y+dy[i];
				if(f[nx][ny]=='.'&&dist[nx][ny]==INF) {
				que.add(new Point(nx,ny));
				dist[nx][ny]=dist[p.x][p.y]+1;
				}
			}
		}
		System.out.println(dist[gx][gy]);
	}
}