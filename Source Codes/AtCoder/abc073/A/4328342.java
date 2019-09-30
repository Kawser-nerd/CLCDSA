import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    if(str.charAt(0) == '9' || str.charAt(1) == '9'){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}