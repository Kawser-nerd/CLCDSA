import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int hour = a+b;
    if(hour < 24){
      System.out.println(hour);
    }
    else{
      System.out.println(hour%24);
    }
  }
}