import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] a = new int[N];
    int[] b = new int[N + 1];
    int[] c = new int[N];
    for(int i = 1; i < N + 1; i++) {
      b[i] = i;
    }
    for(int i = 0; i < N; i++) {
      a[i] = sc.nextInt();
      b[a[i]]--;
      if(b[a[i]] >= 0) c[b[a[i]]]++;
    }
    int L = 0;
    for(int i = 0; i < N; i++) {
      if(c[i] == 0) L++;
    }
    for(int i = 0; i < M; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      if(b[a[x - 1]] >= 0) c[b[a[x - 1]]]--;
      if(b[a[x - 1]] >= 0 && c[b[a[x - 1]]] == 0) L++;
      b[a[x - 1]]++;
      a[x - 1] = y;
      b[y]--;
      if(b[y] >= 0 && c[b[y]] == 0) L--;
      if(b[y] >= 0) c[b[y]]++;
      System.out.println(L);
    }
  }
}