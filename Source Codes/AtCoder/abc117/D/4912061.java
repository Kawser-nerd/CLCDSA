import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long K = sc.nextLong();
    long[] a = new long[N];
    for (int i = 0; i < N; i++) {
      a[i] = sc.nextLong();
    }
    Main abc117D = new Main();
    System.out.println(abc117D.solve(N, K, a));
  }

  public long solve(int N, long K, long[] a){
    int MAX_BIT = 39;
    int[] oneBitNums = new int[MAX_BIT + 1];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= MAX_BIT; j++) {
        if ((a[i] >> j & 1) == 1) {
          oneBitNums[j]++;
        }
      }
    }

    int[] xBits = new int[MAX_BIT + 1];
    for (int i = MAX_BIT; i >= 0; i--) {
      if (oneBitNums[i] <= N / 2) {
        xBits[i] = 1;
      }
    }

    long X = 0;
    for (int i = MAX_BIT; i >= 0; i--) {
      if (xBits[i] == 1) {
        long num = (long) Math.pow(2.0, i);
        // K???????
        if (X + num <= K) {
          X += num;
        }
      }
    }

    long ans = 0;
    for (int i = 0; i < N; i++) {
      ans += X ^ a[i];
    }
    return ans;
  }

//  public long solve(int N, long K, long[] a) {
//    List<Boolean> kBits = longToBits(K);
//    int[] aggregate = bitAggregate(kBits.size(), a);
//    long xor = bestXor(N, aggregate, kBits);
//
//    long ans = 0;
//    for (long x : a) {
//      ans += x ^ xor;
//    }
//    return ans;
//  }
//
//  private long bestXor(int N, int[] aggregate, List<Boolean> kBits) {
//    int N2 = N / 2;
//    long xor1 = 0;
//    long xor2 = 0;
//    long sum1 = 0;
//    long sum2 = 0;
//    for (int i = 0; i < aggregate.length; i++) {
//      boolean off = aggregate[i] <= N2;
//      long b = 1 << i;
//      if (kBits.get(i) && off) {
//        xor1 += b;
//        sum1 += b * (N - aggregate[i]);
//      } else {
//        sum1 += b * aggregate[i];
//      }
//      if (off && i < aggregate.length - 1) {
//        xor2 += b;
//        sum2 += b * (N - aggregate[i]);
//      } else {
//        sum2 += b * aggregate[i];
//      }
//    }
//    if (sum1 > sum2) {
//      return xor1;
//    } else {
//      return xor2;
//    }
//  }
//
//  private int[] bitAggregate(int len, long[] a) {
//    int[] ret = new int[len];
//    for (long x : a) {
//      long num = x;
//      int i = 0;
//      while (i < len) {
//        if ((num >> i & 1) == 1)
//          ret[i] += 1;
//        i++;
//      }
//    }
//    return ret;
//  }
//
//  private List<Boolean> longToBits(long K) {
//    List<Boolean> bools = new ArrayList();
//    while (K > 0) {
//      if ((K & 1) == 1) bools.add(true);
//      else bools.add(false);
//      K = K >> 1;
//    }
//    return bools;
//  }

  public long solveBack(int N, long K, long[] a) {
    int N2 = N / 2;
    long defaultBits = ~0;
    List<Long> xorBits = new ArrayList();
    List<Boolean> bitsOn = new ArrayList();
    long b = 1;
    while (K >= b) {
      xorBits.add(b);
      if ((K & b) > 0) bitsOn.add(true);
      else bitsOn.add(false);
      defaultBits = defaultBits ^ b;
      b = b << 1;
    }
    int bitLen = xorBits.size();
    int[] bitsAggregate = new int[bitLen];


    long defaultSum = 0;
    for (long x : a) {
      defaultSum += defaultBits & x;
      for (int z = 0; z < xorBits.size(); z++) {
        if ((xorBits.get(z) & x) > 0) {
          bitsAggregate[z] += 1;
        }
      }
    }

    long xor1 = 0;
    long xor2 = 0;
    long sum1 = 0; // ????bit?1
    long sum2 = 0; // ????bit?0
    b = 1;
    for (int j = 0; j < bitsAggregate.length; j++) {
      boolean off = bitsAggregate[j] <= N2;
      if (bitsOn.get(j) && off) {
        xor1 += b;
        sum1 += b * (N - bitsAggregate[j]);
      } else {
        sum1 += b * bitsAggregate[j];
      }
      if (off && j < bitsAggregate.length - 1) {
        xor2 += b;
        sum2 += b * (N - bitsAggregate[j]);
      } else {
        sum2 += b * bitsAggregate[j];
      }
      b = b << 1;
    }
    long xor = xor1;
    if (sum1 > sum2) {
//      xor = xor1;
//      return defaultSum+sum1;
    } else {
//      xor = xor2;
//      return defaultSum+sum2;
    }
    long ans = 0;
    for (long x : a) {
      ans += x ^ xor;
    }
    return ans;
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.