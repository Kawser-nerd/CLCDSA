import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[][] K = new int[N][];
    for (int i = 0; i < N; i++) {
      int k = sc.nextInt();
      int[] a = new int[k];
      for (int j = 0; j < k; j++) {
        a[j] = sc.nextInt();
      }
      K[i] = a;
    }
    Main abc118B = new Main();
    System.out.println(abc118B.solve(M, K));
  }

  public int solve(int M, int[][] K) {
    ABC118BSolve abc118BSolve = new ABC118BSolve();
    return abc118BSolve.solve(M, K);
  }


  class ABC118BSolve {

    public int solve(int M, int[][] K) {
      Set<Integer> set = arrayToSet(K[0]);
      for(int i = 1; i < K.length; i++ ){
        int[] a = new int[30];
        for(int j = 0; j < K[i].length; j++ ){
          a[K[i][j] - 1] = 1;
        }
        Set<Integer> nextSet = new HashSet();
        Iterator<Integer> it = set.iterator();
        while(it.hasNext()) {
          Integer next = it.next();
          if(a[next-1] == 1) nextSet.add(next);
        }
        set = nextSet;
      }
      return set.size();
    }
  }

  private Set<Integer> arrayToSet(int[] k) {
    Set<Integer> set = new HashSet();
    for(int i = 0; i < k.length; i++ ){
      set.add(k[i]);
    }
    return set;
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.