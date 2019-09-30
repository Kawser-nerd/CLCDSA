import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] ans = new int[6];
    for(int i = 0; i < N; i++) {
      double M = sc.nextDouble();
      double m = sc.nextDouble();
      if(M >= 35) ans[0]++;
      if(M >= 30 && M < 35) ans[1]++;
      if(M >= 25 && M < 30) ans[2]++;
      if(m >= 25) ans[3]++;
      if(m < 0 && M >= 0) ans[4]++;
      if(M < 0) ans[5]++;
    }
    for(int i = 0; i < 6; i++) {
      System.out.print(ans[i]);
      if(i < 5) System.out.print(" ");
    }
    System.out.println();
  }
}