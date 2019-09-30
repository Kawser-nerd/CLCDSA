import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    int yen = 0;
    double btc = 0.;
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for (int i = 0; i < N; i++) {
      Double x = sc.nextDouble();
      String u = sc.nextLine();
      if (u.trim().equals("JPY")) {
        yen += x;
      } else {
        btc += x;
      }
    }
    System.out.println(String.format("%f", yen + 380000 * btc));
  }
}