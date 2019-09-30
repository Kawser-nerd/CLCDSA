import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int W = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();
    if(b-W-a > 0){
      System.out.println(b-W-a);
    }else if(a-b-W > 0){
      System.out.println(a-b-W);
    }else{
      System.out.println(0);
    }
  }
}