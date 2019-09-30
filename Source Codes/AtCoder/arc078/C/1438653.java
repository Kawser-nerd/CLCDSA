import java.util.Scanner;

public class Main{
  static final long n = 10;

  static final boolean DEBUG = false;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    StringBuilder left = new StringBuilder("1");
    StringBuilder right = new StringBuilder("10");
    boolean foundLength = false;
    int length = 1;
    while(true){
      System.out.println("? " + left);
      System.out.flush();
      //boolean ans1 = question(Long.decode(left.toString()));
      boolean ans1 = sc.next().equals("Y");
      assert ans1 == question(Long.decode(left.toString()));
      System.out.println("? " + right);
      System.out.flush();
      boolean ans2 = sc.next().equals("Y");
      assert ans2 == question(Long.decode(right.toString()));
      //boolean ans2 = question(Long.decode(right.toString()));
      if(ans1 && !ans2){
        foundLength = true;
        break;
      }
      if(length >= 10){
        break;
      }
      length++;
      left.append("0");
      right.append("0");
    }

    if(DEBUG){
      System.out.println("length = " + length);
    }

    if(foundLength){
      if(DEBUG){
        System.out.println("left = " + left);
        System.out.println("right = " + right);
      }
      long low = 1;
      for(int i = 0; i < length - 1; i++){
        low *= 10;
      }
      long high = 1;
      for(int i = 0; i < length; i++){
        high *= 10;
      }
      high--;
      if(DEBUG){
        System.out.println("low = " + low);
        System.out.println("high = " + high);
      }
      while(high - low > 1){
        long mid = (low + high) / 2;
        System.out.println("? " + (mid * 10L));
        System.out.flush();
        //boolean ans = question(mid * 10);
        boolean ans = sc.next().equals("Y");
        assert ans == question(mid * 10L);
        if(DEBUG){
          System.out.println("mid = " + mid);
          System.out.println(ans);
        }
        if(ans){
          high = mid;
        }
        else{
          low = mid;
        }
      }
      System.out.println("! " + high);
    }
    else{
      // 1, 100, 1000, 10000
      long v = 10;
      while(v <= 1000000000){
        //boolean ans1 = question(v - 1);
        System.out.println("? " + (v - 1));
        System.out.flush();
        boolean ans1 = sc.next().equals("Y");
        assert ans1 == question(v - 1);
        //boolean ans2 = question(v + 1);
        System.out.println("? " + (v + 1));
        System.out.flush();
        boolean ans2 = sc.next().equals("Y");
        assert ans2 == question(v + 1);
        if(!ans1 && ans2){
          System.out.println("! " + v);
          return;
        }
        v *= 10L;
      }
      System.out.println("! " + 1);
    }
  }

  private static boolean question(long x){
    return (x <= n && Long.toString(x).compareTo(Long.toString(n)) <= 0) ||
      (x > n && Long.toString(x).compareTo(Long.toString(n)) > 0);
  }
}