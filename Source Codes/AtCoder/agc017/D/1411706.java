/**
 * @author Finn Lidbetter
 */
import java.util.*;
import java.io.*;
import java.awt.geom.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    int n = Integer.parseInt(br.readLine());
    Node[] nodes = new Node[n];
    for (int i=0; i<n; i++) {
      nodes[i] = new Node(i);
    }
    for (int i=0; i<n-1; i++) {
      String[] s = br.readLine().split(" ");
      int a = Integer.parseInt(s[0])-1;
      int b = Integer.parseInt(s[1])-1;
      nodes[a].adj.add(nodes[b]);
      nodes[b].adj.add(nodes[a]);
    }
    if (solve(nodes[0],-1)!=0) {
      System.out.println("Alice");
    } else {
      System.out.println("Bob");
    }


  }
  static int solve(Node a, int from) {
    if (a.adj.size()==1 && a.i!=0) {
      return 0;
    }
    int ans = 0;
    for (Node n:a.adj) {
      if (n.i!=from) {
        ans ^= 1+solve(n,a.i);
      }
    }
    //System.out.println("Answer for "+a.i+": "+ans);
    return ans;
  }
}
class Node {
  int i;
  ArrayList<Node> adj;
  public Node(int ii) {
    i = ii;
    adj = new ArrayList<Node>();
  }
}