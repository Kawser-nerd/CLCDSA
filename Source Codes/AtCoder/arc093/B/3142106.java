import java.util.*;

class Main{
	static Scanner s=new Scanner(System.in);
	static char[][]f=new char[40][99];
	public static void main(String[] $){
		for(int i=0;i<20;++i)
			Arrays.fill(f[i],'#');
		for(int i=20;i<40;++i)
			Arrays.fill(f[i],'.');
		f(0,'.');
		f(21,'#');
		System.out.println("40 99");
		Arrays.stream(f).forEach(System.out::println);
	}
	static void f(int b,char c){
		int a=s.nextInt()-1;
		for(int i=0;i<a;++i)
			f[i/50*2+b][i%50*2]=c;
	}
}