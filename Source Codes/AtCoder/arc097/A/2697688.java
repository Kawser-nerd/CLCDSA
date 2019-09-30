import java.util.*;
public class Main {
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
String K=sc.next();
int length = K.length();
int N=sc.nextInt();
Set<String> set = new HashSet<>();

	for (int i = 1; i <= N; i++) {
           for (int j = 0; j <=  length- i; j++){
           		set.add(K.substring(j, j+i));
                
    		}
    	}
List<String> list = new ArrayList<>(set);
    Collections.sort(list);
    System.out.println(list.get(N-1));
}
}