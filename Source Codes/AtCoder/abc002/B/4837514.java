import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String W = sc.next();
    String r = W.replaceAll("[a,i,u,e,o]+", "");
    System.out.println(r);
  }
}