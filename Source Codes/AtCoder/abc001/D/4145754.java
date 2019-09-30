import java.util.*;

public class Main {
  public static void main (String... args) {
    Scanner sc = new Scanner(System.in);
    boolean[][] rain = new boolean[25][12];

    int a = sc.nextInt();
    int[][] time = new int[a][2];
    String[] str = new String[2];
    for (int i = 0; i < a; i++) {
      str = sc.next().split("-", -1);
      time[i][0] = Integer.valueOf(str[0]);
      if (time[i][0] % 5 != 0) {
        time[i][0] -= time[i][0] % 5;
      }
      time[i][1] = Integer.valueOf(str[1]);
      if (time[i][1] % 5 != 0) {
        time[i][1] += 5 - time[i][1] % 5;
        if (time[i][1] % 100 == 60) {
          time[i][1] += 40;
        }
      }
    }
    
    for (int count = 0; count < a; count++) {
      for (int x = 0; x <= 24; x++) {
        for (int y = 0; y < 12; y++) {
          if (rain[x][y] == true) {
            continue;
          } else if (time[count][0] <= x * 100 + y * 5
              && time[count][1] > x * 100 + y * 5) { 
            rain[x][y] = true;
          }
        }
      }
    }

    boolean flag = false;
    for (int x = 0; x < 25; x++) {
      for (int y = 0; y < 12; y++) {
        if (!flag && rain[x][y]) {
          if (x == 0) {
            System.out.print("00");
          } else if (x < 10) {
            System.out.print("0" + x);
          } else {
            System.out.print(x);
          }
          if (y == 0) {
            System.out.print("00");
          } else if (y == 1) {
            System.out.print("05");
          } else {
            System.out.print(y * 5);
          }
          System.out.print("-"); 
          flag = true;
        } else if (flag && !rain[x][y]) {
          if (x == 0) {
            System.out.print("00");
          } else if (x < 10) {
            System.out.print("0" + x);
          } else {
            System.out.print(x);
          }
          if (y == 0) {
            System.out.println("00");
          } else if (y == 1) {
            System.out.println("05");
          } else {
            System.out.println(y * 5);
          }
          flag = false;
        }
      }
    }
  }
}