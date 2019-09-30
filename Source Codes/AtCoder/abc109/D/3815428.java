import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int H = scanner.nextInt();
    int W = scanner.nextInt();
    int[][] a = new int[H+1][W+1];
    int[][] b = new int[H+1][W+1];
    for(int i = 1; i <= H; i++){
      for(int j = 1; j <= W; j++){
        a[i][j] = scanner.nextInt();
        b[i][j] = a[i][j];
      }
    }
    int count = 0;
    for(int i = 1; i <= H; i++){
      for(int j = 1; j < W; j++){
        if(b[i][j] % 2 == 1){
          b[i][j] += -1;
          b[i][j+1] += 1;
          count++;
        }
      }
    }
    for(int i = 1; i < H; i++){
      if(b[i][W] % 2 == 1){
        b[i][W] += -1;
        b[i+1][W] += 1;
        count++;
      }
    }
    System.out.println(count);

    for(int i = 1; i <= H; i++){
      for(int j = 1; j < W; j++){
        if(a[i][j] % 2 == 1){
          a[i][j] += -1;
          a[i][j+1] += 1;
          System.out.println(i + " " + j + " " + i + " " + (j+1));
        }
      }
    }
    for(int i = 1; i < H; i++){
      if(a[i][W] % 2 == 1){
        a[i][W] += -1;
        a[i+1][W] += 1;
        System.out.println(i + " " + W + " " + (i+1) + " " + W);
      }
    }
	}
}