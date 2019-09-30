import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    while(true){
      String tmp = str.replace("1B", "").replace("0B", "");
      if(tmp.equals(str)){
        break;
      }
      str = tmp;
    }
    System.out.println(str.replace("B", ""));
  }
}