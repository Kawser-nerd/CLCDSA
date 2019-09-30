import java.util.*;
import java.io.*;
class Main{
  public static void main(String[] args) throws Exception{
    Scanner sc = new Scanner(System.in);
    StringBuilder sb = new StringBuilder();
    int w = sc.nextInt(), h = sc.nextInt(), q = sc.nextInt();
    char[][] field = new char[w][];
    int[][] x_edge_map = new int[w][], y_edge_map = new int[w][], node_map = new int[w][];
    for(int i = 0; i < w; i++){
      field[i] = sc.next().toCharArray();
      x_edge_map[i] = new int[h];
      y_edge_map[i] = new int[h];
      node_map[i] = new int[h];
    }

    for(int row_index = 0; row_index < field.length; row_index++){
      char[] row = field[row_index];

      for(int index = 0; index < row.length; index++){
        char cell = row[index];
        if(index != 0){
          x_edge_map[row_index][index] = x_edge_map[row_index][index - 1] - (cell == '1' && cell == row[index - 1] ? 1 : 0);
        }
        if(row_index != 0) y_edge_map[row_index][index] = y_edge_map[row_index - 1][index] - (cell == '1' && cell == field[row_index - 1][index] ? 1 : 0);
        node_map[row_index][index] = idx(node_map, row_index, index - 1) + (cell == '1' ? 1 : 0);
      }
    }


    y_accumulation(x_edge_map);
    x_accumulation(y_edge_map);
    y_accumulation(node_map);
    for(int i = 0; i < q; i++){
      int sy = sc.nextInt() - 1, sx = sc.nextInt() - 1, ey = sc.nextInt() - 1, ex = sc.nextInt() - 1;
      sb.append(
      x_edge_map[ey][ex] - idx(x_edge_map,sy-1,ex) - (x_edge_map[ey][sx] - idx(x_edge_map,sy-1,sx)) +
      y_edge_map[ey][ex] - y_edge_map[sy][ex] - (idx(y_edge_map,ey,sx-1) - idx(y_edge_map,sy,sx-1)) +
      node_map[ey][ex] - idx(node_map,sy-1,ex) - (idx(node_map,ey,sx-1) - idx(node_map,sy-1,sx-1))
      );
      sb.append("\n");
    }
    System.out.println(sb);
  }

  private static int idx(int[][] array, int y, int x){
    if(y < 0 || x < 0) return 0;
    return array[y][x];
  }

  private static void y_accumulation(int[][] array){
    for(int i = 1; i < array.length; i++){
      int[] v = array[i];
      for(int j = 0; j < v.length; j++){
        v[j] += array[i - 1][j];
      }
    }
  }

  private static void x_accumulation(int[][] array){
    for(int[] v: array){
      for(int i = 1; i < v.length; i++){
        v[i] += v[i - 1];
      }
    }
  }
}