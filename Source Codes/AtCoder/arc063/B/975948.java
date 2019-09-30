import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int t = s.nextInt();
    int minAi = Integer.MAX_VALUE;
    int maxValue = 0;
    int maxValuePairs = 0;
    for (int i = 0; i < n; i++) {
      int ai = s.nextInt();
      minAi = Math.min(minAi, ai);
      if (ai - minAi > maxValue) {
        maxValue = ai - minAi;
        maxValuePairs = 1;
      } else if (ai - minAi == maxValue) {
        maxValue = ai - minAi;
        maxValuePairs++;
      }
    }
    System.out.println(maxValuePairs);
  }
}