import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
  
    int count = scanner.nextInt();
    int[] scores = new int[count];
    int sum = 0;
    for (int ix = 0; ix < scores.length; ix++) {
      scores[ix] = scanner.nextInt();
      sum += scores[ix];
    }
  
    Arrays.sort(scores);
    for (int ix = 0; ix < scores.length; ix++) {
      if (sum % 10 != 0) break;
      if (scores[ix] % 10 != 0) {
        sum -= scores[ix];
      }
    }
    
    if (sum % 10 != 0) {
      System.out.println(sum);
    } else {
      System.out.println(0);
    }
  }
}