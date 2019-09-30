import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int W = scanner.nextInt();
    int H = scanner.nextInt();

    if (W * 3 == H * 4) {
      System.out.println("4:3");
    } else {
      System.out.println("16:9");
    }
  }
}