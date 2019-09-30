import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int N = Integer.parseInt(s[0]);
    int M = Integer.parseInt(s[1]);
    
    for(int i = 0; i <= 1; i++){
      for(int j = 0; j <= N-i; j++){
        int k = N - i - j;
        if((i * 3) + (j * 2) + (k * 4) == M){
          System.out.println(j + " " + i + " " + k);
          System.exit(0);
        }
      }
    }
    System.out.println("-1 -1 -1");
  }
}