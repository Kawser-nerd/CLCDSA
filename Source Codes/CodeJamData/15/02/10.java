import java.util.*;

public class Pancakes {
  public static void main(String[] _) {
    Scanner sc = new Scanner(System.in);
    int numTests = sc.nextInt();
    for (int test = 1; test <= numTests; ++test) {
      int[] pancakes = new int[sc.nextInt()];
      for (int i = 0; i < pancakes.length; ++i)
        pancakes[i] = sc.nextInt();
      System.out.printf("Case #%d: %d\n", test, getMinutesNeeded(pancakes));
    }
  }

  private static int getMinutesNeeded(int[] pancakes) {
    int bestTime = max(pancakes);
    for (int eatingTime = bestTime; eatingTime > 0; --eatingTime) {
      int time = getSpecialMinutesNeeded(pancakes, eatingTime) + eatingTime;
      bestTime = Math.min(bestTime, time);
    }
    return bestTime;
  }

  private static int getSpecialMinutesNeeded(int[] pancakes, int eatingTime) {
    int specialMinutes = 0;
    for (int n : pancakes) {
      while (n > eatingTime) {
        n -= eatingTime;
        ++specialMinutes;
      }
    }
    return specialMinutes;
  }

  private static int max(int[] arr) {
    int max = arr[0];
    for (int i = 1; i < arr.length; ++i)
      max = Math.max(max, arr[i]);
    return max;
  }
}
