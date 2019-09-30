import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    long K = Long.parseLong(sc.next());
    long ans = 0;
    long ans1, ans2, s1, s2;
    long add = 1;
    long count = 0;
    boolean flag = true;
    int times = 9;
    while (count < K) {
      ans1 = ans + add;
      s1 = 0;
      String a1 = String.valueOf(ans1);
      for (int i = 0; i < a1.length(); i++) {
        s1 += Long.valueOf(String.valueOf(a1.charAt(i)));
      }
      ans2 = ans1 + add;
      s2 = 0;
      String a2 = String.valueOf(ans2);
      for (int i = 0; i < a2.length(); i++) {
        s2 += Long.valueOf(String.valueOf(a2.charAt(i)));
      }
      if (ans2 * s1 - ans1 * s2 < 0) {
        add *= 10;
        flag = true;
        continue;
      }
      if (flag) {
        times = 9;
      } else {
        times = 10;
      }
      String a = String.valueOf(ans + add);
      for (int i = 0; i < times; i++) {
        ans += add;
        String ai = String.valueOf(ans);
        if (a.length() != ai.length()) {
          ans-=add;
          break;
        }
        System.out.println(ans);
        count++;
        if (count >= K) {
          break;
        }
      }
      flag = false;

    }

  }
}