import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    for(int i = 0; i < s.length(); i++){
      s = s.charAt(s.length() - 1) + s.substring(0, s.length()-1);
      if(s.equals(t)){
        System.out.println("Yes");
        System.exit(0);
      }
    }
    System.out.println("No");
  }
}