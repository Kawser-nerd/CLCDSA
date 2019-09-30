import java.util.Scanner;

public class Main {
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      String[] date = in.next().split("/");
      int year = Integer.valueOf(date[0]);
      int month = Integer.valueOf(date[1]);
      int day = Integer.valueOf(date[2]);

      if (year < 2019) {
          System.out.println("Heisei");
      } else if (year == 2019 && month <= 4) {
          System.out.println("Heisei");
      } else {
          System.out.println("TBD");
      }
    }
  }
}