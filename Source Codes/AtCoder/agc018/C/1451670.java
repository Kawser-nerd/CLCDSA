import java.util.Scanner;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main{
  static final long INF = Long.MAX_VALUE / 2;
  static int x, y, z;
  static int[] a, b, c;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    x = sc.nextInt();
    y = sc.nextInt();
    z = sc.nextInt();
    int n = x + y + z;
    a = new int[n];
    b = new int[n];
    c = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
      b[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }

    long sumA = 0;
    for(int i = 0; i < n; i++){
      sumA += a[i];
      b[i] = b[i] - a[i];
      c[i] = c[i] - a[i];
    }

    Block[] blocks = new Block[n];
    for(int i = 0; i < n; i++){
      blocks[i] = new Block(b[i], c[i]);
    }

    Arrays.sort(blocks);

    long[] max1 = new long[n + 1];
    long sum1 = 0;
    PriorityQueue< Integer > pq1 = new PriorityQueue< >();
    for(int i = 0; i < n; i++){
      sum1 += blocks[i].c;
      pq1.offer(blocks[i].c);
      if(pq1.size() > z){
        sum1 -= pq1.poll();
      }
      max1[i] = sum1;
    }

    long[] max2 = new long[n];
    long sum2 = 0;
    PriorityQueue< Integer > pq2 = new PriorityQueue< >();
    for(int i = n - 1; i >= 0; i--){
      sum2 += blocks[i].b;
      pq2.offer(blocks[i].b);
      if(pq2.size() > y){
        sum2 -= pq2.poll();
      }
      max2[i] = sum2;
    }

    long max = -INF;
    for(int i = z - 1; i + y - 1 < n; i++){
      if(i + 1 < n){
        max = Math.max(max, max1[i] + max2[i + 1]);
      }
    }

    System.out.println(sumA + max);
  }

  static class Block implements Comparable< Block >{
    int b, c;

    Block(int b, int c){
      this.b = b;
      this.c = c;
    }

    @Override
      public int compareTo(Block block){
        return (b - c) - (block.b - block.c);
      }
  }
}