import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int H = scanner.nextInt();
    int W = scanner.nextInt();
    int T = scanner.nextInt();
    String[] str = new String[H];
    for(int i = 0; i < H; i++){
      str[i] = scanner.next();
    }
    char[][] map = new char[H][W];
    int startw = -1;
    int starth = -1;
    int goalw = -1;
    int goalh = -1;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        map[i][j] = str[i].charAt(j);
        if(map[i][j] == 'S'){
          starth = i;
          startw = j;
        }
        if(map[i][j] == 'G'){
          goalh = i;
          goalw = j;
        }
      }
    }
    int lb = 0;
    int ub = T;
    while(ub-lb > 1){
      int mid = (lb+ub)/2;
      long[][] time = new long[H][W];
      for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
          time[i][j] = Long.MAX_VALUE;
        }
      }
      Deque<Point> deq = new ArrayDeque<Point>();
      int[] mw = {0, 1, 0, -1};
      int[] mh = {1, 0, -1, 0};
      deq.add(new Point(starth, startw));
      time[starth][startw] = 0;
      while(!deq.isEmpty()){
        Point now = deq.poll();
        for(int i = 0; i < mw.length; i++){
          Point next = new Point(now.h+mh[i], now.w+mw[i]);
          if(next.w < 0 || next.w >= W || next.h < 0 || next.h >= H){
            continue;
          }
          int x = map[next.h][next.w] == '#' ? mid : 1;
          if(time[next.h][next.w] < time[now.h][now.w] + x){
            continue;
          }
          deq.add(new Point(next.h, next.w));
          time[next.h][next.w] = time[now.h][now.w] + x;
        }
      }
      if(time[goalh][goalw] > T){
        ub = mid;
      }else{
        lb = mid;
      }
    }
    System.out.println(lb);
  }
  static class Point{
    int h;
    int w;
    public Point(int h, int w){
      this.h = h;
      this.w = w;
    }
  }
}