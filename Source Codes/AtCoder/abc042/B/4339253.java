import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int L = sc.nextInt();
        String[] S = new String[N]; 
        
        //????????????????
        for(int i = 0; i < N; i++)S[i] = sc.next();
        Arrays.sort(S);
        
        //?????????????????
        StringBuilder bf = new StringBuilder();
        for(int i = 0; i < N; i++)bf.append(S[i]);
        
        String ans = bf.toString();
        System.out.println(ans);
    }
}