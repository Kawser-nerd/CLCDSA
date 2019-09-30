import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();

    final long M = 1_000_000_007;
    String[] words = line.split(" ");
    int H = Integer.parseInt(words[0]);
    int W = Integer.parseInt(words[1]);
    PriorityQueue<Cell> queue = new PriorityQueue<>(Comparator.comparingInt(c -> c.v));
    Cell[][] cells = new Cell[H][W];
    for (int i = 0; i < H; i++) {
      line = br.readLine();
      words = line.split(" ");
      for (int j = 0; j < W; j++) {
        Cell c = new Cell(i, j, Integer.parseInt(words[j]));
        queue.add(c);
        cells[i][j] = c;
      }
    }

    long sum = 0;
    while (!queue.isEmpty()) {
      Cell c = queue.poll();
      long v = c.d;
      sum += v;
      if (sum >= M) sum -= M;
      for (int[] dd : new int[][] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
        int nx = c.x + dd[0];
        int ny = c.y + dd[1];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && cells[nx][ny].v > c.v) {
          cells[nx][ny].d += v;
          if (cells[nx][ny].d >= M) cells[nx][ny].d -= M;
        }
      }
    }
    System.out.println(sum);
  }

  private static class Cell {
    final int x;
    final int y;
    final int v;
    long d = 1L;

    private Cell(int x, int y, int v) {
      this.x = x;
      this.y = y;
      this.v = v;
    }
  }
}