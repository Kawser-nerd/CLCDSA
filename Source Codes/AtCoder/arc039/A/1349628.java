import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static int getInt(){
		return Integer.parseInt(s.next());
	}
	static IntStream REPS(int r){
		return IntStream.range(0,r);
	}
	static IntStream REPS(int l,int r){
		return IntStream.rangeClosed(l,r);
	}
	static IntStream INTS(int l){
		return REPS(l).map(i->getInt());
	}
	public static void main(String[] __){
		char[]a=s.next().toCharArray(),aa=Arrays.copyOf(a,a.length),
				b=s.next().toCharArray(),bb=Arrays.copyOf(b,b.length);
		for(int i=0;i<aa.length;i++) {
			if(aa[i]!='9') {
				aa[i]='9';
				break;
			}
		}
		if(bb[0]=='1') {
			for(int i=1;i<bb.length;i++) {
				if(bb[i]!='0') {
					bb[i]='0';
					break;
				}
			}
		}else {
			bb[0]='1';
		}
		System.out.println(Math.max(
				miare(aa)-miare(b),
				miare(a)-miare(bb)
				));
	}
	static int miare(char[]c) {
		return Integer.parseInt(String.valueOf(c));
	}
}