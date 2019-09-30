import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    final int N = in.nextInt();
    final int Y = in.nextInt();
    int rstX = -1;
    int rstY = -1;
    int rstZ = -1;
    for (int x = 0; x <= N; x++) {
      for (int y = 0; y <= N - x; y++) {
        for (int z = 0; z <= N - x - y; z++) {
          if ((10000 * x + 5000 * y + 1000 * z) == Y && x + y + z == N) {
            rstX = x;
            rstY = y;
            rstZ = z;
            break;
          }
        }
      }
    }
    System.out.println(rstX + " " + rstY + " " + rstZ);

  }

}