import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
  private static int N;
  private static int M;
  private static int gy;
  private static int gx;
  private static int sy;
  private static int sx;
  private static int[][] map;
  private static int[][] DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  private static int[][] len = new int[502][502];
  private static int[] bd = new int[10];
  private static ArrayDeque<Integer> queue = new ArrayDeque<>();

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    M = sc.nextInt();
    map = new int[N + 2][M + 2];
    for (int[] v : map) Arrays.fill(v, -1);
    for (int i = 1; i <= N; i ++) {
      String s = sc.next();
      for (int j = 1; j <= M; j ++) {
        char c = s.charAt(j - 1);
        int now;
        if (c == 's') {
          sy = i;
          sx = j;
          now = Integer.MAX_VALUE;
        } else if (c == 'g') {
          gy = i;
          gx = j;
          now = Integer.MAX_VALUE;
        } else if (c == '#') { 
          now = -1;
        } else {
          now = c - '0';
        }
        map[i][j] = now;
      }
    }
 
    if (!check(0)) {
      System.out.println(-1);
      return;
    }
    double left = 0;
    double right = 10;
    int max = 50;
    
    for (int i = 0; i < max && right - left > 1e-10; i ++) {
      double k = (left + right) / 2;
      if (check(k)) {
        left = k;
      } else {
        right = k;
      }
    }
    System.out.printf("%.12f\n", left);
  }

  //static long mem = 0;
  private static boolean check(double k) {
    for (int[] v: len) Arrays.fill(v, Integer.MAX_VALUE);
    queue.add(sy * 1000 + sx);
    len[sy][sx] = 0;
 
    for (int i = 1; i <= 9; i ++) {
      bd[i] = (int)Math.floor((Math.log(k) - Math.log(i)) / Math.log(0.99));
    }
    System.gc();
 
    boolean flg = false;
    while (queue.size() > 0) {
//      long now = Runtime.getRuntime().totalMemory()-Runtime.getRuntime().freeMemory();
//      if (mem < now) {
//        System.out.println(now + " " + queue.size());
//        mem = now;
//      }
      
      int v = queue.poll();
      int y = v / 1000;
      int x = v % 1000;
      
      for (int[] d : DIR) {
        int ny = y + d[0];
        int nx = x + d[1];
        int nlen = len[y][x] + 1;
        
        if (ny == gy && nx == gx) {
          queue.clear();
          flg = true;
          break;
        }
        if (len[ny][nx] == Integer.MAX_VALUE && map[ny][nx] >= 0 && map[ny][nx] <= 9 && bd[map[ny][nx]] >= nlen ) {
          len[ny][nx] = nlen;
          queue.add(ny * 1000 + nx);
        }
      }
    }
    return flg;
  }
  
}