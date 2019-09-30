import java.util.*;
public class Main {
  public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);
      long N = sc.nextLong();
      long M = sc.nextLong();
      long result = 0;
      //if (M >= 2) {
        if (N*2 <= M) {
          if ((M - N*2) >= 4) {
            result = ((M - N*2) / 4) + N;
          } else {
            result = N;
          }
        } else {
          result = M/2;
        }
        //} else {
        //result = 0;
        //}
      System.out.println(result);
  }
}