import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Here your code !
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // int[] b = Arrays.asList(br.readLine().split(" ")).stream().mapToInt(Integer::parseInt).toArray();
        int n = Integer.parseInt(br.readLine());
        int[] x = new int[n], y = new int[n];
        for(int i=0;i<n;i++){
            String[] s = br.readLine().split(" ");
            x[i] = Integer.parseInt(s[0]);
            y[i] = Integer.parseInt(s[1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)for(int j=0;j<i;j++)for(int k=0;k<j;k++){
            long ax = x[k] - x[i]; long ay = y[k] - y[i];
            long bx = x[j] - x[i]; long by = y[j] - y[i];
            long s2 = Math.abs(ax*by - ay*bx);
            if(s2>0 && s2%2==0){
                ans++;
            }
        }
        System.out.println(ans);
    }
}