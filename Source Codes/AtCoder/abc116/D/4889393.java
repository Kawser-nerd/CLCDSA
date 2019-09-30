import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int K = sc.nextInt();
    int[] t = new int[N];
    int[] d = new int[N];
    for (int i = 0; i < N; i++) {
      t[i] = sc.nextInt();
      d[i] = sc.nextInt();
    }
    Main abc116D = new Main();
    System.out.println(abc116D.solve(N, K, t, d));
  }

  long solve(int N, int K, int[] t, int[] d) {
    List<Sushi> sushis = new ArrayList();
    for(int i = 0; i < N; i++){
      sushis.add(new Sushi(t[i], d[i]));
    }
    ABC116DSolveWork abc116DSolve = new ABC116DSolveWork(sushis, K);
    return abc116DSolve.solve();
  }

  class ABC116DSolveWork {
    List<Sushi> sushis;
    int K;

    public ABC116DSolveWork( List<Sushi> sushis, int K) {
      this.sushis = sushis;
      this.K = K;
      Collections.sort(this.sushis);
    }

    public long solve() {
      return searchAns();
    }

    private long searchAns() {
      long point = 0;
      long size = 0;
      Set<Integer> types = new HashSet<>();
      Stack<Sushi> chohukus = new Stack();
      Queue<Sushi> kouho = new LinkedList();

      for (int i = 0; i < K; i++) {
        Sushi sushi = this.sushis.get(i);
        point += sushi.d;
        if (types.contains(sushi.t)) {
          chohukus.push(sushi);
        } else {
          types.add(sushi.t);
          size += 1;
        }
      }
      long ans = point + size * size;

      for (int i = K; i < this.sushis.size(); i++) {
        Sushi sushi = this.sushis.get(i);
        if (!types.contains(sushi.t)) {
          types.add(sushi.t);
          kouho.add(sushi);
        }
      }

      while (!chohukus.isEmpty() && !kouho.isEmpty()) {
        Sushi delSushi = chohukus.pop();
        Sushi addSushi = kouho.poll();
        point = point - delSushi.d + addSushi.d;
        size += 1;
        long nextAns = point + size * size;

        if (nextAns > ans) {
          ans = nextAns;
        }
      }
      return ans;
    }
  }
  class Sushi implements Comparable<Sushi>{
    public int t;
    public int d;
    public Sushi(int t, int d){
      this.t = t;
      this.d = d;
    }

    @Override
    public int compareTo(Sushi other) {
      return other.d - this.d;
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.