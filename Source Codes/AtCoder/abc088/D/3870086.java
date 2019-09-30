import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int H = scanner.nextInt();
    int W = scanner.nextInt();
    String[] str = new String[H];
    for(int i = 0; i < H; i++){
      str[i] = scanner.next();
    }
    char[][] map = new char[H][W];
    int[][] d = new int[H][W];
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        map[i][j] = str[i].charAt(j);
        d[i][j] = -1;
      }
    }
    Deque<Point> deq = new ArrayDeque<Point>();
    d[0][0] = 0;
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};
    deq.add(new Point(0, 0));
    while(!deq.isEmpty()){
      Point now = deq.poll();
      for(int i = 0; i < 4; i++){
        Point next = new Point(now.x + dx[i], now.y + dy[i]);
        if(next.x < 0 || next.x >= H || next.y < 0 || next.y >= W){
          continue;
        }
        if(map[next.x][next.y] == '#'){
          continue;
        }
        if(d[next.x][next.y] != -1){
          continue;
        }
        d[next.x][next.y] = d[now.x][now.y] + 1;
        deq.add(next);
      }
    }
    int count = 1;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        if(map[i][j] == '#'){
          count++;
        }
      }
    }
    if(d[H-1][W-1] == -1){
      System.out.println(-1);
    }else{
      System.out.println(H*W-count-d[H-1][W-1]);
    }
  }
  static class Point{
    int x;
    int y;
    public Point(int x, int y){
      this.x = x;
      this.y = y;
    }
  }
}