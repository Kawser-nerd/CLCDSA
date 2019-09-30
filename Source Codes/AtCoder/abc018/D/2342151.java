import java.util.*;

public class Main{
  static int N;
  static int M;
  static int P;
  static int Q;
  static int R;
  static int[][] value;
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    N = Integer.parseInt(sc.next());
    M = Integer.parseInt(sc.next());
    P = Integer.parseInt(sc.next());
    Q = Integer.parseInt(sc.next());
    R = Integer.parseInt(sc.next());
    value = new int[N][M];
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        value[i][j] = 0;
      }
    }
    for(int i=0; i<R; i++){
      int x = Integer.parseInt(sc.next());
      int y = Integer.parseInt(sc.next());
      int z = Integer.parseInt(sc.next());
      value[x-1][y-1] = z;
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
            if(girl[k] == 1) temp[j] += value[k][j];
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