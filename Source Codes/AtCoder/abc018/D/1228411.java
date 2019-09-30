import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int P = sc.nextInt();
    int Q = sc.nextInt();
    int R = sc.nextInt();
    int[] x = new int[R];
    int[] y = new int[R];
    int[] z = new int[R];
    int[][] score = new int[N][M];
    for(int i = 0; i < R; i++) {
      x[i] = sc.nextInt() - 1;
      y[i] = sc.nextInt() - 1;
      z[i] = sc.nextInt();
      score[x[i]][y[i]] = z[i];
    }
    int happy = 0;
    for(int i = 1; i < (int)Math.pow(2, N); i++) {
      int[] girl = new int[N];
      int countg = 0;
      for(int j = 0; j < N; j++) {
        if((i & (1 << j)) != 0) {
          countg++;
          girl[j] = 1;
        }
      }
      if(countg == P) {
        int[] temp = new int[M];
        for(int j = 0; j < M; j++) {
          for(int k = 0; k < N; k++) {
            if(girl[k] == 1) temp[j] += score[k][j];
          }
        }
        Arrays.sort(temp);
        int s = 0;
        for(int j = 0; j < Q; j++) {
          s += temp[M - 1 - j];
        }
        happy = Math.max(happy, s);
      }
    }
    System.out.println(happy);
  }
}