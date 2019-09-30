import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    String S = sc.next();
    int len = S.length();
    int minDif = Integer.MAX_VALUE;

    for (int i=0; i<=len-3; i++) {
      minDif = Math.min(minDif, Math.abs(Integer.parseInt(S.substring(i, i+3)) - 753));
    }

    System.out.println(minDif);

  }
}