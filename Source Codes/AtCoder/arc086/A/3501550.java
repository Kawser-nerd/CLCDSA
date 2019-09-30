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
        int K = sc.nextInt();
        int[] A = new int[N];
        for(int i=0;i<N;i++) A[i] = sc.nextInt();

        int[] cnt = new int[N+1];
        for(int i=0;i<N;i++) cnt[A[i]]++;
        Arrays.sort(cnt);

        int sum = 0;
        for(int i=0;i<K;i++){
            sum += cnt[N-i];
        }
        System.out.println(N-sum);
    }
}