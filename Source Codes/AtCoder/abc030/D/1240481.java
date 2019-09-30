import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long N = sc.nextLong();
    long a = sc.nextLong();
    String k = sc.next();
    long[] b = new long[(int)N];
    for(int i = 0; i < N; i++) {
      b[i] = sc.nextLong();
    }
    ArrayList<Long> f = new ArrayList<Long>();
    f.add(a);
    long presence = a;
    long s = 0;
    long g = 1;
    for(int i = 0; i < N; i++) {
      presence = b[(int)presence - 1];
      if(f.contains(presence)) {
        for(int j = 0; j < N; j++) {
          if(f.get(j) == presence) {
            s = (long)j;
            g = (long)(i + 1) - s;
            break;
          }
        }
        break;
      } else {
        f.add(presence);
      }
    }
    long ans = 0;

    if(k.length() <= 6) {
      int step = Integer.parseInt(k);
      int p = (int)a;
      for(int i = 0; i < step; i++) {
        p = (int)b[p - 1];
      }
      ans = p;
    } else {
      // s+t?g??????
      long r = 0;
      if(k.length() <= 18) {
        r = (Long.parseLong(k)) % g;
      } else {
        for(int i = 0; i < k.length(); i++) {
          long d = Long.parseLong(String.valueOf(k.charAt(i)));
          r = (10 * r + d) % g;
        }
      }
      while(r < s) {
        r += g;
      }  
      ans = f.get((int)r);
    }
    System.out.println(ans);
  }
}