import java.util.*;
import java.lang.*;
import java.io.*;
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
    public static Pair<Integer,Integer> numToCood(int H, int W, int n){
        int h = n/(2*W);
        int w = n%(2*W);
        if(w<W) return new Pair<>(2*h,w);
        else return new Pair<>(2*h+1,2*W-w-1);
    }
    public static void printArray(int[] array){
        int W = array.length;
        for(int w=0;w<W;w++){
        	System.out.print(array[w]);
        	if(w==W-1)System.out.println();
        	else System.out.print(" ");
        }
    }
    public static void printArray(int[][] array){
        int H = array.length;
        for(int h=0;h<H;h++) printArray(array[h]);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int n=0;n<N;n++) a[n]=sc.nextInt();
        int[][] grid = new int[H][W];
        int color=1;
        int painted=0;
        for(int i=0;i<H*W;i++){
        	if(painted<a[color-1]){
        	    Pair<Integer,Integer> cood = numToCood(H,W,i);
        	    grid[cood.getFirst()][cood.getSecond()] = color;
        	    painted++;
        	}else{
        	    color++;
        	    painted=0;
        	    i--;
        	}
        }
        printArray(grid);
    }
}