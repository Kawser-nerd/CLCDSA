import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int xa = sc.nextInt();
    int ya = sc.nextInt();
    int xb = sc.nextInt();
    int yb = sc.nextInt();
    int xc = sc.nextInt();
    int yc = sc.nextInt();

    int a = xb - xa;
    int b = yb - ya;
    int c = xc - xa;
    int d = yc - ya;
    
    double r = (double) Math.abs( a * d - b * c ) / 2;

    System.out.println( r );
    
  }
}