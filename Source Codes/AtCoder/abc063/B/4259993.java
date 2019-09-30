import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    while(str.length() != 0){
      int tmp = str.length();
      str = str.replace(str.charAt(0) + "", "");
      if(str.length() - tmp != -1){
        System.out.println("no");
        System.exit(0);
      }
    }
    System.out.println("yes");
  }
}