import java.util.*;

public class B {

  public static void main(String args[]) {
    (new B()).exec();
  }

  int prime[];
  int ps;

  void init() {
    prime = new int[1000];
    ps = 0;
    prime[ps++] = 2;
  MAIN:
    for(int i=3; i<=1000; i+=2) {
      for(int j=0; j<ps; ++j) {
        if( i % prime[j] == 0 ) { continue MAIN; }
      }
      prime[ps++] = i;
    }
  }

  boolean contain(int i, int j, int p) {
    for(int a=0; a<ps; ++a) {
      if( prime[a] < p ) { continue; }
      if( prime[a] > i ) { return false; }
      if( i % prime[a] == 0 && j % prime[a] == 0 ) { return true; }
    }
    return false;
  }

  int ans(int a, int b, int p) {
    int own[] = new int[b+1];
    for(int i=a; i<=b; ++i) {
      own[i] = i;
      for(int j=a; j<i; ++j) {
        if( contain(j, i, p) ) {
          int over = own[j];
          for(int k=a; k<i; ++k) {
            if( own[k] == over ) { own[k] = i; }
          }
        }
      }
    }
    HashSet<Integer> h = new HashSet<Integer>();
    for(int i=a; i<=b; ++i) {
      h.add(own[i]);
    }
    return h.size();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    init();

    int z = cin.nextInt();
    for(int a=0; a<z; ++a) {

      int s = cin.nextInt();
      int t = cin.nextInt();
      int p = cin.nextInt();

      System.out.println("Case #" + (a + 1) + ": " + ans(s, t, p));

    }

  }

}
