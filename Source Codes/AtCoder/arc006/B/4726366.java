import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Main{
	static int[] amida;
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String a=br.readLine();
		String[] b=a.split(" ");
		int N=Integer.parseInt(b[0]);
		int L=Integer.parseInt(b[1]);
		amida=new int[N];
		for(int i=0; i<N; i++) {
			amida[i]=i+1;
		}
		for(int i=0; i<L; i++) {
			String s=br.readLine();
			//pl(s);
			for(int j=0; j<N-1; j++) {
				if(s.charAt(2*j+1)=='-') {
					swap(j);
				}
			}
		}
		String s=br.readLine();
		for(int i=0; i<N; i++) {
			if(s.charAt(2*i)=='o') {
				pl(amida[i]);
				break;
			}
		}
	}
	static void swap(int p) {
		int a=amida[p];
		amida[p]=amida[p+1];
		amida[p+1]=a;
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}