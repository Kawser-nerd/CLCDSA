import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    if(b == 100){
      System.out.println(101 * (int)Math.pow(100, a));
    }else{
      System.out.println(b * (int)Math.pow(100, a));
    }
  }
}