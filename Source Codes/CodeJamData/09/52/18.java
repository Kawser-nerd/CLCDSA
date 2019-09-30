import java.util.*;

public class Main {

  int mod = 10009;

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void eval(int t, Scanner cin) {
    String s = cin.next();
    int z = cin.nextInt();
    int d = cin.nextInt();
    String dict[] = new String[d];
    for(int i=0; i<d; ++i) { dict[i] = cin.next(); }
    int table[][] = new int[d][26];
    for(int i=0; i<d; ++i) {
      for(int j=0; j<dict[i].length(); ++j) {
        ++table[i][ dict[i].charAt(j) - 'a' ];
      }
    }
    int ret[] = new int[5];
    for(int i=0; i<d; ++i) {
      int now[] = new int[26];
      add(now, table[i]);
      ret[0] += score(s, now);
      ret[0] %= mod;
      for(int j=0; j<d; ++j) {
        add(now, table[j]);
        ret[1] += score(s, now);
        ret[1] %= mod;
        for(int k=0; k<d; ++k) {
          add(now, table[k]);
          ret[2] += score(s, now);
          ret[2] %= mod;
          for(int l=0; l<d; ++l) {
            add(now, table[l]);
            ret[3] += score(s, now);
            ret[3] %= mod;
            for(int m=0; m<d; ++m) {
              add(now, table[m]);
              ret[4] += score(s, now);
              ret[4] %= mod;
              sub(now, table[m]);
            }
            sub(now, table[l]);
          }
          sub(now, table[k]);
        }
        sub(now, table[j]);
      }
    }

    System.out.print("Case #" + t + ":");
    for(int i=0; i<z; ++i) {
      System.out.print(" " + ret[i]);
    }
    System.out.println();

  }

  int score(String s, int a[]) {
    int ret = 0;
    int base = 1;
    for(int i=0; i<s.length(); ++i) {
      char c = s.charAt(i);
      if( c == '+' ) {
        ret += base;
        ret %= mod;
        base = 1;
      }
      else {
        base *= a[c - 'a'];
        base %= mod;
      }
    }
    ret += base;
    ret %= mod;
    return ret;
  }

  void add(int a[], int b[]) {
    for(int i=0; i<26; ++i) { a[i] += b[i]; }
  }

  void sub(int a[], int b[]) {
    for(int i=0; i<26; ++i) { a[i] -= b[i]; }
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      eval(i + 1, cin);
    }

  }

}
