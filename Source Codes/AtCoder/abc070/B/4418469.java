import java.util.*;

public class Main{
  public static void main (String[]args){
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int n1 = Integer.parseInt(s[0]);
    int n2 = Integer.parseInt(s[1]);
    int n3 = Integer.parseInt(s[2]);
    int n4 = Integer.parseInt(s[3]);
    
    int st = 0;
    int en = 0;
    if(n1 > n3){
      st = n1;
    }else{
      st = n3;
    }
    
    if(n2 < n4){
      en = n2;
    }else{
      en = n4;
    }
    
    if(en -st > 0){
      System.out.println(en - st);
    }else{
      System.out.println(0);
    }
  }
}