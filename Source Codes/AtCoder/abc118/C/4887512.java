import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(),
            min = (int)Math.pow(10, 9)+1;
        int[] A = new int[N];
        for(int i = 0; i < N; i++){
            A[i] = sc.nextInt();
        }
        int gcd = gcd(A[0], A[1]);
        for(int i = 2; gcd > 1 && i < N; i++){
            gcd = gcd(gcd, A[i]);
        }
        System.out.println(gcd);
    }

    public static int gcd(int a, int b){        
        if(b < a){
            int c = a;
            a = b;
            b = c;
        }
        int r;
        while((r = b%a) > 0){
            b = a;
            a = r;
        }
        return a;
    }   
}