import java.util.*;

public class Main {
    static int n, k;
    static int[] a;
    static int modP = 1000000007;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        char[] s = in.next().toCharArray();

        int[] wOnLeftCnt  = new int[n];
        int[] eOnLeftCnt  = new int[n];
        int[] wOnRightCnt = new int[n];
        int[] eOnRightCnt = new int[n];

        int wCnt = 0;
        for(int i = 0; i < n; i++) {
            wOnLeftCnt[i] = wCnt;
            if(s[i] == 'W') {
                wCnt++;
            }
        }

        int eCnt = 0;
        for(int i = n-1; i >= 0; i--) {
            eOnRightCnt[i] = eCnt;
            if(s[i] == 'E'){
                eCnt++;
            }
        }

        int minTurned = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            if(minTurned > wOnLeftCnt[i] + eOnRightCnt[i]) {
                minTurned = wOnLeftCnt[i] + eOnRightCnt[i];
            }

            minTurned = Math.min(minTurned, wOnLeftCnt[i] + eOnRightCnt[i]);
        }

        System.out.println(minTurned);
    }
}