import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int dia = 0;
    int v = 0;
    int m = 0;
    for(int i = 2; i <= N; i++) {
      System.out.printf("? %d %d\n", 1, i);
      int d = sc.nextInt();
      if(d > m) {
        m = d;
        v = i;
      }
    }
    for(int i = 1; i <= N; i++) {
      if(i != v) {
        System.out.printf("? %d %d\n", v, i);
        int d = sc.nextInt();
        if(d > dia) dia = d;
      }
    }
    System.out.println("! " + dia);
    System.out.flush();
  }
}