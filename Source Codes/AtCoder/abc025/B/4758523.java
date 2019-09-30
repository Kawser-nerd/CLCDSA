import java.util.*;
 
public class Main{
  public static int[] dp;
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int N = Integer.parseInt(s[0]);
    int A = Integer.parseInt(s[1]);
    int B = Integer.parseInt(s[2]);
    
    int count = 0;
    for(int i = 0; i < N; i++){
      String[] t = sc.nextLine().split(" ");
      int M = Integer.parseInt(t[1]);
      if(t[0].equals("East")){
        if(M < A){
          count += A;
        }else if(M > B){
          count += B;
        }else{
          count += M;
        }
      }else{
        if(M < A){
          count -= A;
        }else if(M > B){
          count -= B;
        }else{
          count -= M;
        }
      }
    }
    if(count == 0){
      System.out.println(0);
    }else if(count > 0){
      System.out.println("East " + Math.abs(count));
    }else{
      System.out.println("West " + Math.abs(count));
    }
  }
}