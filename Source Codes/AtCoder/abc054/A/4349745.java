import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      int a=sc.nextInt();
      int b=sc.nextInt();
      if(a==1)a=14;
      if(b==1)b=14;
      System.out.println((a==b)?"Draw":(a<b)?"Bob":"Alice");
      
    }
}