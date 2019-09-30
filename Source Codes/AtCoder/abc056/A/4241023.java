import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str1 = sc.next();
    String str2 = sc.next();
    boolean flag1 = (str1.equals("H"));
    boolean flag2 = (str2.equals("H"));
    flag2 = (flag1 ? flag2 : !flag2);
    System.out.println(flag2 ? "H" : "D");
  }
}