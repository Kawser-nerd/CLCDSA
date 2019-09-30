import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  String[] solve(int n, int m, String d[], String l[]) {
    String ret[] = new String[m];
    for(int i=0; i<m; ++i) { ret[i] = solve(n, d, l[i]); }
    return ret;
  }

  String solve(int n, String d[], String s) {
    char map[] = new char[26];
    for(int i=0; i<26; ++i) {
      map[s.charAt(i) - 'a'] = (char)('a' + i);
    }
    Dict D[] = new Dict[n];
    for(int i=0; i<n; ++i) {
      D[i] = new Dict(convert(d[i], map), i);
    }
    return d[find(D, n)];
  }

  class Dict implements Comparable<Dict> {
    String body;
    int index;
    int len;
    String hide;
    int score;
    Dict(String body, int index) {
      this.body = body;
      this.index = index;
      len = body.length();
      hide = "";
      for(int i=0; i<len; ++i) {
        hide += "_";
      }
      score = 0;
    }
    boolean open(char c) {
      String ret = "";
      boolean res = false;
      for(int i=0; i<len; ++i) {
        if( body.charAt(i) == c ) {
          ret += c;
          res = true;
        }
        else { ret += hide.charAt(i); }
      }
      hide = ret;
      return res;
    }
    public int compareTo(Dict d) {
      if( len < d.len ) { return -1; }
      if( len > d.len ) { return 1; }
      return hide.compareTo(d.hide);
    }
  }

  int find(Dict d[], int n) {
    Arrays.sort(d);
    Dict ans = check(0, n, d, 'a');
    return ans.index;
  }

  Dict check(int L, int R, Dict d[], char c) {
    if( L + 1 == R ) { return d[L]; }
    int p = 0;
    Dict ret = null;
    while( p < R ) {
      int q = p + 1;
      while( q < R && d[p].hide.equals(d[q].hide) ) { ++q; }
      boolean open = false;
      boolean memo[] = new boolean[q - p];
      for(int s=p; s<q; ++s) {
        memo[s-p] = d[s].open(c);
        open |= memo[s-p];
      }
      if( open ) {
        for(int s=p; s<q; ++s) {
          if( !memo[s-p] ) { ++d[s].score; }
        }
        Arrays.sort(d, p, q);
      }
      Dict ans = check(p, q, d, (char)(c + 1));
      if( ret == null ) { ret = ans; }
      else { ret = min(ret, ans); }
      p = q;
    }
    return ret;
  }

  Dict min(Dict a, Dict b) {
    if( a.score < b.score ) { return b; }
    if( a.score > b.score ) { return a; }
    if( a.index < b.index ) { return a; }
    return b;
  }

  String convert(String s, char map[]) {
    String ret = "";
    for(int i=0; i<s.length(); ++i) {
      ret += map[s.charAt(i) - 'a'];
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=1; i<=t; ++i) {

      int n = cin.nextInt();
      int m = cin.nextInt();

      String d[] = new String[n];
      for(int j=0; j<n; ++j) { d[j] = cin.next(); }
      String l[] = new String[m];
      for(int j=0; j<m; ++j) { l[j] = cin.next(); }

      String res[] = solve(n, m, d, l);
      System.out.print("Case #" + i + ":");
      for(int j=0; j<m; ++j) { System.out.print(" " + res[j]); }
      System.out.println();

    }

  }

}
