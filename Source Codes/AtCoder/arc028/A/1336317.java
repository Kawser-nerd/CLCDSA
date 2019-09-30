import java.util.*;
public class Main {
  public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);
         int N = sc.nextInt();
         int A = sc.nextInt();
         int B = sc.nextInt();
         String winner = "";
         if (N > A) {
           if (N-A > B) {
             if (N%(A+B) == 0) {
                winner = "Bug";
             } else if (N%(A+B) <= A) {
                 winner = "Ant";
             } else {
                winner = "Bug";
             }
           } else {
             winner = "Bug";
           }
         } else {
           winner = "Ant";
         }
         System.out.println(winner);
  }
}