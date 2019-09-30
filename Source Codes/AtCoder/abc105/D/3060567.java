import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[] a = new int[n];
    for(int i=0;i<n;++i)a[i]=sc.nextInt()%m;
    for(int i=1;i<n;++i)a[i]=(a[i]+a[i-1])%m;
    Map<Integer, Integer> cnt = new HashMap<>();
    cnt.put(0,1);
    long ans = 0;
    for(int i=0;i<n;++i){
      ans += (long)cnt.getOrDefault(a[i], 0);
      cnt.put(a[i], cnt.getOrDefault(a[i], 0)+1);
    }
    System.out.println(ans);
  }
}