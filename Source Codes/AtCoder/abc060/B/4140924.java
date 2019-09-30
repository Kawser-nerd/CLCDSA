import java.util.*;
public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    String ans = "NO";
    for(int i=0;i<=100;i++){
      if(A*i%B==C){
        ans="YES";
        break;
      }
    }
    System.out.println(ans);
  }
}