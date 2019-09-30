import java.util.*;
public class Main {
  static int H, W, N;
  static int[][] ans;
  // ??
  static void snake(int n, int x){
    int h = n / W;
    int w = n % W;
    if(h % 2 == 1)
      w = W - w - 1;
    ans[h][w] = x + 1;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    H = sc.nextInt();
    W = sc.nextInt();
    N = sc.nextInt();
    ArrayList<Integer> nums = new ArrayList<>();
    for(int i = 0; i < N; i++) {
      int a = sc.nextInt();
      for(int j = 0; j < a; j++)
        nums.add(i);
    }
    ans = new int[H][W];
    for(int n = 0; n < nums.size(); n++){
      snake(n, nums.get(n));
    }
    for(int i = 0; i < H; i++){
      System.out.print(ans[i][0]);
      for(int j = 1; j < W; j++)
        System.out.print(" " + ans[i][j]);
      System.out.print('\n');
    }
  }
}