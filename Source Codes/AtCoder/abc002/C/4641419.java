import java.util.*;

public class Main {
  
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   double x1 = sc.nextDouble();
   double y1 = sc.nextDouble();
   double x2 = sc.nextDouble() - x1;
   double y2 = sc.nextDouble() - y1;
   double x3 = sc.nextDouble() - x1;
   double y3 = sc.nextDouble() - y1;
   System.out.println(Math.abs(x2 * y3 - y2 * x3) / 2);   
 }
  
}