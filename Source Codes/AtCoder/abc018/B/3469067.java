import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    String S = scanner.next();
    int N = scanner.nextInt();

    int[] L = new int[N];
    int[] R = new int[N];
    for(int i = 0; i < N; i++){
      L[i] = scanner.nextInt()-1;
      R[i] = scanner.nextInt()-1;
    }
    char[] c = new char[S.length()];
    for(int i = 0; i < S.length(); i++){
      c[i] = S.charAt(i);
    }
    for(int i = 0; i < N; i++){
      for(int j = L[i]; j <= (L[i]+R[i])/2; j++){
        char t = c[j];
        c[j] = c[L[i]+R[i]-j];
        c[L[i]+R[i]-j] = t;
      }
    }
    for(int i = 0; i < S.length(); i++){
      System.out.print(c[i]);
    }
    System.out.println();
  }
}