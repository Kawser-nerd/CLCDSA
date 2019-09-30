import java.util.*;

public class Main {
  public static void main(String[] args){
      
    Scanner sc = new Scanner(System.in);    

    int N = sc.nextInt();
                 
    long[] t = new long[N];
    long[] a = new long[N];
    
    for(int i = 0;i < N;i++){
        t[i] = sc.nextLong();
        a[i] = sc.nextLong();
    }

    long ct = t[0];
    long ca = a[0];
    
    for(int i = 1;i < N;i++){
        long kt = ct/t[i] + (ct%t[i] > 0 ?1 :0);
        long ka = ca/a[i] + (ca%a[i] > 0 ?1 :0);
        long k = Math.max(kt,ka);
        ct = k*t[i];
        ca = k*a[i];
    }
    
    System.out.println(ct + ca);    
      
  }  
}