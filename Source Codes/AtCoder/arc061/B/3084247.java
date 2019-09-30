import java.util.*;
import java.lang.*;
import java.io.*;
class Counter<T> extends HashMap<T,Integer>{
    public Counter(){
        super();
    }
    public Integer get(Object elm){
        return getOrDefault(elm,0);
    }
    public void add(T elm){
        put(elm, get(elm)+1);
    }
    
}
class Pair<E,F>{
    E first;
    F second;
    public Pair(E first, F second){
        this.first=first;
        this.second=second;
    }
    public E getFirst(){return first;}
    public F getSecond(){return second;}
    public String toString(){
        return "<"+first.toString()+","+second.toString()+">";
    }
    public int hashCode(){
        return first.hashCode()*30011+second.hashCode()+2;
    }
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Pair another = (Pair) obj;
        return this.getFirst().equals(another.getFirst())&&this.getSecond().equals(another.getSecond());
    }
}

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long H = sc.nextLong();
        long W = sc.nextLong();
        int N = sc.nextInt();
        Counter<Pair<Long,Long>> count = new Counter<>();
        for(int n=0;n<N;n++){
        	long A = sc.nextLong();
        	long B = sc.nextLong();
        	for(long a=A-1;a<=A+1;a++)for(long b=B-1;b<=B+1;b++){
        	    if(a>=2 && a<=H-1 && b>=2 && b<=W-1)
        	        count.add(new Pair<Long,Long>(a,b));
        	}
        }
        long[] ans = new long[10];
        ans[0] = (H-2)*(W-2);
        for(Pair<Long,Long> p:count.keySet()){
        	ans[count.get(p)]++;
        	ans[0]--;
        }
        for(int i=0;i<10;i++) System.out.println(ans[i]);
        
    }
}