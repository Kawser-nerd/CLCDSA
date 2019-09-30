import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Here your code !
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] yo = Arrays.asList(br.readLine().split(" ")).stream().mapToInt(Integer::parseInt).toArray();
        int r = yo[0];
        int g = yo[1];
        int b = yo[2];
        long ans = 1252521830252521L;
        final int OH = 1500;
        int[] arr = new int[OH];
        for(int gl = -1000;gl<=700;gl++){
            long cnt = 0;
            for(int i=0;i<g;i++){
                cnt += Math.abs(gl+i);
            }
            // red
            {
                for(int i=0;i<OH;i++){
                    int p = gl-1-i;
                    arr[i] = Math.abs(p-(-100));
                }
                Arrays.sort(arr);
                for(int i=0;i<r;i++){
                    cnt += arr[i];
                }
            }
            // blue
            {
                for(int i=0;i<OH;i++){
                    int p = gl+g+i;
                    arr[i] = Math.abs(p-(100));
                }
                Arrays.sort(arr);
                for(int i=0;i<b;i++){
                    cnt += arr[i];
                }
            }
            ans = Math.min(ans, cnt);
        }
        System.out.println(ans);
    }
}