import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Main abc116A = new Main();
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    int y = sc.nextInt();
    int z = sc.nextInt();
    System.out.println(abc116A.solve(x, y, z));

  }

  public int solve(int x, int y, int z) {
    int[] a = {x, y, z};
    Arrays.sort(a);
    return a[0] * a[1] / 2;
  }

}