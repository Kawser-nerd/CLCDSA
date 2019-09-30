import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    long N = sc.nextLong();
    ArrayList<Integer> first = new ArrayList<>();
    ArrayList<Integer> second = new ArrayList<>();
    for (int i = 1; (1L << i) - 1 <= N; i++) {
      first.add(i);
      second.add(i);
    }
    N -= (1L << first.size()) - 1;
    while (N > 0) {
      int a = first.size() + 1;
      first.add(a);
      for (int i = 0; ; i++) {
        if ((1L << (i + 1)) > N) {
          second.add(i, a);
          N -= (1L << (i));
          break;
        }
      }
    }

    System.out.println(first.size() * 2);
    for (int i = 0; i < first.size(); i++) {
      System.out.print(first.get(i) + " ");
    }
    for (int i = 0; i < first.size(); i++) {
      System.out.print(second.get(i) + (i == first.size() - 1 ? "\n" : " "));
    }
  }

}