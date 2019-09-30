import java.util.*;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    String s=sc.next();
    int n=sc.nextInt()-1;
    System.out.print(s.charAt(n/5));
    System.out.println(s.charAt(n%5));
  }
}