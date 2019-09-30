import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemD {
    final static String PROBLEM_NAME = "problem_D";
    final static String WORK_DIR = "C:\\GCJ\\" + PROBLEM_NAME + "\\";

    int N, D, K;
    int ansL, ansR;

    void updateAnswer(int candL, int candR) {
        int ansLen = ansR - ansL;
        int candLen = candR - candL;
        if (candLen > ansLen || candLen == ansLen && candL < ansL) {
            ansL = candL;
            ansR = candR;
        }
    }

    boolean matches(int[] A, int[] nums) {
        for (int i=0; i<D; i++) for (int j=0; j<K; j++)
            if (A[i] == nums[j]) return true;
        return false;
    }

    void extend(int[][] A, int[] nums, int globalL, int globalR, int L, int R, int pos) {
        while (L > globalL && matches(A[L-1 - globalL], nums)) L--;
        while (R < globalR && matches(A[R+1 - globalL], nums)) R++;
        updateAnswer(L, R);
        if (pos < K) {
            if (L > globalL) {
                for (int pp = 0; pp < D; pp++) {
                    nums[pos] = A[L-1 - globalL][pp];
                    extend(A, nums, globalL, globalR, L, R, pos+1);
                    nums[pos] = -1;
                }
            }
            if (R < globalR) {
                for (int pp = 0; pp < D; pp++) {
                    nums[pos] = A[R+1 - globalL][pp];
                    extend(A, nums, globalL, globalR, L, R, pos+1);
                    nums[pos] = -1;
                }
            }
        }
    }

    void rec(int[][] A, int L, int R) {
        if (L == R) {
            updateAnswer(L, R);
            return;
        }
        int mid = (L + R) / 2;
        if (L < mid) {
            int[][] left = new int[mid - L][];
            for (int i=L; i < mid; i++) left[i-L] = A[i-L].clone();
            rec(left, L, mid-1);
        }
        if (R > mid) {
            int[][] right = new int[R - mid][];
            for (int i=mid+1; i <= R; i++) right[i-mid-1] = A[i-L].clone();
            rec(right, mid+1, R);
        }

        int[] nums = new int[] {-1, -1, -1};
        for (int pp = 0; pp < D; pp++) {
            nums[0] = A[mid - L][pp];
            extend(A, nums, L, R, mid, mid, 1);
            nums[0] = -1;
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        N = sc.nextInt();
        D = sc.nextInt();
        K = sc.nextInt();
        int[][] A = new int[N][D];
        for (int i=0; i<N; i++) for (int j=0; j<D; j++) A[i][j] = sc.nextInt();
        ansL = N-1; ansR = N-1;
        rec(A, 0, N-1);
        pw.println(ansL + " " + ansR);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemD().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
