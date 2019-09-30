import java.util.*;
import java.lang.*;

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int N = Integer.parseInt(sc.next());
      int[] t = new int[N+1];
      int[] x = new int[N+1];
      int[] y = new int[N+1];
      for(int i = 1; i<N+1; i++){
        t[i] = Integer.parseInt(sc.next());
        x[i] = Integer.parseInt(sc.next());
        y[i] = Integer.parseInt(sc.next());
      }
      for(int i = 1; i<N+1; i++){
        int tdiff = t[i] - t[i-1];
        int xd = Math.abs(x[i]-x[i-1]);
        int yd = Math.abs(y[i]-y[i-1]);
        int dd = xd+yd;
        if(tdiff >= dd && ((tdiff-dd)%2)==0) continue;
        else{
          System.out.println("No");
          return;
        }
      }
      System.out.println("Yes");
  }
}