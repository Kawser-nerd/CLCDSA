import java.util.Scanner;
import java.awt.Point;
import java.util.ArrayDeque;
public class Main{
	static int h;
	static int w;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		h = sc.nextInt();
		w = sc.nextInt();
		Point start=new Point(0,0);
		Point goal=new Point(0,0);
		char[][] map=new char[h][w];
		int[][] hei=new int[h][w];
		for(int i = 0; i<h; i++){
			String a=sc.next();
			for(int j = 0; j<w; j++){
				if(a.charAt(j)=='s'){
					start=new Point(j,i);
				}else if(a.charAt(j)=='g'){
					goal=new Point(j,i);
				}else{
					map[i][j]=a.charAt(j);
				}
				
			}
		}
		ArrayDeque<Point> q=new ArrayDeque<>();
		q.add(start);
		int[] dx={0,0,1,-1};
		int[] dy={1,-1,0,0};
		while(!q.isEmpty()){
			Point p=q.poll();
			for(int i=0; i<4; i++){
				if(judge(p.x+dx[i],p.y+dy[i],map)){
					if(map[p.y+dy[i]][p.x+dx[i]]=='#' && hei[p.y][p.x]==2){
						continue;
					}else if(map[p.y+dy[i]][p.x+dx[i]]=='#'){
						hei[p.y+dy[i]][p.x+dx[i]]=hei[p.y][p.x]+1;
						q.addLast(new Point(p.x+dx[i],p.y+dy[i]));
					}else{
						hei[p.y+dy[i]][p.x+dx[i]]=hei[p.y][p.x];
						q.addFirst(new Point(p.x+dx[i],p.y+dy[i]));
					}
					map[p.y+dy[i]][p.x+dx[i]]='X';
					if(map[goal.y][goal.x]=='X'){
						System.out.println("YES");
						return;
					}
				}
			}
		}
		System.out.println("NO");
	}
	static boolean judge(int x,int y,char[][] map){
		return x>=0 && y>=0 && x<w && y<h && !(map[y][x]=='X');
	}
}