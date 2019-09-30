import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class CandySplit {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i<numExamples; i++) {
        br.readLine();
        String[] values = br.readLine().split(" ");
        int result = 0;
        int sum = 0;
        int min = Integer.MAX_VALUE;
        int[] v = new int[values.length];
        for (int j = 0; j < values.length; j++) {
          v[j] = Integer.parseInt(values[j]);
          result ^= v[j];
          sum += v[j];
          min = Math.min(min, v[j]);
        }
        if (result != 0) {
          System.out.println("Case #" + (i + 1) + ": " + "NO");
        } else {
          System.out.println("Case #" + (i + 1) + ": " + (sum-min));
        }
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }
  }
}
