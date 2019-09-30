import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt();
    Main abc120B = new Main();
    System.out.println(abc120B.solve(A, B, K));
  }

  public int solve(int A, int B, int K) {
    ABC120BSolve abc120BSolve = new ABC120BSolve(A, B);
    return abc120BSolve.solve(K);
  }

  class ABC120BSolve {
    List<Integer> D;

    public ABC120BSolve(int A, int B) {
      Set<Integer> divB = divisors(new HashSet(), B);
      List<Integer> divAList = new ArrayList(divisors(new HashSet(), A));
      Collections.sort(divAList, Collections.reverseOrder());
      D = new ArrayList();
      for (int a : divAList) {
        if (divB.contains(a)) {
          D.add(a);
        }
      }
    }

    public int solve(int k) {
      if (this.D.size() >= k) {
        return this.D.get(k - 1);
      } else {
        return -1;
      }

    }

    private Set<Integer> divisors(Set<Integer> ans, int n) {
      for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
          ans.add(i);
          ans.add(n / i);
        }
      }
      return ans;
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.