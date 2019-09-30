import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int W = sc.nextInt();
    char[][] A = new char[8][8];
    for (int i = 0; i < H; i++) {
      A[i] = sc.next().toCharArray();
    }
    int count = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (A[i][j] == '#') {
          count++;
        }
      }
    }
    if (count == H + W - 1) {
      System.out.println("Possible");
    } else {
      System.out.println("Impossible");
    }
  }
}