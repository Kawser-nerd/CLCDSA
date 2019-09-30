import java.util.ArrayDeque;
import java.util.Scanner;
import java.util.stream.IntStream;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int[] a = new int[N];
        for(int i=0;i<N;++i){
            a[i] = scan.nextInt();
        }
        int[] leftl = new int[N];
        int[] rightl = new int[N];

        ArrayDeque<Integer> que = new ArrayDeque<>();
        int index = 0;
        while(index<N){
            while(!que.isEmpty() && a[que.peek()] > a[index]){
                int ind = que.poll();
                rightl[ind] = index-ind -1;
            }
            que.push(index++);
        }
        while(!que.isEmpty()){
            int ind = que.poll();
            rightl[ind] = N - ind -1;
        }

        index = N-1;
        while(index>=0){
            while(!que.isEmpty() && a[que.peek()] > a[index]){
                int ind = que.poll();
                leftl[ind] = ind - index -1;
            }
            que.push(index--);
        }
        while(!que.isEmpty()){
            int ind = que.poll();
            leftl[ind] = ind - index -1;
        }

        long ans = 0;
        for(int i=0;i<N;++i){
            ans += (long)a[i]*(leftl[i]+1)*(rightl[i]+1);
        }
        System.out.println(ans);
    }
}