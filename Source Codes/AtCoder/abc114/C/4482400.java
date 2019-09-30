import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  static int[] n;

  public static void main(String[] args) {

    String S = sc.next();
    n = new int[S.length()];

    for (int i=0; i<n.length; i++) {
      n[i] = Integer.parseInt(S.substring(n.length-i-1, n.length-i));
    }

    int sum = g(n.length-1, 0, 0, 0);
    for (int i=2; i<n.length-1; i++) {
      sum += h(i, 0, 0, 0);
    }

    System.out.println(sum);

  }

  static int g(int m, int seven, int five, int three) {

    if (m < 0) return (seven + five + three == 3) ? 1 : 0;

    if (n[m] < 3) {
      return 0;
    } else if (n[m] == 3) {
      return g(m-1, seven, five, 1);
    } else if (n[m] < 5) {
      return h(m-1, seven, five, 1);
    } else if (n[m] == 5) {
      int a = h(m-1, seven, five, 1);
      int b = g(m-1, seven, 1, three);
      return h(m-1, seven, five, 1) + g(m-1, seven, 1, three);
    } else if (n[m] < 7) {
      return h(m-1, seven, five, 1) + h(m-1, seven, 1, three);
    } else if (n[m] == 7) {
      return h(m-1, seven, five, 1) + h(m-1, seven, 1, three) + g(m-1, 1, five, three);
    } else {
      return h(m-1, seven, five, 1) + h(m-1, seven, 1, three) + h(m-1, 1, five, three);
    }
  }

  static int h(int m, int seven, int five, int three) {

    int a = seven + five + three;

    if (m < 0) {
      return (seven + five + three == 3) ? 1 : 0;
    } else if (m == 0) {
      if (a < 2) {
        return 0;
      } else if (a == 2) {
        return 1;
      } else {
        return 3;
      }
    } else if (m == 1) {
      if (a == 0) {
        return 0;
      } else if (a == 1) {
        return 2;
      } else if (a == 2) {
        return 5;
      } else if (a == 3) {
        return 9;
      }
    }

    switch(a) {
      case 0: return (int)Math.pow(3, m+1) - 3 * (int)Math.pow(2, m+1) + 3;
      case 1: return (int)Math.pow(3, m+1) - 2 * (int)Math.pow(2, m+1) + 1;
      case 2: return (int)Math.pow(3, m+1) -     (int)Math.pow(2, m+1);
      case 3: return (int)Math.pow(3, m+1);
      default: return Integer.MIN_VALUE;
    }
  }

}