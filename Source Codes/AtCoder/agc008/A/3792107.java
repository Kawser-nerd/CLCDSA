import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    int y = sc.nextInt();
    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;
    int ans4 = 0;
    int x1 = x;
    int x2 = -1 * x;
    int y1 = y;
    int y2 = -1 * y;
    if (x1 <= y1) {
      ans1 = y1 - x1;
    } else {
      ans1 = Integer.MAX_VALUE;
    }
    if (x2 <= y1) {
      ans2 = y1 - x2 + 1;
    } else {
      ans2 = Integer.MAX_VALUE;
    }
    if (x1 <= y2) {
      ans3 = y2 - x1 + 1;
    } else {
      ans3 = Integer.MAX_VALUE;
    }
    if (x2 <= y2) {
      ans4 = y2 - x2 + 2;
    } else {
      ans4 = Integer.MAX_VALUE;
    }
    int ans = Math.min(Math.min(ans1, ans2), Math.min(ans3, ans4));
    System.out.println(ans);
  }
}