import java.util.*;

public class Main{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
   int x = sc.nextInt();
   int num=0;
   while(x>0){
     num++;
     x-=2;
   }
   System.out.println(num);
 }
}