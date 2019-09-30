import  java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    
    String[] s = sc.nextLine().split(" ");
    int H = Integer.parseInt(s[0]);
    int W = Integer.parseInt(s[1]);
    
    char[][] map = new char[H][W];
    int[][] route = new int[H][W];
    
    int dots = 0;
    for(int i = 0; i < H; i++){
      String str = sc.nextLine();
      for(int j = 0; j < W; j++){
        map[i][j] = str.charAt(j);
        if(i == 0 && j == 0){
          route[i][j] = 1;
          dots++;
        }else if(map[i][j] == '.'){
          route[i][j] = 0;
          dots++;
        }else{
          route[i][j] = -1;
        }
      } 
    }
    
    int[] ih = {+1, 0, -1, 0};
    int[] iw = {0, +1, 0, -1};
    
    Queue<Integer> qh = new ArrayDeque<>();
    Queue<Integer> qw = new ArrayDeque<>();
    qh.add(0);
    qw.add(0);
    boolean b = false;
    
    while(qh.size() > 0){
      int nh = qh.poll();
      int nw = qw.poll();
      
      if(nh == H - 1 && nw == W - 1){
        b = true;
        break;
      }
      
      for(int i = 0; i < 4; i++){
        int fh = nh + ih[i];
        int fw = nw + iw[i];
        
        if(fh >= 0 && fw >= 0 && fh < H && fw < W && route[fh][fw] == 0){
          qh.add(fh);
          qw.add(fw);
          route[fh][fw] = route[nh][nw] + 1;
        }
      }
    }
    if(b){
      System.out.println(dots - route[H-1][W-1]);
    }else{
      System.out.println(-1);
    }
  }
}