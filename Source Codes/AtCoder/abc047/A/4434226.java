import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int left;
    if(a > b && a > c){
      left = a;
      if(left == b+c){
        System.out.println("Yes");
      }
      else{
        System.out.println("No");
      }
    }
    else if(b > a && b > c){
      left = b;
      if(left == a+c){
        System.out.println("Yes");
      }
      else{
        System.out.println("No");
      }
    }
    else{
      left = c;
      if(left == a+b){
        System.out.println("Yes");
      }
      else{
        System.out.println("No");
      }
    }
  }
}