import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    char[][] s = new char[N][N];

    int ans = 0;
    String line;
    for (int i=0; i<N; i++) {
      line = sc.next();
      for (int j=0; j<N; j++) {
        s[i][j] = line.charAt(j);
      }
    }

    // B=0;
    boolean good;
    for (int A=0; A<N; A++) {
      good = true;
      for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
          int tmpI = (i + A)% N;
          int tmpJ = (j + A)% N;
          if (s[tmpI][j] != s[tmpJ][i]) {
            good = false;
          }
        }
      }
      if (good) {
        ans++;
      }
    }
    System.out.println(ans*N);
  }
}