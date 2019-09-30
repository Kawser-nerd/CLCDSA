import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt() % 500;
    int a = sc.nextInt();
    System.out.println(a >= n ? "Yes" : "No");
  }
}