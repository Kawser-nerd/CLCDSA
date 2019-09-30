import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int c = scanner.nextInt();
    int d = scanner.nextInt();

    if (b * c > a * d) {
      System.out.println("TAKAHASHI");
    } else if (b * c < a * d) {
      System.out.println("AOKI");
    } else {
      System.out.println("DRAW");
    }
  }
}