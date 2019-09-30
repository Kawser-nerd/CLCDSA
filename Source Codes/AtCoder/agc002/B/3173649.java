import java.util.*;
import java.io.*;

public class Main {
    public static int count(boolean[] array){
        int ans = 0;
        for(int i=0;i<array.length;i++)
            if(array[i]) ans++;
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] boll = new int[N];
        boolean[] red = new boolean[N];
        for(int n=0;n<N;n++){
        	boll[n] = 1;
        	red[n]  = (n==0);
        }
        int M = sc.nextInt();
        for(int m=0;m<M;m++){
            int x = sc.nextInt()-1;
            int y = sc.nextInt()-1;
            
            if(red[x]) red[y]=true;
            boll[y]++;
            if(boll[x]<=1) red[x]=false;
            boll[x]--;
        }
        System.out.println(count(red));
    }
}