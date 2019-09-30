import java.util.*;
import java.lang.*;
import java.io.*;
class Counter<T> extends HashMap<T,Integer>{
    public Counter(){
        super();
    }
    public Counter(T[] array){
        super();
        for(int i=0;i<array.length;i++) add(array[i]);
    }
    public Integer get(Object elm){
        return getOrDefault(elm,0);
    }
    public void add(T elm){
        put(elm, get(elm)+1);
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Integer[] A = new Integer[N];
        for(int n=0;n<N;n++)A[n]=sc.nextInt();
        Counter<Integer> count = new Counter(A);
        if((N-count.size())%2==0) System.out.println(count.size());
        else System.out.println(count.size()-1);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.