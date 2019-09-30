import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int C = scanner.nextInt();
    int[][] D = new int[C][C];
    for (int i = 0; i < C; i++) {
      for (int j = 0; j < C; j++) {
        D[i][j] = scanner.nextInt();
      }
    }
    int[][] c = new int[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        c[i][j] = scanner.nextInt();
      }
    }

    int[][] cost = new int[3][C + 1];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 1; k <= C; k++) {
          cost[(i + j + 2) % 3][k] += D[c[i][j] - 1][k - 1];
        }
      }
    }

    int min = Integer.MAX_VALUE;
    for (int ia = 1; ia <= C; ia++) {
      for (int ib = 1; ib <= C; ib++) {
        if (ia == ib) continue;
        for (int ic = 1; ic <= C; ic++) {
          if (ia == ic || ib == ic) continue;
          int t = cost[0][ia] + cost[1][ib] + cost[2][ic];
          if (t < min) min = t;
        }
      }
    }
    System.out.println(min);
  }
}