import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.HashMap;
import java.util.TreeSet;
import java.util.Comparator;

public class Main {
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    long[] a = new long[n];
    long[] b = new long[n];
    int count = 0;
    for(int i = 0; i < n; i++){
      a[i] = scanner.nextLong();
    }
    Arrays.sort(a);
    b[0] = a[0];
    for(int i = 1; i < n; i++){
      b[i] = b[i-1] + a[i];
    }
    int index = -1;
    for(int i = n-1; i >= 1; i--){
      if(a[i] > b[i-1] * 2){
        index = i;
        break;
      }
    }
    if(index >= 0){
      System.out.println(n-index);
    }else{
      System.out.println(n);
    }
  }

  static class Edge{
    int to;
    int cost;
    Edge(int to, int cost){
      this.to = to;
      this.cost = cost;
    }
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
        return (x == p.x ? y - p.y : x - p.x) * -1; //x???????
        //return y == p.y ? x - p.x : y - p.y;//y???????
        //return (y == p.y ? x - p.x : y - p.y)*-1;//y???????
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