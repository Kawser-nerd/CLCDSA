import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int s = k * (int)Math.pow(k-1,n-1);
    System.out.println(s);
  }
}