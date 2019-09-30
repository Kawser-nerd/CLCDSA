import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] day = new int[366];
    for(int i = 0; i < 366; i++) {
      if((i % 7 == 0) || (i % 7 == 6)) day[i] = 1;
    }
    int[] D = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int[] hin = new int[N];
    for(int i = 0; i < N; i++) {
      String ho = sc.next();
      String[] sp = ho.split("/");
      int m = Integer.parseInt(sp[0]);
      int d = Integer.parseInt(sp[1]);
      int sum = 0;
      for(int j = 0; j < m - 1; j++) {
        sum += D[j];
      }
      sum += d;
      day[sum - 1]++;
      hin[i] = sum - 1;
    }
    for(int i = N - 1; i >= 0; i--) {
      int index = hin[i];
      if(day[index] > 1) {
        day[index] = 1;
        for(int j = index + 1; j < 366; j++) {
          if(day[j] == 0) {
            day[j] = 1;
            break;
          }
        }
      }
    }
    for(int i = 0; i < 366; i++) {
      if((i > 0) && (day[i] > 0)) day[i] += day[i - 1];
    }
    int ans = 0;
    for(int i = 0; i < 366; i++) {
      ans = Math.max(ans, day[i]);
    }
    System.out.println(ans);
  }
}