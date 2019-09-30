import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt(),
            B = sc.nextInt(),
            K = sc.nextInt();
        int n = gcd(A, B),
            count = 0,
            num = 0;
        while(count < K){
            if(n%++num == 0){
                count++;
            }
        }
        System.out.println(n/num);
    }
        public static int gcd(int a, int b){
        if(a > b){
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