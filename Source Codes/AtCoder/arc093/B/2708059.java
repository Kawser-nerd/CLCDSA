import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt(); // white : true
    int B = sc.nextInt(); // black : false
    System.out.println("100 100");
    boolean ans[][] = new boolean[100][100];
    // initialize
    for (int i=0; i<100; i++) {
      for (int j=0; j<100; j++) {
        if (i < 50) {
          ans[i][j] = true;
        } else {
          ans[i][j] = false;
        }
      }
    }
    for (int i=0; i<B-1; i++) {
      ans[2*(i/50)][2*(i%50)] = false;
    }
    for (int i=0; i<A-1; i++) {
      ans[2*(i/50) + 51][2*(i%50)] = true;
    }
    
    for (int i=0; i<100; i++) {
      for (int j=0; j<100; j++) {
        if (ans[i][j]) {
          System.out.print('.');
        } else {
          System.out.print('#');
        }
      }
      System.out.println();
    }
  }
}