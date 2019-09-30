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
        long[] A = new long[N];
        for(int i=0;i<N;i++) A[i] = sc.nextLong();

        Map<Long,Long> mp = new HashMap<>();
        for(int i=0;i<N;i++){
            if(mp.containsKey(A[i])){
                mp.put(A[i],mp.get(A[i])+1);
            }else{
                mp.put(A[i],1L);
            }
        }

        long ans = 0;
        for(Map.Entry<Long,Long> e : mp.entrySet()){
            long key = e.getKey();
            long val = e.getValue();

            if(key > val) ans += val;
            else if(key < val) ans += (val - key);
        }
        System.out.println(ans);
    }
}