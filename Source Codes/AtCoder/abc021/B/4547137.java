import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    String[] s = sc.nextLine().split(" ");
    int start = Integer.parseInt(s[0]);
    int goal = Integer.parseInt(s[1]);
    int K = Integer.parseInt(sc.nextLine());
    String[] t = sc.nextLine().split(" ");
    
    boolean[] b = new boolean[N];
    b[start-1] = b[goal-1] = true;
    
    for(int i = 0; i < K; i++){
      int n = Integer.parseInt(t[i]) - 1;
      if(b[n]){
        System.out.println("NO");
        System.exit(0);
      }else{
        b[n] = true;
      }
    }
    System.out.println("YES");
  }
}