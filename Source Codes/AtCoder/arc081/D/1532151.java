import java.util.Scanner;
import java.util.Stack;

public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int[][] mat = new int[h][w];
    long max = Math.max(h, w);

    for (int i=0; i<h; i++) {
      char[] tmp = sc.next().toCharArray();
      for (int j=0; j<w; j++) {
        if (tmp[j]=='#')
          mat[i][j] = 1;
        else
          mat[i][j] = 0;
      }
    }
    sc.close();

    boolean[][] n_mat = new boolean[h-1][w-1];
    for (int i=0; i<h-1; i++) {
      for (int j=0; j<w-1; j++) {
        if ((mat[i][j]+mat[i+1][j]+mat[i][j+1]+mat[i+1][j+1])%2==0)
          n_mat[i][j]=true;
        else
          n_mat[i][j]=false;
      }
    }

    int[][] hist = new int[h-1][w-1];
    for (int i=0; i<h-1; i++) {
      for (int j=0; j<w-1; j++) {
        if (n_mat[i][j]) {
          if (i==0) {
            hist[i][j]=1;
          } else {
            hist[i][j]=hist[i-1][j]+1;
          }
        } else {
          hist[i][j]=0;
        }
      }
    }

    Stack<int[]> stack = new Stack<>();
    for (int i=0; i<h-1; i++) {
      if (!stack.isEmpty()) {
        for (int[] tmp: stack) {
          max = Math.max(max, (long)(tmp[0]+1)*(w-tmp[1]));
        }
        stack.clear();
      }

      for (int j=0; j<w-1; j++) {
        int th = hist[i][j];
        if (th==0) {
          for (int[] tmp: stack) {
            max = Math.max(max, (long)(tmp[0]+1)*(j-tmp[1]+1));
          }
          stack.clear();
          continue;
        }

        if (stack.isEmpty()) {
          stack.push(new int[]{th,j});
          continue;
        }

        if (th==stack.peek()[0])
          continue;

        if (th>stack.peek()[0]) {
          stack.push(new int[]{th,j});
          continue;
        }

        Stack<int[]> mini = new Stack<>();
        while (!stack.isEmpty()) {
          int[] tmp = stack.pop();
          if (th>tmp[0]) {
            stack.push(tmp);
            break;
          }
          mini.push(tmp);
        }
        if (!mini.isEmpty()) {
          if (th==mini.peek()[0]) {
            stack.push(mini.pop());
          } else {
            int tw = mini.peek()[1];
            stack.push(new int[]{th,tw});
          }
          for (int[] tmp: mini) {
            max = Math.max(max, (long)(tmp[0]+1)*(j-tmp[1]+1));
          }
          mini.clear();
        }
      }
    }
    if (!stack.isEmpty()) {
      for (int[] tmp: stack) {
        max = Math.max(max, (long)(tmp[0]+1)*(w-tmp[1]));
      }
      stack.clear();
    }

    System.out.println(max);
  }
}