import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] dpmax = new int[N];
    int[] dpmin = new int[N];
    int d0 = sc.nextInt();
    dpmax[0] = d0;
    dpmin[0] = d0;
    for(int i = 1; i < N; i++) {
      int d = sc.nextInt();
      dpmax[i] = dpmax[i - 1] + d;
      if(d >= dpmin[i - 1] && d <= dpmax[i - 1]) {
      } else if(d < dpmin[i - 1]) {
        dpmin[i] = dpmin[i - 1] - d;
      } else {
        dpmin[i] = d - dpmax[i - 1];
      } 
    }
    System.out.println(dpmax[N - 1]);
    System.out.println(dpmin[N - 1]);
  }
}