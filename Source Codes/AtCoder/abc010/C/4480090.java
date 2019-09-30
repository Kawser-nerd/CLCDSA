import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int ax = Integer.parseInt(s[0]);
    int ay = Integer.parseInt(s[1]);
    int bx = Integer.parseInt(s[2]);
    int by = Integer.parseInt(s[3]);
    int T = Integer.parseInt(s[4]);
    int V = Integer.parseInt(s[5]);
    int n = Integer.parseInt(sc.nextLine());
    
    int dis = T * V;
    
    for(int i = 0; i < n; i++){
      int cx = sc.nextInt();
      int cy = sc.nextInt();
      int L1 = (ax - cx)*(ax - cx) + (ay - cy)*(ay - cy);
      int L2 = (bx - cx)*(bx - cx) + (by - cy)*(by - cy);
      double LD1 = Math.sqrt(L1);
      double LD2 = Math.sqrt(L2);
      double LD = LD1 + LD2;
      if(dis >= LD){
        System.out.println("YES");
        System.exit(0);
      }
    }
    System.out.println("NO");
  }
}