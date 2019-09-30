import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] h = new long[N];
    long[] s = new long[N];
    for(int i = 0; i < N; i++) {
      h[i] = sc.nextLong();
      s[i] = sc.nextLong();
    }
    long ans = 0;
    long left = 1;
    long right = 2 * (long)Math.pow(10, 14);
    while(left < right) {
      long med = (left + right) / 2;
      long[] time = new long[N];
      boolean flg = true;
      for(int i = 0; i < N; i++) {
        if(med - h[i] < 0) {
          flg = false;
          break;
        }
        time[i] = (med - h[i]) / s[i];
      }
      Arrays.sort(time);
      for(int i = 0; i < N; i++) {
        if(time[i] < i) {
          flg = false;
          break;
        }
      }
      if(flg) {
        ans = med;
        right = med;
      } else {
        left = med + 1;
      }
    }
    System.out.println(ans);
  }
}