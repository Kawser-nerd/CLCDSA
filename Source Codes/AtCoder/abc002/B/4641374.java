import java.util.*;

public class Main {
  
  public static String S;
  
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   S = sc.next();
   replace("a");
   replace("i");
   replace("u");
   replace("e");
   replace("o");
   System.out.println(S);
 }
  
 public static void replace(String s){
   S = S.replace(s, "");
 }
  
}