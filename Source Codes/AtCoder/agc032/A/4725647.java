import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] b = new int[N];
    for (int i = 0; i < N; i++) b[i] = scanner.nextInt();

    int[] op = new int[N];
    for (int i = N - 1; i >= 0; i--) {
      boolean found = false;
      int cnt = i + 1;
      for (int j = N - 1; j >= 0; j--) {
        if (b[j] == cnt) {
          op[i] = cnt;
          b[j] = -1;
          found = true;
          break;
        }
        if (b[j] >= 0) cnt--;
      }
      if (!found) {
        System.out.println(-1);
        return;
      }
    }
    for (int p : op) System.out.println(p);
  }
}