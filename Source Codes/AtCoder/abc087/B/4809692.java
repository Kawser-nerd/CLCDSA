import java.util.Scanner;

public class Main {
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    final int A = in.nextInt();
    final int B = in.nextInt();
    final int C = in.nextInt();
    final int X = in.nextInt();
    int count = 0;

    for (int a = 0; a <= A; a++) {
      for (int b = 0; b <= B; b++) {
        for (int c = 0; c <= C; c++) {
          if ((500 * a + 100 * b + 50 * c) == X) {
            count++;
          }
        }
      }
    }
    System.out.println(count);
    
  }

}