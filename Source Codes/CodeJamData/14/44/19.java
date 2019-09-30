import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.System.*;

public class D {
  public static String[] parts(BufferedReader br) throws Exception {
    String line = br.readLine();
    if (line == null) return null;
    return line.trim().split("\\s+");
  }
  
  public static void main(String args[]) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(in));
    
    int cas = parseInt(br.readLine());
    for(int z=1;z<=cas;z++) {
      String[] ss = parts(br);
      
      int M = parseInt(ss[0]);
      int N = parseInt(ss[1]);
      String[] S = new String[M];
      for(int i=0;i<M;i++) {
        S[i] = br.readLine();
      }
      
      LL[] arr = new LL[N];
      for(int i=0;i<N;i++) arr[i] = new LL();
      
      out.println("Case #"+z+": "+ go(arr, 0, M, N, S));
    }
  }
  
  static Pair go(LL[] arr, int k, int M, int N, String[] ss) {
    if(k == M) {
      for(int i=0;i<N;i++) if (arr[i].size() == 0) return new Pair(INF, 1);
      int sum = 0;
      for(int i=0;i<N;i++) {
        sum += count(arr[i]);
      }
      return new Pair(sum, 1);
    }
    int max = 0;
    int count = 0;
    int sum = 0;
    for(int i=0;i<N;i++) {
      arr[i].add(ss[k]);
      Pair p = go(arr, k+1, M, N, ss);
      if (p.u > max) {
        max = p.u;
        count = p.v;
      } else if (p.u == max) {
        count += p.v;
      }
      arr[i].removeLast();
    }
    return new Pair(max, count);
  }
  
  static int count(LL g) {
    Node root = new Node();
    for(String s : g) {
      root.add(s, 0);
    }
    return root.size();
  }
  
  static class Node {
    HashMap<Character, Node> root;
    
    Node() {
      root = new HashMap<Character, Node>();
    }
    
    public void add(String s, int k) {
      if (k == s.length()) return;
      char c = s.charAt(k);
      if (root.containsKey(c)) {
        root.get(c).add(s, k+1);
      } else {
        root.put(c, new Node());
        root.get(c).add(s, k+1);
      }
    }
    
    public int size() {
      int sum = 1;
      for(char c : root.keySet()) {
        sum += root.get(c).size();
      }
      return sum;
    }
  }
  
  static class Pair {
    int u, v;
    
    Pair(int a, int b) {
      u = a;
      v = b;
    }
    
    public String toString() {
      return u+" "+v;
    }
  }
  
  static class LL extends LinkedList<String> {}
    
  static final int INF = -1;
}
