import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    String[] S = new String[N];
    for(int i = 0; i < N; i++){
      S[i] = scanner.next();
    }
    char[][] s = new char[N][N];
    char[][] t = new char[N][N];
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        s[i][j] = S[i].charAt(j);
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        t[j][N-i-1] = s[i][j];
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        System.out.print(t[i][j]);
      }
      System.out.println();
    }
  }
}