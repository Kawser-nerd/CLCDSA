import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        final int m = (int)Math.sqrt(M);
        boolean[] prm = new boolean[m+1];
        for(int i = 2;i < m+1;i++)  prm[i] = true;
        for(int i = 2;i < m+1;i++){
            if(prm[i]){
                for(int j = 2*i;j < m+1;j += i) prm[j] = false;
            }
        }
        int[] L1 = new int[m+1];
        int[] L2 = new int[m+1];
        int id = 0;
        int M2 = M;
        for(int i = 2;i < m+1;i++){
            if(prm[i] && M2%i == 0){
                L1[id] = i;
                while(M2%i == 0){
                    L2[id]++;
                    M2 /= i;
                }
                id++;
            }
            if(i == m && M2 > 1){
                L1[id] = M2;
                L2[id]++;
                id++;
            }
        }
        int p = solve(1, L1, L2, 0, N, id);
        System.out.println(M/p);
    }
    public static int solve(int a, int[] l1, int[] l2, int ind, int n, int l){
        if(ind == l){
            if(a >= n)  return a;
            else    return 1000000007;
        }else{
            int min = 1000000007;
            for(int i = 0;i <= l2[ind];i++){
                min = Math.min(solve(a*(int)Math.pow(l1[ind], i), l1, l2, ind+1, n, l), min);
            }
            return min;
        }
    }
}