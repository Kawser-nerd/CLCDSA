import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class A {
  static int R, C;
  static int size;
  
  public static void main(String[] args) throws IOException {
    Scanner s = new Scanner(new File("A.in"));
    int T = s.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      HashSet<String> visited = new HashSet<String>();
      R = s.nextInt();
      C = s.nextInt();
      
      String read = "";
      for (int i = 0; i < R; i++) {
        read += s.next();
      }
      String goal = read.replace('o', '.').replace('w', 'o').replace('x', 'o');
      String start = read.replace('x', '.').replace('w', 'o');
      size = start.split("o").length - 1;
      
      visited.add(start);
      Queue<State> queue = new LinkedList<State>();
      queue.add(new State(start, 0));
      int answer = -1;
      while (!queue.isEmpty()) {
        State cur = queue.remove();
        if (cur.s.equals(goal)) {
          answer = cur.c;
          break;
        }
        for (int r = 0; r < R; r++) {
          for (int c = 0; c < C; c++) {
            if (cur.s.charAt(r * C + c) == 'o') {
              if (r > 0 && cur.s.charAt(C * (r - 1) + c) == '.' && r < R - 1 && cur.s.charAt(C * (r + 1) + c) == '.') {
                char[] cc = cur.s.toCharArray();
                cc[r * C + c] = '.';
                cc[(r - 1) * C + c] = 'o';
                String str = new String(cc);
                State next = new State(str, cur.c + 1);
                if ((cur.isStable() || next.isStable()) && !visited.contains(str)) {
                  visited.add(str);
                  queue.add(next);
                }
                cc = cur.s.toCharArray();
                cc[r * C + c] = '.';
                cc[(r + 1) * C + c] = 'o';
                str = new String(cc);
                next = new State(str, cur.c + 1);
                if ((cur.isStable() || next.isStable()) && !visited.contains(str)) {
                  visited.add(str);
                  queue.add(next);
                }
              }
              if (c > 0 && cur.s.charAt(C * (r) + c - 1) == '.' && c < C - 1 && cur.s.charAt(C * (r) + c + 1) == '.') {
                char[] cc = cur.s.toCharArray();
                cc[r * C + c] = '.';
                cc[(r) * C + c - 1] = 'o';
                String str = new String(cc);
                State next = new State(str, cur.c + 1);
                if ((cur.isStable() || next.isStable()) && !visited.contains(str)) {
                  visited.add(str);
                  queue.add(next);
                }
                cc = cur.s.toCharArray();
                cc[r * C + c] = '.';
                cc[r * C + c + 1] = 'o';
                str = new String(cc);
                next = new State(str, cur.c + 1);
                if ((cur.isStable() || next.isStable()) && !visited.contains(str)) {
                  visited.add(str);
                  queue.add(next);
                }
              }

            }
          }
        }
      }
      
      System.out.println("Case #" + tc + ": " + answer);
    }
  }
  
  static class State {
    String s;
    int c;
    boolean stable;
    boolean stableComputed;
    
    public State(String s, int c) {
      this.s = s;
      this.c = c;
    }
    
    public void print() {
      for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
          System.out.print(s.charAt(r * C + c));
        }
        System.out.println();
      }
    }
    
    public boolean isStable() {
      if (stableComputed) return stable;
      stableComputed = true;
      Arrays.fill(mark, false);
      int count = recFill(s.indexOf('o'));
      return stable = size == count;
    }
    
    int recFill(int index) {
      if (mark[index]) return 0;
      mark[index] = true;
      if (s.charAt(index) != 'o') return 0;
      int count = 1;
      int r = index / C;
      int c = index % C;
      if (r > 0) count += recFill(C * (r - 1) + c);
      if (r < R - 1) count += recFill(C * (r + 1) + c);
      if (c > 0) count += recFill(C * (r) + c - 1);
      if (c < C - 1) count += recFill(C * (r) + c + 1);
      return count;
    }
    
    static boolean[] mark = new boolean[256];
  }
}
