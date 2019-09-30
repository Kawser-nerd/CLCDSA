import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int Q = scanner.nextInt();
    int[] left = new int[Q];
    int[] right = new int[Q];
    for (int i = 0; i < Q; i++) {
      left[i] = scanner.nextInt();
      right[i] = scanner.nextInt();
    }
    Arrays.sort(left);
    Arrays.sort(right);

    long count = 0;
    int li = 0;
    int ri = 0;
    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= N; i++) {
      while (li < Q && left[li] == i) {
        li++;
        count++;
      }
      sb.append(count % 2 == 0 ? '0' : '1');
      while (ri < Q && right[ri] == i) {
        ri++;
        count--;
      }
    }
    System.out.println(sb.toString());
  }
}