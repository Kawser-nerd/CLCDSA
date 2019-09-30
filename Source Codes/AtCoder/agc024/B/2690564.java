import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int Q[] = new int[N+1];
    for (int i=0; i<N; i++) {
      int tmp = sc.nextInt();
      Q[tmp] = i;
    }
    
    int tmp = 0;
    int anstmp = 1;
    for (int i=2; i<=N; i++) {
      if (Q[i] > Q[i-1]) {
        anstmp++;
      } else {
        tmp = Math.max(tmp, anstmp);
        anstmp = 1;
      }
    }
    tmp = Math.max(tmp, anstmp);
    System.out.println(N-tmp);
  }
}