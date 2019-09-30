import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] nums1 = new int[n][n];
        int[] nums2 = new int[n];
        for (int i = 1; i < n; i++) {
            nums2[i] = sc.nextInt();
        }
        int[] lengths = new int[n];
        for (int i = 1; i < n; i++) {
            nums1[nums2[i] - 1][lengths[nums2[i] - 1]] = i;
            lengths[nums2[i] - 1]++;
        }
        int[] outputs = new int[n];
        for (int i = 0; i < n; i++) {
            outputs[i] = 1;
        }
        int maxtmp = 0;
        int mintmp = 0;
        for (int i = n; i > 0; i--) {
            maxtmp = 0;
            mintmp = 0;
            for (int j = 0; j < lengths[i - 1]; j++) {

                if (outputs[nums1[i - 1][j]] > maxtmp) {
                    maxtmp = outputs[nums1[i - 1][j]];
                }
                if (outputs[nums1[i - 1][j]] < mintmp || mintmp == 0) {
                    mintmp = outputs[nums1[i - 1][j]];
                }
            }
            outputs[i - 1] += maxtmp;
            outputs[i - 1] += mintmp;
        }
        System.out.println(outputs[0]);
    }
}