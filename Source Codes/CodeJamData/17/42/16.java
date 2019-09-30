import java.util.*;

class B {
    public static void main (String [] arg) {
        Scanner sc = new Scanner(System.in);
        int TT = sc.nextInt();
        for (int ii = 1; ii<= TT; ++ii) {
            int N = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            int [] COUNT = new int [C+1];
            int [] coast = new int [N+1];
            for (int i = 0; i<M; ++i) {
                int pos = sc.nextInt();
                int buyer = sc.nextInt();
                COUNT[buyer]++;
                coast[pos]++;
            }
            int min = 0;
            for (int i =0; i<COUNT.length; ++i) {
                if (COUNT[i] > min) min = COUNT[i];
            }
            min = Math.max(min, coast[1]);
            int max = M;
            while (min < max) {
                int piv = (min + max)/2;
                int promotions = canDo(coast, piv);
                if (promotions >= 0) {
                    if (max == piv) System.err.println("whoops");
                    max = piv;
                } else {
                    min = piv+1;
                }
            }
            if (min != max) System.err.println("never");
            int ans = canDo(coast, max);
            
            System.out.printf("Case #%d: %d %d\n", ii, max, ans);
        }
    }
    
    public static int canDo(int [] coast, int R) {
        int slots_available = 0;
        int promotions = 0;
        for (int i = 1; i<coast.length; ++i) {
            if (coast[i] > R) {
                if (coast[i] - R > slots_available) {
                    return -1;
                }
                int p = (coast[i] - R);
                slots_available -= p;
                promotions += p;
            } else if (coast[i] == R) {
                //continue
            } else {
                slots_available += R - coast[i];
            }   
        }
        return promotions;
    }
}