import java.util.*;
public class Main{
        public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int  N = Integer.parseInt(sc.next());
	Set<Integer> stick = new HashSet<Integer>();
	    int dupli[] = new int[N];
	
	 Arrays.fill(dupli,0);
	for(int i = 0;i < N;i++){
	     int  in = Integer.parseInt(sc.next());
	     if(!(stick.add(in))){
		 dupli[i] = in;
		 stick.remove(in);
		}
	}
	Arrays.sort(dupli);
        long  ans = dupli[N - 1];
	ans   *=  dupli[N - 2];
	System.out.println(ans);
	}
}