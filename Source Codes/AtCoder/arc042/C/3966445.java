import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    static long mod = 1000000000+7;
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int P = sc.nextInt();
        Item[] dic = new Item[n];
        for(int i=0;i<n;i++) dic[i] = new Item(sc.nextInt(),sc.nextInt());
        Arrays.sort(dic);
        int[] dp = new int[P+101];
        Arrays.fill(dp,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            Item cur = dic[i];
            for(int j=P;j>=0;j--){
                if(dp[j]==-1) continue;
                dp[j+cur.price] = Math.max(dp[j+cur.price],dp[j]+cur.value);
            }
        }
        int ans = 0;
        for(int i=0;i<=P+100;i++) ans = Math.max(ans,dp[i]);
        System.out.println(ans);
    }
    static class Item implements Comparable<Item>{
        int price,value;
        public Item(int p, int v){
            this.price = p; this.value = v;
        }
        public int compareTo(Item o){
            return o.price-this.price;
        }
    }
}