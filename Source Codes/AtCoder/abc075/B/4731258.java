import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) {


    int h = 0;
    int w = 0;
    char[][] squares = null;

    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      String[] tmp = br.readLine().split("\\s");
      h = Integer.parseInt(tmp[0]);
      w = Integer.parseInt(tmp[1]);

      squares = new char[h][w];
      for (int i = 0; i < h; i++) {
        squares[i] = br.readLine().toCharArray();
      }

    } catch (IOException e) {
      e.printStackTrace();
      System.exit(1);
    }

    int[][] count = new int[h][w];
    for (int i = 0; i < squares.length; i++) {
      char[] line = squares[i];
      for (int j = 0; j < line.length; j++) {
        if (line[j] == '#') {
          count[i][j] = -1;
          // ?
          if (0 <= i - 1 && squares[i-1][j] != '#') {
            count[i-1][j]++;
          }
          // ?
          if (i + 1 < h && squares[i+1][j] != '#') {
            count[i+1][j]++;
          }
          // ?
          if (0 <= j - 1 && squares[i][j-1] != '#') {
            count[i][j-1]++;
          }
          // ?
          if (j + 1 < w && squares[i][j+1] != '#') {
            count[i][j+1]++;
          }
          // ??
          if (0 <= i - 1 && 0 <= j - 1 && squares[i-1][j-1] != '#') {
            count[i-1][j-1]++;
          }
          // ??
          if (i + 1 < h && 0 <= j - 1 && squares[i+1][j-1] != '#') {
            count[i+1][j-1]++;
          }
          // ??
          if (0 <= i - 1 && j + 1 < w && squares[i-1][j+1] != '#') {
            count[i-1][j+1]++;
          }
          // ??
          if (i + 1 < h &&  j + 1 < w && squares[i+1][j+1] != '#') {
            count[i+1][j+1]++;
          }
        }
      }
    }

    for (int i = 0; i < count.length; i++) {
      int[] result = count[i];
      for (int j = 0; j < result.length; j++) {
        if (result[j] == -1) {
          System.out.print("#");
        } else {
          System.out.print(result[j]);
        }
      }
      System.out.print(System.lineSeparator());
    }
  }
}