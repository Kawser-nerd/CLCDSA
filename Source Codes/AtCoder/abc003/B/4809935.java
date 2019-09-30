//AtCoder????

import java.util.*;

class Main{
  public static boolean d;
  public static int fun1(String s, String t){
    char[] charlist= {'a','t','c','o','d','e','r'};
    int i= s.length();
    for (int n= 0; n<i; n++) {
      d= false;
      if (s.charAt(n)!=t.charAt(n)) {
        if (s.charAt(n)!='@' && t.charAt(n)!='@') {
          return 0;
        }else if (s.charAt(n)=='@' && t.charAt(n)!='@') {
          for (char target: charlist) {
            if (t.charAt(n)==target) {
              d= true;
              break;
            }
          }
          if (d==false) {
            return 0;
          }
        }else if (s.charAt(n)!='@' && t.charAt(n)=='@') {
          for (char target: charlist) {
            if (s.charAt(n)==target) {
              d= true;
              break;
            }
          }
          if (d==false) {
            return 0;
          }
        }
      }
    }
    return 1;
  }
  public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    String s= sc.nextLine();
    String t= sc.nextLine();
    int result= fun1(s, t);
    if (result==0) {
      System.out.println("You will lose");
    }else{
      System.out.println("You can win");
    }
  }
}