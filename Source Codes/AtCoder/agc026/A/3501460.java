import java.util.*;
class Main{
    /*
     * ?? -> nextInt() (???????ni())
     * ?? -> next()
     * 1? -> nextLine()
     * ?? : nextLIne?next(),nextInt()???????????????????????????????
     */
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for(int i=0;i<N;i++) A[i] = sc.nextInt();

        int ans = 0;
        for(int i=1;i<N;i++){
            if(A[i] == A[i-1]){
                ans++;
                A[i]=-1; 
            }
        }

        System.out.println(ans);
    }
}