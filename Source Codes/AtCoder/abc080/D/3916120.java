import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        boolean[][] str = new boolean[c][100001];
        boolean[][] end = new boolean[c][100001];
        int[] plus = new int[100001], sub = new int[1000001];
        for(int i = 0; i < n; i++){
            int x = sc.nextInt() - 1, y = sc.nextInt() - 1, z = sc.nextInt() - 1;
            str[z][x] = true;
            end[z][y] = true;
            plus[x]++;
            sub[y+1]++;
        }
        for(int i = 0; i < c; i++){
            for(int j = 0; j < 100001; j++){
                if(str[i][j] && end[i][j]){
                    plus[j]--;
                    sub[j+1]--;
                }
            }
        }
        int tmp = plus[0], ans = plus[0];
        for(int i = 1; i < 100001; i++){
            tmp = tmp + plus[i] - sub[i];
            ans = Math.max(ans, tmp);
        }
        System.out.println(ans);
    }
}