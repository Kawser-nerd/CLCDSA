import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class GoroSort {
  private static final DecimalFormat FORMATTER = new DecimalFormat("0.000000");
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i<numExamples; i++) {
        br.readLine();
        String[] values = br.readLine().split(" ");
        int[] v = new int[values.length];
        int outOfPlace = 0;
        for (int j = 0; j < values.length; j++) {
          v[j] = Integer.parseInt(values[j]);
          if (v[j] != j+1) {
            outOfPlace++;
          }
        }
        System.out.println("Case #" + (i + 1) + ": " + FORMATTER.format(outOfPlace));
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }
  }
}
