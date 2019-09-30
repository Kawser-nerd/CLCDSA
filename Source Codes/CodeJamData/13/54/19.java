import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class ObservationWheel {
    static Scanner sc;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
//        sc = new Scanner(System.in);
//        out = new PrintWriter(System.out);

        sc = new Scanner(new FileReader("D-small-attempt0.in"));
        out = new PrintWriter(new FileWriter("D-small-attempt0.out"));

        int testCases = sc.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println(String.format("Case #%s: %s", testCase,
                    solveCase()));
        }
        out.close();
    }

    static double solveCase() {
        String bits = sc.next();
        N = bits.length();
        memo = new double[1<<N];
        Arrays.fill(memo, -1.0);
        
        int init = 0;
        for(int i=0;i<N;i++)
            if(bits.charAt(i)=='X')
                init |= 1<<i;
        return solve(init);
    }
    
    static double solve(int mask) {
        if (mask == (1<<N) - 1) {
            return 0;
        }
        
        if (memo[mask] < -0.5) {
            double res = 0.0;
            for(int index = 0; index < N; index++) {
                for(int wait = 0; wait < N; wait++) {
                    int exactIndex = (index + wait) % N;
                    if((mask>>exactIndex&1)==0) {
                        res += (N - wait + solve(mask|1<<exactIndex)) / N;
                        break;
                    }
                }
            }
            memo[mask] = res;
        }
        return memo[mask];
    }
    static double[] memo;
    static int N;
}
