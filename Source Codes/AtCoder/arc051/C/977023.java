import java.util.*;
import java.math.*;

class Node implements Comparable<Node> {
  static BigInteger a;

  BigInteger bi;
  int original;
  int count;

  public Node(BigInteger bi, int original, int count) {
    this.bi = bi;
    this.original = original;
    this.count = count;
  }

  public int compareTo(Node node) {
    return this.bi.compareTo(node.bi);
  }

  public Node getNext() {
    return new Node(bi.multiply(a), original, count+1);
  }
}

public class Main {
  private static long MOD = 1000000007;

  private static long mul(long a, long b) {
    return (a * b) % MOD;
  }

  private static long pow(long a, long b) {
    if (b == 0) {
      return 1;
    }
    if (b % 2 == 0) {
      long v = pow(a, b/2);
      return mul(v, v);
    } else {
      long v = pow(a, b/2);
      return mul(mul(v, v), a);
    }
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int a = s.nextInt();
    int b = s.nextInt();
    if (a == 1) {
      int[] value = new int[n];
      for (int i = 0; i < n; i++) {
        value[i] = s.nextInt();
      }
      Arrays.sort(value);
      for (int v : value) {
        System.out.println(v);
      }
      return;
    }
    Node.a = new BigInteger("" + a);
    PriorityQueue<Node> queue = new PriorityQueue<Node>();
    for (int i = 0; i < n; i++) {
      int original = s.nextInt();
      queue.add(new Node(new BigInteger("" + original), original, 0));
    }
    int count = 0;
    while(count < n && b > 0) {
      Node node = queue.poll();
/*
      System.out.println("---");
      System.out.println(node.bi);
      System.out.println(node.original);
      System.out.println(node.count);
*/
      if (node.count == 0) {
        count++;
      }
      b--;
      queue.add(node.getNext());
    }
    ArrayDeque<Long> result = new ArrayDeque<Long>();
    while(!queue.isEmpty()) {
      Node node = queue.poll();
//      System.out.println(node.bi);
//      System.out.println(mul(node.original, pow(a, node.count + b/n)));
      result.add(mul(node.original, pow(a, node.count + b/n)));
    }
    b -= (b/n)*n;
    while(b > 0) {
      long value = result.pollFirst();
//      System.out.println(value);
      result.offerLast(mul(value, a));
      b--;
    }
    while(!result.isEmpty()) {
      System.out.println(result.removeFirst());
    }
  }
}