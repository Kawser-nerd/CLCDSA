import java.util.*;

class Solver {
  int[] x;
  long[][][] cache;
  Solver(int[] x) {
    this.x = x;
    this.cache = new long[64][64][4096];
    for (int i = 0; i < 64; i++) {
      for (int j = 0; j < 64; j++) {
        for (int k = 0; k < 4096; k++) {
          cache[i][j][k] = -1;
        }
      }
    }
  }

  long count(int index, int rest, int target) {
    if (cache[index][rest][target] >= 0) {
      return cache[index][rest][target];
    }
    if (rest == 0 && target > 0) {
      cache[index][rest][target] = 0;
      return cache[index][rest][target];
    }
    if (rest == 0 && target == 0) {
      cache[index][rest][target] = 1;
      return cache[index][rest][target];
    }
    if (x.length - index < rest) {
      cache[index][rest][target] = 0;
      return cache[index][rest][target];
    }
    cache[index][rest][target] = 0;
    for (int i = index; i < x.length; i++) {
      if (target - x[i] < 0) {
        continue;
      }
      cache[index][rest][target] += count(i+1, rest-1, target-x[i]);
    }
    return cache[index][rest][target];
  }

  long solve(int a) {
    long sum = 0;
    for (int i = 1; i <= x.length; i++) {
      sum += count(0, i, a*i);
    }
    return sum;
  }
}

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int a = s.nextInt();
    int[] x = new int[n];
    for (int i = 0; i < n; i++) {
      x[i] = s.nextInt();
    }
    Solver solver = new Solver(x);
    System.out.println(solver.solve(a));
  }
}