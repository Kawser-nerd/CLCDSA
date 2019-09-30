import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void swap(long array[], int i, int j) {
    long temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }

  long solve(long M, long F, int N, long cost[], long time[]) {

    // sort meal;
    for(int i=0; i<N; ++i) {
      for(int j=i+1; j<N; ++j) {
        if( cost[i] > cost[j] ) {
          swap(cost, i, j);
          swap(time, i, j);
        }
        else if( cost[i] == cost[j] && time[i] < time[j] ) {
          swap(cost, i, j);
          swap(time, i, j);
        }
      }
    }

    long times = 1;
    long max = 0;
    while( true ) {
      if( times > M / F ) { break; }
      long rest = M - F * times;
      max = Math.max(max, days(times, rest, N, cost, time));
      ++times;
    }

    return max;

  }

  long days(long times, long rest, int N, long cost[], long time[]) {
    long day = 0;
    for(int i=0; i<N; ++i) {
      if( time[i] < day ) { continue; }
      long cand = rest / cost[i] / times;
      if( cand < time[i] - day ) {
        return day * times + rest / cost[i];
      }
      rest -= (time[i] - day) * times * cost[i];
      day = time[i];
    }
    return day * times;
  }

  long solve(long M, long F, int N, long D, long cost[], long time[], long oneTime) {
    // purchase;
    long sum = F;
    long day = 0;
    long max = 0;
    for(int i=0; i<N; ++i) {
      if( time[i] < day ) { continue; }
      long next = Math.min(D, time[i]);
      long restDay = (M - sum) / cost[i];
      // cannot buy D days;
      if( restDay < next - day ) { return 0; }
      sum += (next - day) * cost[i];
      day = next;
      if( day == D ) { break; }
    }

    if( day < D ) { return 0; }

    long rep = M / sum;
    long ans = rest(M - sum * rep, day, N, cost, time);
    return ans + day * (rep - 1);

  }

  long rest(long rest, long day, int N, long cost[], long time[]) {
    for(int i=0; i<N; ++i) {
      if( time[i] < day ) { continue; }
      long cand = rest / cost[i];
      long next = Math.min(day + cand, time[i]);
      rest -= (next - day) * cost[i];
      day = next;
    }
    return day;
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();

    for(int C=1; C<=T; ++C) {

      long M = cin.nextLong();
      long F = cin.nextLong();
      int N = cin.nextInt();
      long cost[] = new long[N];
      long time[] = new long[N];
      for(int i=0; i<N; ++i) {
        cost[i] = cin.nextLong();
        time[i] = cin.nextLong() + 1;
      }

      System.out.println("Case #" + C + ": " + solve(M, F, N, cost, time));

    }

  }

}
