import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	Map<Integer,Integer> map=new TreeMap<Integer,Integer>();
    	int a=sc.nextInt();
    	int []A=new int[a];
    	for(int i=0;i<a;i++) {
    		A[i]=sc.nextInt();
    		map.put(A[i],0);
    	}
    	int count=0;
    	for(int k:map.keySet()) {
    		map.put(k, count++);
    	}
    	for(int i = 0; i < a; i++) {
			System.out.println(map.get(A[i]));
		}
    }
}