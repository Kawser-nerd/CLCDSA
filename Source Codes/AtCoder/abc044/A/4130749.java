import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.next());
    int k = Integer.parseInt(sc.next());
    k = Math.min(n,k);
    int x = Integer.parseInt(sc.next());
    int y = Integer.parseInt(sc.next());
    System.out.println(k * x + (n-k) * y);
  }
}