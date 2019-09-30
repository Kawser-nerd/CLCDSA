import java.util.*;
import java.io.*;
import java.math.*;

public class c {

  static boolean[][] board;
  static boolean[][] used;
  static int M;
  static int N;
  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    String str;
    String haha = "0123456789ABCDEF";
    int numCases = Integer.parseInt(br.readLine());

    for (int nCase = 1; nCase <= numCases; nCase++) {
      String[] sa = br.readLine().split(" ");
       M = Integer.parseInt(sa[0]);
       N = Integer.parseInt(sa[1]);
   // true = white
     board = new boolean[M][N];
      for (int i = 0; i < M; i++) {
        str = br.readLine();
        for (int j = 0, nn = 0; j < str.length(); j++, nn += 4) {
          int val = haha.indexOf(str.charAt(j));
          board[i][nn] = ((val & 8) != 0);
          board[i][nn+1] = ((val & 4) != 0);
          board[i][nn+2] = ((val & 2) != 0);
          board[i][nn+3] = ((val & 1) != 0);
        }
      }
      // true if already cut
      used = new boolean[M][N];
      ArrayList<ArrayList<Point>> grids = new ArrayList<ArrayList<Point>>();
      int biggestGridSize = Math.min(M,N);
      for (int i = 0; i <= biggestGridSize; i++) {
        grids.add(new ArrayList<Point>());
      }
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          grids.get(1).add(new Point(i,j));
        }
      }
      for (int i = 2; i <= biggestGridSize; i++) {
        for (int j = 0; j < grids.get(i-1).size(); j++) {
          Point p = grids.get(i-1).get(j);
          if (check(p.x, p.y, i)) {
            //grids.get(i-1).remove(j);
            //j--;
            grids.get(i).add(p);
          }
        }
      }
      /*
      for (int i = 1; i < grids.size(); i++) {
        System.out.println(i + ": " + grids.get(i));
      }
      for (int i = 0;i<M;i++) {
        System.out.println(Arrays.toString(board[i]));
      }
      */
      int numSize = 0;
      int[] count = new int[biggestGridSize+1];
      for (int i = biggestGridSize; i >= 1; i--) {
        ArrayList<Point> pts = grids.get(i);
        boolean yes = false;
        for (int j = 0; j < pts.size(); j++) {
          Point pt = pts.get(j);
          if (fillIfNotUsed(pt.x, pt.y, i)) {
            if (!yes) {
              yes = true;
              numSize++;
            }
            count[i]++;
          }
        }
      }
      System.out.println("Case #" + nCase + ": " + numSize);
      for (int i = biggestGridSize; i >= 1; i--) {
        if (count[i] > 0) {
          System.out.println(i + " " + count[i]);
        }
      }
    }
    br.close();

    }

  public static boolean fillIfNotUsed(int x, int y, int size) {
    for (int xx = x; xx < x+size; xx++) {
      for (int yy = y; yy < y+size; yy++) {
        if (used[xx][yy])
          return false;
      }
    }
    for (int xx = x; xx < x+size; xx++) {
      for (int yy = y; yy < y+size; yy++) {
        used[xx][yy] = true;
      }
    }
    return true;
  }
  
  public static boolean check(int x, int y, int newSize) {
    int newX = x + newSize - 1;
    int newY = y + newSize - 1;
    if (newX < M && newY < N) {
      if (board[newX-1][y] != board[newX][y]) {
        for (int i = 0; i < newSize-1; i++) {
          // new horizontal strip
          if (board[newX][y+i] == board[newX][y+i+1]) {
            //if (x == 0 && y == 10) System.out.println("at 0 10 fail: h strip failed");
            return false;
          }
        }
      }
      else { 
        //if (x == 0 && y == 10) System.out.println("at 0 10 fail: new edge wron colot");
        return false;
      }
      if (board[x][newY-1] != board[x][newY]) {
        for (int i = 0; i < newSize-1; i++) {
          // new vertical strip
          if (board[x+i][newY] == board[x+i+1][newY]) {
            //if (x == 0 && y == 10) System.out.println("at 0 10 fail: v strip failed");
            return false;
          }
        }
      }
      else {
        //if (x == 0 && y == 10) System.out.println("at 0 10 fail: new edge wron colot");
        return false;
      }   
      return true;
    }
    //if (x == 0 && y == 10) System.out.println("at 0 10 fail: bounds");
    return false;
  }
  
}

class Point {
  int x;
  int y;
  public Point(int x, int y) {
    this.x = x;
    this.y = y;
  }
  public String toString() {
    return ("(" + x + "," + y + ")");
  }
}
