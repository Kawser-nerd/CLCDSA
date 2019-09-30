import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int c = scanner.nextInt();

    System.out.println(solve(a, b, c));
  }

  private static int solve(int a, int b, int c) {
    if (a > b) return solve(b, a, c);
    if (b > c) return solve(a, c, b);
    if ((c * 3 - (a + b + c)) % 2 == 1) return solve(a, b + 1, c + 1) + 1;

    return ((c * 3) - (a + b + c)) / 2;
  }
}