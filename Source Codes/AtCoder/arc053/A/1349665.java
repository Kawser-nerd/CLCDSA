import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static int getInt(){
		return Integer.parseInt(s.next());
	}
	public static void main(String[] __){
		int x=getInt(),y=getInt();
		System.out.println((x-1)*y+x*(y-1));
	}
}