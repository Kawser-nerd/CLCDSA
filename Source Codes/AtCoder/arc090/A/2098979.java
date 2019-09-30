import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[][] A = new int[2][N];
    for (int i = 0; i < 2 ; i++)
      for (int j = 0; j < N; j++)
        A[i][j] = sc.nextInt();
    int[][] B = new int[2][N];
    B[1][N - 1] = A[1][N - 1];
    B[0][N - 1] = A[0][N - 1] + A[1][N - 1];
    for (int j = N - 2; j > 0 - 1; j--) {
      B[1][j] = A[1][j] + B[1][j + 1];
      B[0][j] = A[0][j] + Math.max(B[0][j + 1], B[1][j]);
    }
    System.out.println(B[0][0]);
  }

}