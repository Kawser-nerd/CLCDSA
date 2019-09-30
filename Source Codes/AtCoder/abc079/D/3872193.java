import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int H = scanner.nextInt();
    int W = scanner.nextInt();
    int[][] c = new int[10][10];
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        c[i][j] = scanner.nextInt();
      }
    }
    for(int k = 0; k < 10; k++){
      for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
          if(c[i][j] > c[i][k]+c[k][j]){
            c[i][j] = c[i][k]+c[k][j];
          }
        }
      }
    }
    int count = 0;
    int x;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        if((x = scanner.nextInt()) != -1){
          count += c[x][1];
        }
      }
    }
    System.out.println(count);
  }
}