import java.io.*;
import java.util.*;
public class Main {
    static long mod;
    static long modpow(int a,int b){
        if(b == 0)return 1;
        long temp = modpow(a,b/2);
        temp = temp*1L*temp % mod;
        if((b & 1) == 1)
            temp = temp*a % mod;
        return temp;
    }
    public static void main(String[] args)throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int array[] = new int[n + 1];
        mod = (long)1E9 + 7;
        int cnt[] = new int[n];
        for(int i = 1;i <= n;i++) {
            array[i] = Integer.parseInt(st.nextToken());
            cnt[array[i]]++;
        }
        if((n & 1) == 1){
            for(int i = 2;i < array.length;i+=2){
                if(cnt[i] != 2 || cnt[0] != 1){
                    System.out.println("0");
                    return;
                }
            }
            long ways = modpow(2,n/2);
            System.out.println(ways);
        }
        if((n & 1) == 0){
            //System.out.println((n & 1) == 0);
            for(int i = 1;i < array.length;i+=2){
                if(cnt[i] != 2){
                    System.out.print("0");
                    return;
                }
            }
            long ways = modpow(2,n/2);
            System.out.print(ways);
        }
    }
    }