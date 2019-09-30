import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    int N = Integer.parseInt(sc.next());
    ArrayList<interval> List = new ArrayList<interval>();
    for (int i = 0; i < N; i++) {
      List.add(new interval(i, Integer.parseInt(sc.next()), Integer.parseInt(sc.next())));
    }

    Integer lIndex[] = new Integer[N];
    Integer rIndex[] = new Integer[N];
    for (int i = 0; i < N; i++) {
      lIndex[i] = i;
      rIndex[i] = i;
    }

    Arrays.sort(lIndex, new Comparator<Integer>() {
      @Override
      public int compare(Integer i1, Integer i2) {
        int x1 = List.get(i1).left;
        int x2 = List.get(i2).left;
        if (x1 < x2) {
          return 1;
        } else if (x1 > x2) {
          return -1;
        } else {
          return -Integer.compare(List.get(i1).right, List.get(i2).right);
        }
      }

    });
    Arrays.sort(rIndex, new Comparator<Integer>() {
      @Override
      public int compare(Integer i1, Integer i2) {
        int x1 = List.get(i1).right;
        int x2 = List.get(i2).right;
        if (x1 > x2) {
          return 1;
        } else if (x1 < x2) {
          return -1;
        } else {
          return Integer.compare(List.get(i1).left, List.get(i2).left);
        }
      }
    });

    //    System.out.println(Arrays.toString(lIndex));
    //    System.out.println(Arrays.toString(rIndex));

    boolean indexFlag[] = new boolean[N];
    long ans = 0;
    int count = 0;
    int left = 0, right = 0;
    int takahashi = 0;
    int id = 0;

    while (true) {
      while (left < N) {
        if (!indexFlag[lIndex[left]]) {
          break;
        } else {
          left++;
        }
      }
      id = lIndex[left];
      //      System.out.print(id + ": ");
      indexFlag[id] = true;
      left++;
      if (takahashi < List.get(id).left) {
        ans += List.get(id).left - takahashi;
        takahashi = List.get(id).left;
      } else if (takahashi > List.get(id).right) {
        ans += takahashi - List.get(id).right;
        takahashi = List.get(id).right;
      }
      count++;
      //      System.out.println(takahashi);
      if (count == N) {
        ans += Math.abs(takahashi);
        break;
      }
      while (right < N) {
        if (!indexFlag[rIndex[right]]) {
          break;
        } else {
          right++;
        }
      }
      id = rIndex[right];
      //      System.out.print(id + ": ");
      indexFlag[id] = true;
      right++;
      if (takahashi < List.get(id).left) {
        ans += List.get(id).left - takahashi;
        takahashi = List.get(id).left;
      } else if (takahashi > List.get(id).right) {
        ans += takahashi - List.get(id).right;
        takahashi = List.get(id).right;
      }
      count++;
      //      System.out.println(takahashi);
      if (count == N) {
        ans += Math.abs(takahashi);
        break;
      }
    }
    long temp = ans;

    ans = 0;
    count = 0;
    left = 0;
    right = 0;
    takahashi = 0;
    id = 0;
    for (int i = 0; i < N; i++) {
      indexFlag[i] = false;
    }
    while (true) {
      while (right < N) {
        if (!indexFlag[rIndex[right]]) {
          break;
        } else {
          right++;
        }
      }
      id = rIndex[right];
      //      System.out.print(id + ": ");
      indexFlag[id] = true;
      right++;
      if (takahashi < List.get(id).left) {
        ans += List.get(id).left - takahashi;
        takahashi = List.get(id).left;
      } else if (takahashi > List.get(id).right) {
        ans += takahashi - List.get(id).right;
        takahashi = List.get(id).right;
      }
      count++;
      //      System.out.println(takahashi);
      if (count == N) {
        ans += Math.abs(takahashi);
        break;
      }
      while (left < N) {
        if (!indexFlag[lIndex[left]]) {
          break;
        } else {
          left++;
        }
      }
      id = lIndex[left];
      //      System.out.print(id + ": ");
      indexFlag[id] = true;
      left++;
      if (takahashi < List.get(id).left) {
        ans += List.get(id).left - takahashi;
        takahashi = List.get(id).left;
      } else if (takahashi > List.get(id).right) {
        ans += takahashi - List.get(id).right;
        takahashi = List.get(id).right;
      }
      count++;
      //      System.out.println(takahashi);
      if (count == N) {
        ans += Math.abs(takahashi);
        break;
      }
    }
    ans = Math.max(ans, temp);
    System.out.println(ans);
  }

  static class interval {
    public int id;
    public int left;
    public int right;

    public interval(int i, int l, int r) {
      id = i;
      left = l;
      right = r;
    }
  }
}