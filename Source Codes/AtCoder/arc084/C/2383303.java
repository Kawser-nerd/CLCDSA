import java.io.PrintWriter;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Scanner;

class Main{

    static int K;
    static int N;

    static void dec(Deque<Integer> list){
        //??N????????????
        if(list.peekLast()==1)list.pollLast();
        else{
            list.addLast(list.pollLast()-1);
            while(list.size()<N)list.addLast(K);
        }
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        K = scan.nextInt();
        N =scan.nextInt();
        Deque<Integer> ans = new ArrayDeque<>();
        if(K%2==0){
            ans.add(K/2);
            while(N-->1)ans.add(K);
        }else{
            for(int i=0;i<N;++i)ans.add((K+1)/2);
            for(int i=0;i<(N/2);++i)dec(ans);
        }
        PrintWriter pw = new PrintWriter(System.out);
        StringBuffer sb = new StringBuffer();
        for(int i : ans)if(i!=0)sb.append(i+" ");
        System.out.println(sb.toString());
    }
}