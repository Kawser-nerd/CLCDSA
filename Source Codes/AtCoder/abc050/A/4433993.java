/*
?????ABC_50_A???
*/
import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    String op = sc.next();
    int b = sc.nextInt();
    String plus = "+";
    String minus = "-";
    if(op.equals(plus)){
      System.out.println(a+b);
    }
    else if(op.equals(minus)){
      System.out.println(a-b);
    }
  }
}