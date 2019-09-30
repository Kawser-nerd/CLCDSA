import java.util.Scanner;

class Main {

  /**
   * -2????????????????
   *
   * @param 10??
   * @return -2????????
   */
  public static int ketasu(int n) {
    if (n >= 0) {
      int ketasu = 1;
      long jougen = 1;
      long base = 1;
      for (int i = 0; n > jougen; i++) {
        ketasu = ketasu + 2;
        base *= 4;
        jougen += base;
      }
      return ketasu;
    } else {
      int ketasu = 0;
      long jougen = 0;
      long base = -2;
      for (int i = 0; n < jougen; i++) {
        ketasu = ketasu + 2;
        jougen += base;
        base *= 4;
      }
      return ketasu;
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    scanner.close();
    int ketasu = ketasu(n);
    char[] ans = new char[ketasu];
    for (int index = ketasu - 1; index >= 0; index--) {
      if (n % 2 == 0) {
        ans[index] = '0';
        n /= -2;
      } else {
        ans[index] = '1';
        n = n - 1;
        n /= -2;
      }
    }
    System.out.println(String.valueOf(ans));
  }

}