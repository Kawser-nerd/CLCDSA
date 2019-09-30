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
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = scanner.nextInt();
    }
    int now = a[0];
    int count = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(a[i] == now){
        now = a[i];
        count++;
      }
      if(a[i] != now){
        ans += count/2;
        count = 1;
        now = a[i];
      }
      if(i == n-1){
        ans += count/2;
      }
      //System.out.println(count);
    }
    System.out.println(ans);

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