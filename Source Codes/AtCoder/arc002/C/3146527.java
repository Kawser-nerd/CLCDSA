import java.util.*;
import java.awt.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    String str = sc.next();

    String[] keywords = {"AA", "AB", "AX", "AY",
                         "BA", "BB", "BX", "BY",
                         "XA", "XB", "XX", "XY",
                         "YA", "YB", "YX", "YY"
                        };

    int ans = n;
    for (int i = 0; i < keywords.length-1; i++) {
      for (int j = i+1; j < keywords.length; j++) {
        int tmp_ans = n;
        int count = 0;

        while (count < n-1) {
          String command = str.substring(count, count+2);
          if (command.equals(keywords[i]) || command.equals(keywords[j])) {
            tmp_ans--;
            count += 2;
          } else {
            count++;
          }
        }

        ans = Math.min(ans, tmp_ans);
      }
    }

    System.out.println(ans);
  }
}