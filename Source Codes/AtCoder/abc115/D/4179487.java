import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long X = sc.nextLong();
        System.out.println(eatPatty(X, N));
    }

    static long layerTotal(int N) {
        if(N == 0) return 1;
        else return 2*layerTotal(N-1) + 3;
    }

    static long pattyTotal(int N) {
        if(N == 0) return 1;
        else return 2*pattyTotal(N-1) + 1;
    }

    static long eatPatty(long X, int N) {
        if(N == 0) 
            return 1;
        else {
            if(X == 1) 
                return 0;
            else if(1 < X && X <= layerTotal(N-1)+1) 
                return eatPatty(X-1, N-1);
            else if(X == 2+layerTotal(N-1)) 
                return pattyTotal(N-1) + 1;
            else if(2+layerTotal(N-1) < X && X <= 2*layerTotal(N-1)+2) 
                return pattyTotal(N-1) + 1 + eatPatty(X-2-layerTotal(N-1), N-1);
            else 
                return 2*pattyTotal(N-1) + 1;
        }
    }
}