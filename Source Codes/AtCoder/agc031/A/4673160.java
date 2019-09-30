import java.util.Scanner;

public class Main {
  final static long MOD = 1000000007;

  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      int N = in.nextInt();
      String S = in.next();
      int[] countChar = new int[26];

      for (int i = 0; i < S.length(); ++i) {
        ++countChar[S.charAt(i) - 'a'];
      }

      long count = 1;
      for (int i = 0; i < countChar.length; ++i) {
        count *= countChar[i] + 1;
        count %= MOD;
      }

      System.out.println(count - 1);
    }
  }
}