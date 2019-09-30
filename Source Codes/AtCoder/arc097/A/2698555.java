import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String s = scanner.next();
    int K = scanner.nextInt();

    PriorityQueue<String> queue = new PriorityQueue<>();
    for (int l = 1; l <= s.length() && l <= K; l++) {
      for (int i = 0; i <= s.length() - l; i++) {
        String sb = s.substring(i, i + l);
        if (!queue.contains(sb)) {
          queue.add(sb);
        }
      }
    }
    String val = "";
    for (int i = 0; i < K; i++) {
      val = queue.remove();
    }
    System.out.println(val);
  }
}