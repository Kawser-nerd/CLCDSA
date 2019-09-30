import java.util.*;
 
public class Main{
  public static int[] dp;
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    String s = "" + a + b;
    int c = Integer.parseInt(s);
    System.out.println(c * 2);
  }
}