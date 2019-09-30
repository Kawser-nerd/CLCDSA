import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String c = sc.next();
    int[] num = new int[5];
    for (int i = 0; i < N; i++) {
      char tmp = c.charAt(i);
      num[tmp - '0']++;
    }
    int max = Math.max(Math.max(num[1], num[2]), Math.max(num[3], num[4]));
    int min = Math.min(Math.min(num[1], num[2]), Math.min(num[3], num[4]));
    System.out.println(max + " " + min);
  }
}