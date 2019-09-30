import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t[] = new int[n];

        for(int i = 0; i < n; i++){
          t[i] = sc.nextInt();
        }

        int m = sc.nextInt();
        int sum[] = new int[m];
        int p=0; //?????????????
        int x=0; //???????????????
        for(int j = 0; j < m; j++){
          p = sc.nextInt();
          x = sc.nextInt();
           int temp = t[p-1];
           t[p-1] = x;
           for(int k = 0; k < n; k++){
             sum[j] += t[k];
           }
           t[p-1] = temp;
        }
        for(int l = 0; l < m; l++){
          System.out.println(sum[l]);
        }
    }
}