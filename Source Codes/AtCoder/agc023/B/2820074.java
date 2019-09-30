import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    String[][] str = new String[n][n];

    for (int i=0; i < n; i++) {
      String tmpStr = sc.next();

      for (int j=0; j < n; j++) {
        str[i][j] = String.valueOf(tmpStr.charAt(j));
      }
    }

    int count = 0;
    String[][] secondStr = new String[n][n];

    for (int A=0; A < n; A++) {
      for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
          secondStr[i][j] = str[(i+A)%n][j];
        }
      }

      boolean ans = true;

      for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
          if (!(secondStr[i][j].equals(secondStr[j][i]))) {
            ans = false;
          }
        }
      }

      if (ans == true) count += n;
    }

    System.out.println(count);
  }
}