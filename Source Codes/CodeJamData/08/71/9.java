import java.io.*;
import java.util.*;

public class ProblemA {

   class Node {
      String name;
      ArrayList<Node> children;
      public Node(String s) {
         name = s;
         children = new ArrayList<Node>();
      }
      void addChild(Node child) {
         children.add(child);
      }
      boolean isBasic() {
         return Character.isLowerCase(name.charAt(0));
      }
   }

   HashMap<String,Node> map;

   public ProblemA() throws Exception {
      Scanner sc = new Scanner(new File("A-small-attempt1.in"));
      //PrintWriter pw = new PrintWriter(System.out);
      PrintWriter pw = new PrintWriter("C:/Documents and Settings/codejam/Desktop/A-small-out.txt");
      int C = Integer.parseInt(sc.nextLine());
      for (int i=1; i<=C; i++) {
         int nMixtures = Integer.parseInt(sc.nextLine());
         Node root = null;
         map = new HashMap<String,Node>();
         for (int j=0; j<nMixtures; j++) {
            String[] data = parseStringArray(sc.nextLine());
            Node node = getNode(data[0]);
            if (j==0) root = node;
            for (int k=2; k<data.length; k++) {
               Node child = getNode(data[k]);
               node.addChild(child);
            }
         }
         int ans = go(root);
         pw.println("Case #" + (i) + ": "  + (ans));
      }
      pw.flush();
      pw.close();
   }

   Node getNode(String name) {
      if (map.containsKey(name)) return map.get(name);
      Node ret = new Node(name);
      map.put(name, ret);
      return ret;
   }

   int go(Node node) {
      if (node.isBasic()) return 0;
      int ret01 = 1; // for this bowl
      ArrayList<Integer> x = new ArrayList<Integer>();
      for (Node child: node.children) {
         if (!child.isBasic()) ret01++;
         int rec = go(child);
         x.add(rec);
      }
      Collections.sort(x);
      int largest = x.get(x.size()-1);
      int ties = 0;
      for (int y: x) if (y==largest) ties++;
      int ret02 = largest + ties - 1;
      int ret = Math.max(ret01, ret02);
      //System.out.println("To make " + node.name + ", you need " + ret + " bowls");
      return ret;
   }

   int[] parseIntArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      int[] ret = new int[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = Integer.parseInt(st.nextToken());
      }
      return ret;
   }

   String[] parseStringArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      String[] ret = new String[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = st.nextToken();
      }
      return ret;
   }

   public static void main(String[] args) {
      try {
         new ProblemA();
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
}
