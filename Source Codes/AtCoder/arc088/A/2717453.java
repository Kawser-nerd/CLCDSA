import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    long X = sc.nextLong();
    long Y = sc.nextLong();

    int count = 1;
    long tmp_x = X;

    while (true) {
      if (tmp_x * 2 > Y) {
        break;
      } else {
        tmp_x = tmp_x * 2;
        count++;
      }
    }

    System.out.println(count);
  }
}