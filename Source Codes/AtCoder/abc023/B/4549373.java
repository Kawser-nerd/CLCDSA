import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    
    if(N % 2 == 0){
      System.out.println(-1);
      System.exit(0);
    }
    String str = sc.nextLine();
    String s = "";
    int count = 0;
    while(s.length() < 100){
      if(count == 0){
        s = "b";
      }else if(count % 3 == 1){
        s = "a" + s + "c";
      }else if(count % 3 == 2){
        s = "c" + s + "a";
      }else{
        s = "b" + s + "b";
      }
      
      if(s.equals(str)){
        System.out.println(count);
        System.exit(0);
      }
      
      count++;
    }
    System.out.println(-1);
  }
}