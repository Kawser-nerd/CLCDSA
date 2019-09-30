import java.util.*;

class C {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      int n = sc.nextInt();
      Kid[] kids = new Kid[n];
      for (int i = 0; i < n; ++i) kids[i] = new Kid(i + 1);
      for (int i = 0; i < n; ++i) kids[i].bff = kids[sc.nextInt() - 1];

      int maxCycle = 0;
      for (Kid first : kids) {
        Set<Kid> set = new HashSet<Kid>();
        Kid k = first;
        for (;;) {
          if (set.contains(k)) {
            if (k == first) {
              first.cycle = set.size();
              maxCycle = Math.max(maxCycle, first.cycle);
            }
            break;
          }
          set.add(k);
          k = k.bff;
        }
      }

      for (Kid first : kids) {
        Set<Kid> set = new HashSet<Kid>();
        Kid k = first;
        for (;;) {
          if (set.contains(k)) {
            if (k.cycle == 2) {
              k.brings = Math.max(k.brings, set.size() - 1);
            }
            break;
          }
          set.add(k);
          k = k.bff;
        }
      }

      int brings = 0;
      for (Kid k : kids) if (k.cycle == 2) brings += k.brings;

      System.out.printf("Case #%d: %d%n", tc, Math.max(maxCycle, brings));
    }
  }
}

class Kid {
  public Kid bff;
  public int index;
  public int cycle = 0;
  public int brings = 0;

  public Kid(int index) {
    this.index = index;
  }

  public String toString() {
    return this.index + "(" + this.cycle + "," + this.brings + ")";
  }
}
