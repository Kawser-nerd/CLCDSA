import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    int x = sc.nextInt();
    Main abc117A = new Main();
    System.out.println(abc117A.solve(t, x));
  }

  public double solve(int t, int x) {
    return (double) t / x;
  }
}