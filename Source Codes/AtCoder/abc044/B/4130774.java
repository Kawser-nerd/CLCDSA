import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    if(str.length() % 2 != 0){
      System.out.println("No");
      System.exit(0);
    }
    while(true){
      String tmp = str.replace(String.valueOf(str.charAt(0)), "");
      if((str.length() - tmp.length()) % 2 != 0){
        System.out.println("No");
        System.exit(0);
      }else if(tmp.length() == 0){
        System.out.println("Yes");
        System.exit(0);
      }
      str = tmp;
    }
  }
}