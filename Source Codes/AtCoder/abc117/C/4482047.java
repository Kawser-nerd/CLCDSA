import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    int M = sc.nextInt();

    if (N >= M) {
      System.out.println(0);
      return;
    }

    int[] X = new int[M];
    for (int i=0; i<M; i++) {
      X[i] = sc.nextInt();
    }

    Arrays.sort(X);

    ArrayList<Integer[]> ranking = new ArrayList(M-1); //[0] ?? [1] ?
    for (int i=1; i<M; i++) {
      int dif = X[i] - X[i-1];
      ranking.add(new Integer[]{i, dif});
    }

    Collections.sort(ranking, (x,y) -> y[1]-x[1]);
    while(ranking.size() >= N) ranking.remove(N-1);
    Collections.sort(ranking, (x, y) -> x[0] - y[0]);
    ranking.add(0, new Integer[]{0, -1});
    ranking.add(new Integer[]{M, -1});

    int sum = 0;
    for (int i=1; i<=N; i++) {
      sum += X[ranking.get(i)[0]-1] - X[ranking.get(i-1)[0]];
    }

    System.out.println(sum);

  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.