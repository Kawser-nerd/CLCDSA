import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;
class Main{

    private static int bitcount(long n){
        int res = 0;
        while(n>0){
            if((n & 1) == 1)++res;
            n/=2;
        }
        return res;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        long N = scan.nextLong();

        int maxbit = -1;
        long n = N;
        while(n>0){
            n/=2;
            ++maxbit;
        }

        Deque<Integer> first = new ArrayDeque<>();
        List<Integer> second= new ArrayList<>();
        for(int i=maxbit;i>0;--i){
            first.addLast(i);
            second.add(i);
        }
        //N = 2^maxbit + 2^(maxbit-k) + ...
        //(maxbit, maxbit-1, ..., 1)

        Deque<Integer> useNumber = new ArrayDeque<>();
        for(int i = bitcount(N)-1;i>0;--i){
            useNumber.addLast(maxbit + i);
            first.addFirst(maxbit + i);
        }
        //useNumber = {maxbit + k, maxbit+(k-1), ..., maxbit + 1 }
        //first = {maxbit+1, maxbit+2,..., maxbit+k, maxbit, maxbit-1, ..., 1 }

        for(int i = maxbit-1;i>=0;--i){
            if(((N>>i)&1) == 1){
                int inn = useNumber.removeFirst();
                second.add(second.indexOf(i+1)+1, inn);
            }
        }
        List<Integer> ans = new ArrayList<>();
        ans.add(100);
        while(!first.isEmpty()){
            ans.add(first.removeFirst());
        }
        for(int i : second)ans.add(i);
        ans.add(100);

        System.out.println(ans.size());
        for(int i : ans)System.out.print(i + " ");
        System.out.println();

    }
}