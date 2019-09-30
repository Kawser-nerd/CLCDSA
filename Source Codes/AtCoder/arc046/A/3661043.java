import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int keta=1+(N-1)/9;
		int suji=N%9;
		if(suji==0) {
			suji=9;
		}
		String neta="";
		for(int i=0; i<keta; i++) {
			neta=neta+suji;
		}
		System.out.println(neta);
	}
}