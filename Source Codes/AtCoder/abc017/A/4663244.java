import java.util.*;
 
public class Main{
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int s1 = Integer.parseInt(s[0]);
    int s2 = Integer.parseInt(s[1]);
    
    String[] t = sc.nextLine().split(" ");
    int t1 = Integer.parseInt(t[0]);
    int t2 = Integer.parseInt(t[1]);
    
    String[] u = sc.nextLine().split(" ");
    int u1 = Integer.parseInt(u[0]);
    int u2 = Integer.parseInt(u[1]);
    
    int m1 = (s1 * s2) / 10;
    int m2 = (t1 * t2) / 10;
    int m3 = (u1 * u2) / 10;
    
    System.out.println(m1 + m2 + m3);
  }
}