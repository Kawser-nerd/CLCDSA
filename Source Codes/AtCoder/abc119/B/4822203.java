import java.util.Scanner;

public class Main {
  final static int ONE_BTC_JPN_VALUE = 380000;

  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      int N = in.nextInt();
      double money = 0;

      for (int i = 0; i < N; ++i) {
        double x = in.nextDouble();
        String u = in.next();

        if (u.equals("JPY")) {
          money += x;
        } else {
          money += x * ONE_BTC_JPN_VALUE;
        }
      }

      System.out.println(money);
    }
  }
}