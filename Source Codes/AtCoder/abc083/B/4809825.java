import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int a = in.nextInt();
    int b = in.nextInt();
    int sumTotal = 0;
    for (int i = 1; i <= n; i++) {
      int fifthDigit = i / 10000;
      int fourthDigit = i % 10000 / 1000;
      int thirdDigit = i % 1000 / 100;
      int secondDigit = i % 100 / 10;
      int firstDigit = i % 10;

      int sum = firstDigit + secondDigit + thirdDigit + fourthDigit + fifthDigit;
      if (a <= sum && sum <= b) {
        sumTotal += i;
      }
    }
    System.out.println(sumTotal);
  }
}