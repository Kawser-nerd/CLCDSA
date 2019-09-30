import java.util.Scanner;
 
public class Main{
  static int[][][] dp;
  static int[] a;
  static int[] b;
  static int[] c;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.next());
    int Ma = Integer.parseInt(sc.next());
    int Mb = Integer.parseInt(sc.next());
    a = new int[N];
    b = new int[N];
    c = new int[N];
    for(int i=0; i<N; i++){
      a[i] = Integer.parseInt(sc.next());
      b[i] = Integer.parseInt(sc.next());
      c[i] = Integer.parseInt(sc.next());
    }
    dp = new int[N+1][500][500];
    for(int i=0; i<N+1; i++){
      for(int j=0; j<499; j++){
        for(int k=0; k<499; k++){
          dp[i][j][k] = Integer.MAX_VALUE/2;
        }
      }
    }
    dp[0][0][0] = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<400; j++){
        for(int k=0; k<400; k++){
          //i????????????
          dp[i+1][j+a[i]][k+b[i]] = Math.min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
          //i?????????????
          dp[i+1][j][k] = Math.min(dp[i+1][j][k],dp[i][j][k]);
        }
      }
    }
    int min = Integer.MAX_VALUE/2;
    for(int i = 1; i <= 400; i++){
        for(int j= 1; j <= 400; j++){
            if(Ma*j == Mb*i && dp[N][i][j]!=Integer.MAX_VALUE){
                min = Math.min(min,dp[N][i][j]);
            }
        }
    }
    if(min == Integer.MAX_VALUE/2)System.out.println(-1);
    else System.out.println(min);
  }
}