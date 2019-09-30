import java.util.*;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int D = sc.nextInt();
    int N = sc.nextInt();
    int ans = (int)Math.pow(100,D);
    
    if(N==100){
      System.out.println(ans*101);
    }
    else{
      System.out.println(ans*N);
    }

  }
}