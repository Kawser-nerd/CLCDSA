import java.util.Arrays;
import java.util.Scanner;

public class Main{
    void solve(){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] s = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++){
            s[i] = in.nextInt();
            sum += s[i];
        }
        
        if(sum % 10 != 0){
            System.out.println(sum);
            return;
        }else{
            Arrays.sort(s);
            int i = 0;
            while(sum%10==0 && i < n){
                if(s[i]%10 != 0){
                    sum -= s[i];
                }
                i++;
            }
            if(i == n){
                sum = 0;
            }
        }
        System.out.println(sum);
    }
    
    public static void main(String[] args){
        new Main().solve();
    }
}