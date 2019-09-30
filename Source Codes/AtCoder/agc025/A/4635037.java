import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeSet;
import java.util.Comparator;

public class Main {
	static int mod = 1000000007;
  static int size = 510000;
	static long[] fac = new long[size];
	static long[] finv = new long[size];
	static long[] inv = new long[size];

  //AGC010-B-Boxes
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int min = Integer.MAX_VALUE;
    for(int a = 1; a <= n-1; a++){
      int A = a;
      int B = n - A;
      int sumA = 0;
      int sumB = 0;
      while(A > 0){
        sumA += A % 10;
        A /= 10;
      }
      while(B > 0){
        sumB += B % 10;
        B /= 10;
      }
      min = Math.min(min,sumA+sumB);
    }
    System.out.println(min);
  }

  //???????
  public static long pow(long x, long n){
    long ans = 1;
    while(n > 0){
      if((n & 1) == 1){
        ans = ans * x;
        ans %= mod;
      }
      x = x * x % mod;
      n >>= 1;
    }
    return ans;
  }

  //fac, inv, finv????????????????initComb()??????
	public static  void initComb(){
		fac[0] = finv[0] = inv[0] = fac[1] = finv[1] = inv[1] = 1;
		for (int i = 2; i < size; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - (mod / i) * inv[(int) (mod % i)] % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}

	//nCk % mod
	public static  long comb(int n, int k){
		return fac[n] * finv[k] % mod * finv[n - k] % mod;
	}

	//n! % mod
	public static  long fact(int n){
		return fac[n];
	}

	//(n!)^-1 with % mod
	public static long finv(int n){
		return finv[n];
	}

  static class Pair implements Comparable<Pair>{
    int x, y;
    Pair(int a, int b){
        x = a;
        y = b;
    }
    @Override
    public boolean equals(Object o){
        if (this == o) return true;
        if (!(o instanceof Pair)) return false;
        Pair p = (Pair) o;
        return x == p.x && y == p.y;
    }
    @Override
    public int compareTo(Pair p){
        //return x == p.x ? y - p.y : x - p.x; //x???????
        //return (x == p.x ? y - p.y : x - p.x) * -1; //x???????
        //return y == p.y ? x - p.x : y - p.y;//y???????
        return (y == p.y ? x - p.x : y - p.y)*-1;//y???????
    }
  }
  static class UnionFind {
    int[] parent;
    public UnionFind(int size) {
      parent = new int[size];
      Arrays.fill(parent, -1);
    }
    public boolean unite(int x, int y) {
      x = root(x);
      y = root(y);
      if (x != y) {
        if (parent[y] < parent[x]) {
          int tmp = y;
          y = x;
          x = tmp;
        }
        parent[x] += parent[y];
        parent[y] = x;
        return true;
      }
      return false;
    }
    public boolean same(int x, int y) {
      return root(x) == root(y);
    }
    public int root(int x) {
      return parent[x] < 0 ? x : (parent[x] = root(parent[x]));
    }
    public int size(int x) {
      return -parent[root(x)];
    }
  }
  public static int upperBound(long[] a,long val){
    return upperBound(a,0,a.length,val);
  }
  public static int upperBound(long[] a,int l,int r,long val){
    if(r-l==1){
      if(a[l]>val) return l;
      return r;
    }
    int mid=(l+r)/2;
    if(a[mid]>val){
      return upperBound(a,l,mid,val);
    }else{
      return upperBound(a,mid,r,val);
    }
  }
  public static int lowerBound(long[] a,long val){
     return lowerBound(a,0,a.length,val);
 }
  public static int lowerBound(long[] a,int l,int r,long val){
    if(r-l==1){
      if(a[l]<val) return r;
      return l;
    }
    int mid=(l+r)/2;
    if(a[mid]<val){
      return lowerBound(a,mid,r,val);
    }else{
      return lowerBound(a,l,mid,val);
    }
  }
}