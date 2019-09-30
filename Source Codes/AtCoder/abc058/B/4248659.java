import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str1 = sc.next();
    String str2 = sc.next();
    StringBuilder sb = new StringBuilder();
    for(int i = 0; i < str1.length()+str2.length(); i++){
      if(i % 2 == 0){
        System.out.print(str1.charAt(i/2));
      }else{
        System.out.print(str2.charAt(i/2));
      }
    }
    System.out.println();
  }
}