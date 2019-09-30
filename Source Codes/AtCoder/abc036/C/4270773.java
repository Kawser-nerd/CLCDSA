import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] a = new int[N];
    HashSet<Integer> set = new HashSet<>();
    for (int i = 0; i < N; i++) {
      a[i] = scanner.nextInt();
      set.add(a[i]);
    }

    Integer[] list = set.toArray(new Integer[0]);
    Arrays.sort(list);

    HashMap<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < list.length; i++) map.put(list[i], i);

    for (int an : a) System.out.println(map.get(an));
  }
}