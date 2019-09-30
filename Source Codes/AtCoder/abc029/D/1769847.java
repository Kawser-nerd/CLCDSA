import java.util.*;

class Main {
    static long ones(long n){
        long c=0;
        while(n>0){
            if(n%10==1)c++;
            n/=10;
        }
        return c;
    }
    static long f(long n) {
        if(n<=0)return 0;
        long total = 0;
        long r = n % 10;
        if (r >= 2)
            total++;
        total+=10*f(n/10);
        total+=n/10;
        return total+ones(n/10)*r;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.println(f(n+1));
    }
}