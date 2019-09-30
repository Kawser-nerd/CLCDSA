import java.util.Scanner;
public class Main{

	public static void main(String[] args){
		//writeInput();
		solve();
		}

	public static void solve(){
		Scanner sc = new Scanner(System.in);

		long K =Long.parseLong(sc.next());
		int N = 50;
		long m = K/N;
		long r = K%N;
		
		long[] a = new long[N];
		for(int i=0;i<N-(int)r;i++)a[i]=m+N-r-1;
		for(int i=N-(int)r;i<N;i++)a[i]=m+2*N-r;
		
		answer(N,a);
		sc.close();

	}

	public static void answer(long N, long[] a){
		System.out.println(N);
		System.out.print(a[0]);
		for(int i=1;i<N;i++)System.out.print(" "+a[i]);
		System.out.println();
	}


/*	public static void writeInput(){
		try{
			File file = new File("c:\\Users\\jugem\\Documents\\pleiades\\input.dat");
			if (checkBeforeWritefile(file)){
				PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)));
				pw.println("1234567894848");
				pw.close();
			}
		}catch(IOException e){
			System.out.println(e);
		}
	}

	public static boolean checkBeforeWritefile(File f){
		return f.exists()?(f.isFile()&&f.canWrite()):false;
	}
*/
}