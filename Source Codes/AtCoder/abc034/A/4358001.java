import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int x = scanner.nextInt();
    int y = scanner.nextInt();
    if (y > x) System.out.println("Better");
    else System.out.println("Worse");
  }
}