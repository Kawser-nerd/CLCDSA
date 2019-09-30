import java.util.*;

public class Main{
	public static void main(String[] argv){
		ManyFormals.run();
	}
}

class ManyFormals{
	public static void run(){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		boolean[] flag = new boolean[s.length()-1];
		System.out.println(bits(flag, 0, s));
	}
	//flag?true?????+???????????????index, 
	public static long bits(boolean[] flag, int index, String s){
		if(flag.length == index)
			return getSum(flag, s);
		else{
			long sum = 0;
			flag[index]=true;
			sum += bits(flag, index+1, s);
			flag[index]=false;
			sum += bits(flag, index+1, s);
			return sum;
		}
	}
	public static long getSum(boolean[] flag, String s){
		long sum=0;
		int start = 0;
		for(int i=0;i<flag.length;i++){
			if(flag[i]){
				sum += Long.parseLong(s.substring(start, i+1));
				start = i+1;
			}
		}
		sum += Long.parseLong(s.substring(start, s.length()));
		return sum;
	}
}