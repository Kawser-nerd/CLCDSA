import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int C = sc.nextInt();
    int m1 = 0;
    int m2 = 0;
    int m3 = 0;
    for(int i = 0; i < C; i++) {
      int n = sc.nextInt();
      int m = sc.nextInt();
      int l = sc.nextInt();
      int[] arr = {n, m, l};
      Arrays.sort(arr);
      m1 = Math.max(m1, arr[0]);
      m2 = Math.max(m2, arr[1]);
      m3 = Math.max(m3, arr[2]);
    }
    System.out.println(m1 * m2 * m3);
  }
}