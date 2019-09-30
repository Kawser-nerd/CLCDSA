import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();
    System.out.println(x - (a + (x - a) / b * b));
  }
}