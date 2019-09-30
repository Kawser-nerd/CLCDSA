import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int Rcnt = 0;
    int Bcnt = 0;
    String win;
    //String lt[] = new String[N];
    for (int i = 0; i < N ; i++) {
      String S = sc.next();
      String lt[] = S.split("");
      for (int j = 0; j < lt.length; j++) {
        String wk = lt[j];
        if (wk.equals("R")) {
          Rcnt++;
        } else if (wk.equals("B")) {
          Bcnt++;
        }
      }
    }
    if (Rcnt > Bcnt) {
      win = "TAKAHASHI";
    } else if (Rcnt == Bcnt) {
      win = "DRAW";
    } else {
      win = "AOKI";
    }
    System.out.println(win);
  }
}