import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int c[][] = new int[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        c[i][j] = sc.nextInt();
      }
    }
    int x[] = new int[3];
    int y[] = new int[3];
    x[0] = 0;
    for (int i = 0; i < 3; i++)
      y[i] = c[0][i] - x[0];
    for (int i = 0; i < 3; i++)
      x[i] = c[i][0] - y[0];

    boolean flag = true;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (x[i] + y[j] != c[i][j])
          flag = false;
      }
    }
    System.out.println(flag ? "Yes" : "No");
  }
}