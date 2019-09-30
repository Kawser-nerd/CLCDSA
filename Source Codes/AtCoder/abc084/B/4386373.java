import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    String[] str = sc.next().split("-");
    if(str.length == 2){
      if(str[0].length() == a && str[1].length() == b){
        System.out.println("Yes");
      }else{
        System.out.println("No");
      }
    }else{
      System.out.println("No");
    }
  }
}