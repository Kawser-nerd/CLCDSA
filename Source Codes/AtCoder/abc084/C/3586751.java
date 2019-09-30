import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int n = N-1;
        int[][] ary = new int[n][3];
        int[] ans = new int[N];
        ans[n] = 0;
        for(int i = 0; i < n; i++){
        	ary[i][0] = sc.nextInt();
        	ary[i][1] = sc.nextInt();
        	ary[i][2] = sc.nextInt();
        }
        for(int i = 0; i < n; i++){
        	ans[i] = ary[i][1] + ary[i][0];
        	for(int j = i+1; j < n; j++){
        		ans[i] = Math.max(ans[i], ary[j][1]);
        		ans[i] = ((ans[i] - 1) / ary[j][2] + 1) * ary[j][2];
            	ans[i] += ary[j][0];
        	}
        }
        for(int num : ans){
        	System.out.println(num);
        }
    }
}