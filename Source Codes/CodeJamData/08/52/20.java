import java.util.*;

public class B {

  public static void main(String args[]) {
    (new B()).exec();
  }

  private int dx[] = { 1, 0, -1, 0 };
  private int dy[] = { 0, 1, 0, -1 };

  int check(int w, int h, String map[]) {

    ArrayList<int[]> queue = new ArrayList<int[]>();
    int cake[] = new int[2];

    int score[][] = new int[w][h];
    boolean used[][] = new boolean[w][h];

    for(int i=0; i<w; ++i) {
      for(int j=0; j<h; ++j) {
        if( map[j].charAt(i) == 'O' ) {
          queue.add(new int[] { i, j, 0 });
          used[i][j] = true;
        }
        if( map[j].charAt(i) == 'X' ) {
          cake = new int[] { i, j };
        }
      }
    }

    for(int z=0; z<queue.size(); ++z) {
      int pos[] = queue.get(z);
      if( pos[0] == cake[0] && pos[1] == cake[1] ) { break; }
      for(int j=0; j<4; ++j) {
        int x = pos[0] + dx[j];
        int y = pos[1] + dy[j];
        if( x < 0 || y < 0 || x >= w || y >= h || map[y].charAt(x) == '#' || used[x][y] ) { continue; }
        score[x][y] = score[pos[0]][pos[1]] + 1;
        used[x][y] = true;
        queue.add(new int[] { x, y, z });
      }
      if( wall(map, pos[0], pos[1], w, h) ) {
        for(int i=pos[0]+1; i<=w; ++i) {
          if( i == w || map[pos[1]].charAt(i) == '#' ) {
            int x = i - 1;
            int y = pos[1];
            if( used[x][y] ) { break; }
            score[x][y] = score[pos[0]][pos[1]] + 1;
            used[x][y] = true;
            queue.add(new int[] { x, y, z });
            break;
          }
        }
        for(int i=pos[0]-1; i>=-1; --i) {
          if( i == -1 || map[pos[1]].charAt(i) == '#' ) {
            int x = i + 1;
            int y = pos[1];
            if( used[x][y] ) { break; }
            score[x][y] = score[pos[0]][pos[1]] + 1;
            used[x][y] = true;
            queue.add(new int[] { x, y, z });
            break;
          }
        }
        for(int j=pos[1]+1; j<=h; ++j) {
          if( j == h || map[j].charAt(pos[0]) == '#' ) {
            int x = pos[0];
            int y = j - 1;
            if( used[x][y] ) { break; }
            score[x][y] = score[pos[0]][pos[1]] + 1;
            used[x][y] = true;
            queue.add(new int[] { x, y, z });
            break;
          }
        }
        for(int j=pos[1]-1; j>=-1; --j) {
          if( j == -1 || map[j].charAt(pos[0]) == '#' ) {
            int x = pos[0];
            int y = j + 1;
            if( used[x][y] ) { break; }
            score[x][y] = score[pos[0]][pos[1]] + 1;
            used[x][y] = true;
            queue.add(new int[] { x, y, z });
            break;
          }
        }
      }
    }

    return score[cake[0]][cake[1]];

  }

  boolean wall(String map[], int x, int y, int w, int h) {
    for(int i=0; i<4; ++i) {
      int a = x + dx[i];
      int b = y + dy[i];
      if( a < 0 || b < 0 || a >= w || b >= h || map[b].charAt(a) == '#' ) { return true; }
    }
    return false;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int time = cin.nextInt();

    for(int count=0; count<time; ++count) {

      int h = cin.nextInt();
      int w = cin.nextInt();
      String map[] = new String[h];
      for(int i=0; i<h; ++i) { map[i] = cin.next(); }

      int ans = check(w, h, map);
      System.out.println("Case #" + (count + 1) + ": " + (ans == 0 ? "THE CAKE IS A LIE" : "" + ans) );

    }

  }

}
