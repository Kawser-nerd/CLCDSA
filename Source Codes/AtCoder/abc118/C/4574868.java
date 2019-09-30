import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        
        int[] i = new int[N];
        
        for(int j = 0; j < N; j++){
            i[j] = Integer.parseInt(sc.next());
        }
        
        long ans = gcd(i[0],i[1]);
        
        for(int j = 2; j < N; j++){
            ans = gcd(ans,i[j]);
        }
        
        System.out.println(ans);
    }
    
    public static long gcd(long a, long b){
        if(b == 0) return a;
        return gcd(b,a%b);
        
        
    }
}