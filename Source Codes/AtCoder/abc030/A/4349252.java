import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      int a=sc.nextInt();
      int b=sc.nextInt()*sc.nextInt();
      a*=sc.nextInt();
      System.out.println((a==b)?"DRAW":(a<b)?"TAKAHASHI":"AOKI");
    }
}