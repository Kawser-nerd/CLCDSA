import java.util.*;
 
class Main {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
     
     int a = sc.nextInt();
     int b = sc.nextInt();
     
     int cnt = 0;
     if (a <= b)
       cnt = a;
     else
       cnt = a-1;
     
     System.out.println(cnt);
   }
}