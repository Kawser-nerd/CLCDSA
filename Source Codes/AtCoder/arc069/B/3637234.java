import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        sc.close();

        boolean[] ans = new boolean[n];
        boolean[] ani = new boolean[n];
        for(int i=0; i<n; i++){
            ans[i] = s.charAt(i) == 'o';
        }

        ani[0] = true;
        ani[1] = true;
        if(setAndCheck(n, ans, ani)){
            print(n, ani);
            return;
        }

        ani[0] = true;
        ani[1] = false;
        if(setAndCheck(n, ans, ani)){
            print(n, ani);
            return;
        }

        ani[0] = false;
        ani[1] = true;
        if(setAndCheck(n, ans, ani)){
            print(n, ani);
            return;
        }

        ani[0] = false;
        ani[1] = false;
        if(setAndCheck(n, ans, ani)){
            print(n, ani);
            return;
        }

        System.out.println(-1);
    }

    static boolean setAndCheck(int n, boolean[] ans, boolean[] ani){
        boolean ret = true;
        for(int i=1; i<n-1; i++){
            if(ani[i] == ans[i]){
                ani[i+1] = ani[i-1];
            }else{
                ani[i+1] = !ani[i-1];
            }
        }

        if(ani[0] == ans[0]){
            ret = ani[1] == ani[n-1];
        }else{
            ret = ani[1] != ani[n-1];
        }
        if(!ret) return false;

        if(ani[n-1] == ans[n-1]){
            ret = ani[n-2] == ani[0];
        }else{
            ret = ani[n-2] != ani[0];
        }

        return ret;
    }

    static void print(int n, boolean[] ani){
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++){
            if(ani[i]){
                sb.append('S');
            }else{
                sb.append('W');
            }
        }
        System.out.println(sb.toString());
    }
}