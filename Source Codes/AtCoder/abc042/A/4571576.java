import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    Map<Integer, Integer> seen = new HashMap<>();
    for (int ix = 0; ix < 3; ix++) {
      int value = scanner.nextInt();
      seen.put(value, seen.getOrDefault(value, 0) + 1);
    }

    boolean result = seen.containsKey(5)
      && seen.containsKey(7)
      && seen.get(5) == 2
      && seen.get(7) == 1;
    
    System.out.println(result ? "YES" : "NO");
  }
}