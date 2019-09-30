import java.util.*;

public class Main {
    static int[] ori ;
    static int N;
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
        char[] s = sc.next().toCharArray();
        ori = new int[N];
        for(int i = 0;i < N;i++){
            if(s[i] ==  'o'){
                ori[i] = 1;
            }else{
                ori[i] = -1;
            }
        }
        int[] res = new int[N];
        //ss
        Arrays.fill(res,0);
        res[0] = 1;
        res[1] = 1;
        if(chal(res)){
            out(res);
            return;
        }
        
        //sw
        Arrays.fill(res,0);
        res[0] = 1;
        res[1] = -1;
        if(chal(res)){
            out(res);
        return;
            
        }
        //ws
        Arrays.fill(res,0);
        res[0] = -1;
        res[1] = 1;
        if(chal(res)){
            out(res);
        return;
            
        }
        //ww
        Arrays.fill(res,0);
        res[0] = -1;
        res[1] = -1;
        if(chal(res)){
            out(res);
        return;
            
        }
        
        System.out.println(-1);
    }
    public static boolean chal(int[] res){
        for(int i = 1; i < N-1; i++){
            res[i + 1] = res[i - 1] * res[i] *  ori[i];
        }
        if(res[N-2] * res[N-1] * ori[N-1] == res[0] 
         &&res[N-1] * res[0] * ori[0] == res[1])return true;
         return false;
    }
    public static void out(int[] res){
        for(int i = 0; i < N;i++){
            char c;
            if(res[i] == 1)c = 'S';
            else c = 'W';
            System.out.print(c);
        }
        System.out.println("");
    }
    
}