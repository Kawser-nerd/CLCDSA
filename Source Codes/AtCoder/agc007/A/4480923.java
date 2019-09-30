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

public class Main {
  static class Point{
    int x;
    int y;
    Point(int x, int y){
      this.x = x;
      this.y = y;
    }
  }
  static int[] dx = {0,1};
  static int[] dy = {1,0};
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int h = scanner.nextInt();
    int w = scanner.nextInt();
    String[] s = new String[h];
    for(int i = 0; i < h; i++){
      s[i] = scanner.next();
    }
    char[][] map = new char[h][w];
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        map[i][j] = s[i].charAt(j);
      }
    }
    int[][] dist = new int[h][w];
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        dist[i][j] = -1;
      }
    }
    Deque<Point> que = new ArrayDeque<Point>();
    que.add(new Point(0,0));
    dist[0][0] = 0;
    while(!que.isEmpty()){
      Point now = que.poll();
      for(int i = 0; i < 2; i++){
        if(now.x+dx[i]<0 || now.x+dx[i]>= h || now.y+dy[i]<0 || now.y+dy[i]>=w) continue;
        if(map[now.x+dx[i]][now.y+dy[i]] == '.') continue;
        if(dist[now.x+dx[i]][now.y+dy[i]] != -1) continue;
        dist[now.x+dx[i]][now.y+dy[i]] = dist[now.x][now.y]+1;
        que.add(new Point(now.x+dx[i], now.y+dy[i]));
      }
    }
    int count = 0;
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        if(map[i][j] == '#'){
          count++;
        }
      }
    }
    if(dist[h-1][w-1] == -1 || count > dist[h-1][w-1]+1){
      System.out.println("Impossible");
    }else{
      System.out.println("Possible");
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