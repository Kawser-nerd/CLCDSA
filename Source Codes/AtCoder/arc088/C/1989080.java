import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;

class SegmentTree{
    int N;
    long[] data;

    SegmentTree(int N){
        this.N=1;
        while(this.N<N)this.N*=2;
        data = new long[this.N*2-1];
        Arrays.fill(data,0);
    }

    //0-index
    void add(int index,long value){
        index += N-1;
        data[index] += value;
        while(index>0){
            index = (index-1)/2;
            data[index]+=value;
        }
    }

    private long getSum(int left,int right,int a,int b,int k){
        if(left<=a && b <= right)return data[k];
        if(b<=left || right <= a)return 0;
        return getSum(left,right,a,(a+b)/2,2*k+1) + getSum(left, right,(a+b)/2,b,2*k+2);
    }

    //[left,right)
    long getSum(int left, int right){
        return getSum(left, right,0,N,0);
    }
}

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        Deque<Integer>[] charIndexes = new ArrayDeque[26];
        for(int i=0;i<26;++i)charIndexes[i]=new ArrayDeque<>();
        for(int i=0;i<s.length();++i){
            charIndexes[s.charAt(i) - 'a'].add(i);
        }
        int odd = 0;
        for(int i=0;i<26;++i)if(charIndexes[i].size()%2==1)++odd;
        if(odd>1){
            System.out.println(-1);
            return;
        }
        //??index????????????????????
        //?segtree???
        SegmentTree st = new SegmentTree(s.length());
        long ans=0;
        boolean oddFlag = false;
        for(int i=0;i<s.length();++i){
            int nextc = s.charAt(i)-'a';
            if(charIndexes[nextc].isEmpty() || charIndexes[nextc].getFirst() != i)continue;
            if(charIndexes[nextc].size()==1){
                oddFlag = true;
                continue;
            }
            int f = charIndexes[nextc].removeFirst();
            int l = charIndexes[nextc].removeLast();
            //l?s.length()-1??0??
            ans += (long)(s.length()-1)-l - st.getSum(l, s.length()) +(oddFlag ? 1:0);
            st.add(l,1);
        }
        System.out.println(ans);

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.