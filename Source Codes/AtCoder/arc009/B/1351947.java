import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Here your code !
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 1?????????int???????????????????(?????)
        int[] b = Arrays.asList(br.readLine().split(" ")).stream().mapToInt(Integer::parseInt).toArray();
        int[] x = new int[10];
        for(int i=0;i<10;i++)x[b[i]] = i;
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for(int i=0;i<n;i++){
            String s = br.readLine();
            // ????????????
            a[i] = 0;
            for(int j=0;j<s.length();j++){
                a[i] *= 10;
                a[i] += x[s.charAt(j)-'0'];
            }
            // System.out.println(s + "->" + a[i]);
        }
        Arrays.sort(a);
        for(int i=0;i<n;i++){
            // ????
            StringBuilder sb = new StringBuilder();
            int t = a[i];
            if(t==0){
                System.out.println(0);
                continue;
            }
            while(t > 0){
                sb.append(b[t%10]);
                t/=10;
            }
            sb.reverse();
            System.out.println(sb.toString());
        }
    }
}