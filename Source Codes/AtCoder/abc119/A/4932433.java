import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    DateTimeFormatter sdf = DateTimeFormatter.ofPattern("yyyy/MM/dd");
    LocalDate reiwa = LocalDate.of(2019, 5, 1);

    LocalDate d = LocalDate.parse(S, sdf);
    if (d.isBefore(reiwa)) {
      System.out.println("Heisei");
    } else {
      System.out.println("TBD");
    }
  }
}