import java.util.*;

public class Main {
  public static char[][] A = new char[10][10];
  public static char[][] A_tmp = new char[10][10];

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    for (int i = 0; i < 10; i++) {
      A[i] = sc.next().toCharArray();
    }
    ArrayList<String> sea = new ArrayList<>();
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (A[i][j] == 'x') {
          sea.add(i + ":" + j);
        }
      }
    }
    for (int h = 0; h < sea.size(); h++) {
      int count = 0;
      int x = Integer.parseInt(sea.get(h).split(":")[0]);
      int y = Integer.parseInt(sea.get(h).split(":")[1]);
      init();
      A_tmp[x][y] = 'o';
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          if (A_tmp[i][j] == 'o') {
            dfs(i, j);
            count++;
          }
        }
      }
      if (count == 1) {
        System.out.println("YES");
        return;
      }
    }
    System.out.println("NO");
  }

  public static void init() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        A_tmp[i][j] = A[i][j];
      }
    }
  }

  public static void dfs(int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10 || A_tmp[x][y] == 'x') {
      return;
    }
    A_tmp[x][y] = 'x';
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
  }
}