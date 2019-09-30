import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();
        int cnt = 0;
        for(int i = 0; i <= k; i++){
            for(int h = 0; h <= k; h++){
                    if(s - i - h <= k && s >= i + h){
                        cnt++;
                    }
                }
            }
        System.out.println(cnt);
    }
}