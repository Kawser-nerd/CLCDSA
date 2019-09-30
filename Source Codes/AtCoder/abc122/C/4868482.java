import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(),
            Q = sc.nextInt();
        String S = sc.next();
        int[] l = new int[Q],
              r = new int[Q];
        for(int i = 0; i < Q; i++){
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        char[] letter = S.toCharArray();
        int[] ac = new int[N+1];
        ac[0] = 0;
        for(int i = 1; i < N; i++){
            ac[i] = ac[i-1];
            if(letter[i-1] == 'A'){
                if(letter[i] == 'C'){
                    ac[i]++;
                }
            }
        }
        for(int i = 0; i < Q; i++){
            System.out.println(ac[r[i]-1] - ac[l[i]-1]);
        }        
    }
}