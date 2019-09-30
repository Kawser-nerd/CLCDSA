import java.util.*;
public class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int a[] = new int[M];
        int b[] = new int[M];
        
        for(int i=0; i<M; i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        
        HashMap<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for(int i=1; i<=N; i++){
        cnt.put(i, 0);
        }
        
        for(int i=0; i<M; i++){
        cnt.put(a[i], cnt.get(a[i])+1);
        cnt.put(b[i], cnt.get(b[i])+1);
        }
        
        for(int key=1; key<N+1; key++){
            int sum = cnt.get(key);
            System.out.println(sum);
        }
        
    }
}