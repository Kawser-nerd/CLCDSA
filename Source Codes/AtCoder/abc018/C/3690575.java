import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int R = scanner.nextInt();
    int C = scanner.nextInt();
    int K = scanner.nextInt();
    String[] s = new String[R];
    char[][] field = new char[R][C];
    for(int i = 0; i < R; i++){
      s[i] = scanner.next();
    }
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        field[i][j] = s[i].charAt(j);
      }
    }
    int[][] up = new int[R][C];
    int[][] down = new int[R][C];
    for(int j = 0; j < C; j++){
      if(field[0][j] == 'o'){
        up[0][j] = 1;
      }
    }
    for(int j = 0; j < C; j++){
      if(field[R-1][j] == 'o'){
        down[R-1][j] = 1;
      }
    }
    for(int i = 1; i < R; i++){
      for(int j = 0; j < C; j++){
        if(field[i][j]=='o'){
          up[i][j] = up[i-1][j]+1;
        }
      }
    }
    for(int i = R-2; i >= 0; i--){
      for(int j = 0; j < C; j++){
        if(field[i][j]=='o'){
          down[i][j] = down[i+1][j]+1;
        }
      }
    }
    int count = 0;
    for(int x = K - 1; x <= R - K; x++){
      for(int y = K - 1; y <= C - K; y++){
        boolean flag = true;
        for(int z = y - (K - 1); z <= y + (K - 1); z++){
          if(up[x][z] <= K-1-Math.abs(y-z) || down[x][z] <= K-1-Math.abs(y-z)){
            flag = false;
            break;
          }
        }
        if(flag){
          count++;
        }
      }
    }
    System.out.println(count);
  }
}