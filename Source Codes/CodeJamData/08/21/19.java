import java.util.*;

public class A {

  public static void main(String args[]) {
    (new A()).exec();
  }

  long ans(Scanner cin) {
    int n = cin.nextInt();
    int A = cin.nextInt();
    int B = cin.nextInt();
    int C = cin.nextInt();
    int D = cin.nextInt();
    long x[] = new long[n];
    long y[] = new long[n];
    x[0] = cin.nextInt();
    y[0] = cin.nextInt();
    int M = cin.nextInt();
    long count[] = new long[9];
    ++count[(int)(x[0] % 3 * 3 + y[0] % 3)];
    for(int i=1; i<n; ++i) {
      x[i] = (A * x[i-1] + B) % M;
      y[i] = (C * y[i-1] + D) % M;
      ++count[(int)(x[i] % 3 * 3 + y[i] % 3)];
    }
    long ret = 0;
    for(int i=0; i<9; ++i) {
      for(int j=i; j<9; ++j) {
        for(int k=j; k<9; ++k) {
          if( (i / 3 + j / 3 + k / 3) % 3 == 0 &&
              (i % 3 + j % 3 + k % 3) % 3 == 0 ) {
            if( i == j && j == k ) {
              ret += count[i] * (count[j] - 1) * (count[k] - 2) / 6;
            }
            else if( i == j ) {
              ret += count[i] * (count[j] - 1) / 2 * count[k];
            }
            else if( j == k ) {
              ret += count[i] * count[j] * (count[k] - 1) / 2;
            }
            else {
              ret += count[i] * count[j] * count[k];
            }
          }
        }
      }
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);

    int t = cin.nextInt();
    for(int z=0; z<t; ++z) {
      System.out.println("Case #" + (z + 1) + ": " + ans(cin));
    }

  }

}
