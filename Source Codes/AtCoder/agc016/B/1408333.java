import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int ak = 0;
    int bk = 0;
    int an = 0;
    int bn = 0;
    for (int i = 0; i < n; i++) {
      int v = sc.nextInt();
      if (ak == 0) {
        ak = v;
        an ++;
      } else if (v == ak) {
        an ++;
      } else if (bk == 0) {
        bk = v;
        bn ++;
        if (Math.abs(ak - bk) > 1) {
          System.out.println("No");
          return;
        }
      } else if (v == bk) {
        bn ++;
      } else {
        System.out.println("No");
        return;
      }
    }
    if (bk == 0) {
      System.out.println((ak == n - 1 || 2 * ak <= n) ? "Yes" : "No");
    } else {
      if (ak < bk) {
        int tk = ak;
        ak = bk;
        bk = tk;
        int tn = an;
        an = bn;
        bn = tn;
      }
      System.out.println((bn < ak && 2 * (ak - bn) <= an) ? "Yes" : "No");
    }
  }
}