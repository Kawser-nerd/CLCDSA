import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int R = sc.nextInt();
    int G = sc.nextInt();
    int B = sc.nextInt();
    int ans = Integer.MAX_VALUE;
    for(int i = -49 - G; i < 51; i++) {
      int move = 0;
      // ??????????
      if(i + G - 1 <= 0) {
        move += ((-2 * i - G + 1) * G) / 2;
      } else if(i >= 0) {
        move += ((2 * i + G - 1) * G) / 2;
      } else {
        move += ((-i) * (-i + 1)) / 2;
        move += ((i + G - 1) * (i + G)) / 2;
      }
      // ??????????
      if(i <= -99) {
        move += ((-199 - 2 * i + R) * R) / 2;
      } else {
        int r = Math.min(i - 1, -100 + (R - 1) / 2);
        move += ((r + 100) * (r + 101)) / 2;
        move += ((-101 - r + R) * (-100 - r + R)) / 2;
      }
      // ??????????
      if(i + G - 1 >= 99) {
        move += ((2 * (i + G - 100) + B - 1) * B) / 2;
      } else {
        int r = Math.max(i + G, 100 - (B - 1) / 2);
        move += ((100 - r) * (101 - r)) / 2;
        move += ((r + B - 101) * (r + B - 100)) / 2;
      }
      ans = Math.min(ans, move);
    }
    System.out.println(ans);
  }
}