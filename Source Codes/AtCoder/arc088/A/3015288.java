import java.util.*;
import java.lang.*;

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      long X = Long.parseLong(sc.next());
      long Y = Long.parseLong(sc.next());
      long a = X;
      long cnt = 0;
      while(a<=Y){
        a*=2;
        cnt++;
      }
      System.out.println(cnt);
  }
}