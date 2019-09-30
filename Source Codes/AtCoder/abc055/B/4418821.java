import java.util.*;

public class Main{
  public static void main (String[]args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    
    long n = 1l;
    for(int i = 1; i <= N; i++){
      n = (n * i) % 1000000007;
    }
    System.out.println(n);
  }
}