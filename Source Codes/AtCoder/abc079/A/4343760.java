import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    if(str.charAt(0) == str.charAt(1) && str.charAt(1) ==str.charAt(2)){
      System.out.println("Yes");
    }else if(str.charAt(1) == str.charAt(2) && str.charAt(2) ==str.charAt(3)){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}