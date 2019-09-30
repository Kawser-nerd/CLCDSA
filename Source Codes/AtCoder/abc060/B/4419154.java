import java.util.*;

public class Main{
  public static void main (String[]args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int N = sc.nextInt();
    int S = sc.nextInt();
    boolean c = false;
    for(int i = 1; i<= N; i++){
      if((i * A) % N == S){
        c = true;
      }
    }
    if(c){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}