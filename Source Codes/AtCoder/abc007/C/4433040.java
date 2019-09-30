import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int H = Integer.parseInt(s[0]);
    int W = Integer.parseInt(s[1]);
    
    String[] t = sc.nextLine().split(" ");
    int sx = Integer.parseInt(t[0]) - 1;
    int sy = Integer.parseInt(t[1]) - 1;
    
    String[] u = sc.nextLine().split(" ");
    int gx = Integer.parseInt(u[0]) - 1;
    int gy = Integer.parseInt(u[1]) - 1;
    
    int[] ix = {-1, 0, +1, 0};
    int[] iy = {0, +1, 0, -1};
    
    char[][] maze = new char[H][W];
    int[][] route = new int[H][W];
    
    for(int i = 0; i < H; i++){
      String str = sc.nextLine();
      for(int j = 0; j < W; j++){
        maze[i][j] = str.charAt(j);
        if(maze[i][j] == '#'){
          route[i][j] = -1;
        }else{
          route[i][j] = 0;
        }
      }
    }
    
    Queue<Integer> qx = new ArrayDeque<>();
    Queue<Integer> qy = new ArrayDeque<>();
    
    qx.add(sx);
    qy.add(sy);
    
    while(qx.size() > 0){
      int nx = qx.poll();
      int ny = qy.poll();
      
      if(nx == gx && ny == gy){
        break;
      }
      for(int i = 0; i < 4; i++){
        int ax = nx + ix[i];
        int ay = ny + iy[i];
        if(ax >= 0 && ax < H && ay >= 0 && ay < W && 
             !(ax == sx && ay == sy) && route[ax][ay] == 0){
          qx.add(ax);
          qy.add(ay);
          route[ax][ay] = route[nx][ny] + 1;
        }
      }
    }
    System.out.println(route[gx][gy]);
  }
}