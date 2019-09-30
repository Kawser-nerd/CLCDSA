import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int[] L = new int[N];
    for(int i = 0; i < N; i++ ){
      L[i] = sc.nextInt();
    }
    Main abc119C = new Main();
    System.out.println(abc119C.solve(A, B, C, L));
  }

  public int solve(int A, int B, int C, int[] L) {
    ABC119CSolve abc119CSolve = new ABC119CSolve(A, B, C, L);
    return abc119CSolve.solve();
  }

  class ABC119CSolve{
    int A;
    int B;
    int C;
    int[] L;
    int INF = (int) Math.pow(10, 9);
    public ABC119CSolve(int A, int B, int C, int[] L) {
      this.A = A;
      this.B = B;
      this.C = C;
      this.L = L;
    }

    public int solve(){
      return this.dfs(0, 0, 0, 0);
    }

    private int dfs(int index, int a, int b, int c) {
      if(index == L.length) {
        if(a > 0 && b > 0 && c > 0) {
          return Math.abs(this.A - a) + Math.abs(this.B - b) + Math.abs(this.C - c) - 30;
        } else {
          return INF;
        }
      }
      int ret0 = dfs(index+1, a, b, c);
      int ret1 = dfs(index+1, a+L[index], b, c) + 10;
      int ret2 = dfs(index+1, a, b+L[index], c) + 10;
      int ret3 = dfs(index+1, a, b, c+L[index]) + 10;
      return Math.min(Math.min(Math.min(ret0, ret1), ret2), ret3);
    }
  }
}