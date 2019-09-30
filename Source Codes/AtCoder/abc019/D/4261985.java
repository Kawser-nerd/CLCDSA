import java.util.Scanner;

public class Main {
  static Scanner sc;
  public static int getDist(int a, int b) {
    System.out.printf("? %d %d\n", a, b);
    int dist = sc.nextInt();
    return dist;
  }
  public static void main(String[] args) {
    sc = new Scanner(System.in);
    int N = sc.nextInt();

    int max_dist = -1;
    int max_node = -1;
    for (int i = 2; i <= N; i++) {
      int dist = getDist(1, i);
      if (max_dist < dist) {
        max_dist = dist;
        max_node = i;
      }
    }

    int ans = -1;
    for (int i = 1; i <= N; i++) {
      if (i == max_node) continue;
      ans = Math.max(ans, getDist(max_node, i));
    }
    System.out.println("! " + ans);
  }
}