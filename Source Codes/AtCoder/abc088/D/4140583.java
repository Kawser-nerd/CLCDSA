import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;

public class Main {
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int H = scanner.nextInt();
		int W = scanner.nextInt();
		String[] s = new String[H];
		for(int i = 0; i < H; i++){
			s[i] = scanner.next();
		}
		char[][] map = new char[H][W];
		int countB = 0;
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				map[i][j] = s[i].charAt(j);
				if(map[i][j] == '#'){
					countB++;
				}
			}
		}
		int[] dx = {-1,0,1,0};
		int[] dy = {0,1,0,-1};
		Queue<Point> q = new ArrayDeque<Point>();
		int[][] dist = new int[H][W];
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				dist[i][j] = -1;
			}
		}
		q.add(new Point(0,0));
		dist[0][0] = 0;
		while(!q.isEmpty()){
			Point now = q.poll();
			for(int i = 0; i < 4; i++){
				Point next = new Point(now.y+dy[i], now.x+dx[i]);
				if(next.y<0 || next.y>=H || next.x<0 || next.x>=W) continue;
				if(map[next.y][next.x] == '#') continue;
				if(dist[next.y][next.x] != -1) continue;
				dist[next.y][next.x] = dist[now.y][now.x] + 1;
				q.add(new Point(next.y, next.x));
			}
		}
		if(dist[H-1][W-1] != -1){
			System.out.println(H*W-countB-dist[H-1][W-1]-1);
		}else{
			System.out.println(-1);
		}
	}
	static class Point{
		int y;
		int x;
		Point(int y, int x){
			this.y = y;
			this.x = x;
		}
	}
}