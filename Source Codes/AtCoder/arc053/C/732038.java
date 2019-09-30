import java.util.Scanner;
import java.util.Arrays;

public class Main {
  static int n;
  static Pair[][] ab;

  static class Pair implements Comparable< Pair > {
    int x, y;

    Pair(int x, int y){
      this.x = x;
      this.y = y;
    }

    @Override
      public int compareTo(Pair p){
        return x - p.x;
      }
  }

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    ab = new Pair[2][n];
    int sp1 = 0, sp2 = 0;
    for(int i = 0; i < n; i++){
      int a = sc.nextInt(), b = sc.nextInt();
      if(a - b < 0){
        ab[0][sp1++] = new Pair(a, b);
      }
      else{
        ab[1][sp2++] = new Pair(-b, a);
      }
    }

    Arrays.sort(ab[0], 0, sp1);
    Arrays.sort(ab[1], 0, sp2);
    long maxTmp = 0, tmp = 0;
    for(int i = 0; i < sp1; i++){
      tmp += ab[0][i].x;
      maxTmp = Math.max(maxTmp, tmp);
      tmp -= ab[0][i].y;
    }
    for(int i = 0; i < sp2; i++){
      tmp += ab[1][i].y;
      maxTmp = Math.max(maxTmp, tmp);
      tmp += ab[1][i].x;
    }

    System.out.println(maxTmp);
  }
}