import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();

        List<Integer> list = new ArrayList<Integer>();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int p = sc.nextInt();
            list.add(p);

            if(i > 0){
                int diff = list.get(i) - list.get(i - 1);
                if(diff >= t){
                    ans += t;
                }else{
                    ans += diff;
                }
            }
        }

        ans += t;
        System.out.println(ans);
    }
}