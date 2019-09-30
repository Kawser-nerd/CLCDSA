import java.util.*;

public class Main {
  public static class Pair {
    int index;
    int value;

    public Pair(int index, int value) {
      this.index = index;
      this.value = value;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    ArrayList<Pair> list = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      int index = i;
      int value = sc.nextInt();
      Pair p = new Pair(index, value);
      list.add(p);
    }
    Collections.sort(list, (a, b) -> a.value - b.value);
    int before = Integer.MAX_VALUE;
    int nValue = -1;
    for (int i = 0; i < list.size(); i++) {
      int tmp = list.get(i).value;
      if (tmp != before) {
        before = tmp;
        nValue++;
      }
      list.get(i).value = nValue;
    }
    Collections.sort(list, (a, b) -> a.index - b.index);
    for (int i = 0; i < list.size(); i++) {
      System.out.println(list.get(i).value);
    }
  }
}