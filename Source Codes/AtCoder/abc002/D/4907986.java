import java.util.*;
 
public class Main{
  public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    
    boolean[][] rlist = new boolean[N][N];
    
    for(int i = 0; i < M; i++){
      int x = sc.nextInt() - 1;
      int y = sc.nextInt() - 1;
      rlist[x][y] = true;
      rlist[y][x] = true;
    }
    
    int r = 1;
    double n = Math.pow(2, N);
    
    for (int i = 1; i < n; i++) {
      
      ArrayList<Integer> alist = new ArrayList<Integer>();
      boolean valid = true;
      
      for (int j = 0; j < N; j++) {
        if ((1&i >> j) == 1) {
          alist.add(j);
        }
      }
      
      for (int j = 0; j < alist.size(); j++) {
        for (int k = j + 1; k < alist.size(); k++) {
          if (!rlist[alist.get(j)][alist.get(k)]) {
          	valid = false;
            break;
          }
        }
        if (!valid) {
          break;
        }
      }
      
      if (valid) {
        r = Math.max(r, alist.size());
      }
      
    }
    
    System.out.println(r);

  } 
}