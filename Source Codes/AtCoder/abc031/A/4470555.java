import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int a = scanner.nextInt();
    int d = scanner.nextInt();
    if (a > d) {
      System.out.println((d + 1) * a);
    } else {
      System.out.println((a + 1) * d);
    }
  }
}