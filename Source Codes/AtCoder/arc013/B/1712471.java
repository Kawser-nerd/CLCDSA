import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int C = sc.nextInt();
        int[] nml = new int[3];
        int[] maxNml = new int[3];

        for(int i = 0; i < C; i++) {
            for(int j = 0; j < 3; j++)
                nml[j] = sc.nextInt();

            Arrays.sort(nml);

            for(int j = 0; j < 3; j++)
                maxNml[j] = Math.max(maxNml[j], nml[j]);
        }

        int ans = maxNml[0] * maxNml[1] * maxNml[2];
        System.out.println(ans);
    }
}