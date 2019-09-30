import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    String[] s = new String[N];
    int[] d = new int[N];
    int ans = 0;
    for(int i = 0; i < N; i++){
      s[i] = scanner.next();
      d[i] = scanner.nextInt();
    }
    for(int i = 0; i < N; i++){
      if(s[i].equals("East")){
        if(d[i] < A){
          ans += A;
        }else if(A <= d[i] && d[i] <= B){
          ans += d[i];
        }else if(d[i] > B){
          ans += B;
        }
      }
      if(s[i].equals("West")){
        if(d[i] < A){
          ans -= A;
        }else if(A <= d[i] && d[i] <= B){
          ans -= d[i];
        }else if(d[i] > B){
          ans -= B;
        }
      }
    }
    if(ans == 0){
      System.out.println(0);
    }else if(ans > 0){
      System.out.println("East" + " " + ans);
    }else if(ans < 0){
      System.out.println("West" + " " + Math.abs(ans));
    }
  }
}