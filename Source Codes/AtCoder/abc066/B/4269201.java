import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    while(true){
      str = str.substring(0, str.length() - 2);
      String tmp1 = str.substring(0, str.length()/2);
      String tmp2 = str.substring(str.length()/2, str.length());
      if(tmp1.equals(tmp2)){
        System.out.println(str.length());
        break;
      }
    }
  }
}