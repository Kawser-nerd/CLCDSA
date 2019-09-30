import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;

@SuppressWarnings("unchecked")
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        long[] a = new long[N];
        for(int i=0;i<N;++i)a[i]=scan.nextLong();
        List<Integer> posIndex[] = new ArrayList[2];
        for(int i=0;i<2;++i)posIndex[i]=new ArrayList<>();
        for(int i=0;i<N;++i)if(a[i]>=0)posIndex[i%2].add(i);
        if(posIndex[0].isEmpty()&&posIndex[1].isEmpty()){
            int minIndex = 0;
            for(int i=0;i<N;++i)if(a[i]>a[minIndex])minIndex=i;
            System.out.println(a[minIndex]);
            System.out.println(N-1);
            for(int i=N;i>minIndex+1;--i)System.out.println(i);
            for(int i=0;i<minIndex;++i)System.out.println(1);
        }else{
            long ans = Long.MIN_VALUE;
            List<Integer> index = new ArrayList<>();
            for(int i=0;i<2;++i){
                long sum=0;
                for(int j : posIndex[i])sum+=a[j];
                if(sum>ans){
                    ans = sum;
                    index = posIndex[i];
                }
            }
            System.out.println(ans);
            List<Integer> list = new ArrayList<>();
            for(int i=N;i>index.get(index.size()-1) +1;--i)list.add(i);
            for(int i=0;i<index.get(0);++i)list.add(1);
            for(int i=0;i<index.size()-1;++i){
                int num = (index.get(i+1) - index.get(i) -1)/2;
                while(num-->0)list.add(3);
                list.add(2);
            }
            System.out.println(list.size());
            for(int i : list)System.out.println(i);
        }
    }
}