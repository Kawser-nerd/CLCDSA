import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) {

    int h = 0;
    int w = 0;
    char[][] square = null;
    String[] tmp = null;
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      tmp = br.readLine().split("\\s");
      h = Integer.parseInt(tmp[0]);
      w = Integer.parseInt(tmp[1]);

      square = new char[h][w];
      for (int i = 0; i < h; i++) {
        square[i] = br.readLine().toCharArray();
      }
    } catch (IOException e) {
      e.printStackTrace();
      System.exit(1);
    }

    boolean result = true;

    parentLoop:
    for (int i = 0; i < square.length; i++) {
      final char[] line = square[i];
      for (int j = 0; j < line.length; j++) {
        if (line[j] == '#') {
          if (0 <= i - 1 && square[i - 1][j] != '#') {
            if (i + 1 < h && square[i + 1][j] != '#') {
              if (0 <= j - 1 && square[i][j - 1] != '#') {
                if (j + 1 < w && square[i][j + 1] != '#') {
                  result = false;
                  break parentLoop;
                }
              }
            }
          }
        }
      }
    }
    if (result) {
      System.out.print("Yes");
    } else {
      System.out.print("No");
    }
  }
}