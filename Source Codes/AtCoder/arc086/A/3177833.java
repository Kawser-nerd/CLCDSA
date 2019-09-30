import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] anum = new int[n];
        for(int i=0; i<n; i++){
            anum[sc.nextInt() - 1]++;
        }
        sc.close();

        int ans = 0;
        Arrays.sort(anum);
        for(int i=0; i<n; i++){
            if(k > 0){
                k--;
            }else{
                ans += anum[n-i-1];
            }
        }

        System.out.println(ans);
    }
}