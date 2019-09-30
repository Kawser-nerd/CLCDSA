import java.util.*;

public class Main{

  public static void main(String args[]){

    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int d = b-a;
    int[] push = {0,1,2,3,2,1,2,3,3,2};

    pl(Math.abs(d/10) + push[Math.abs(d%10)]);
  }

  private static void pr(Object o){
    System.out.print(o);
  }
  private static void pl(Object o){
    System.out.println(o);
  }

}