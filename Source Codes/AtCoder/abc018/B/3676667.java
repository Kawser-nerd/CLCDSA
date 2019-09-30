import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String unko=sc.next();
		String[] buri=new String[unko.length()+1];
		for(int i=1; i<=unko.length(); i++) {
			buri[i]=unko.charAt(i-1)+"";
		}
		int sousa=sc.nextInt();
		for(int i=0; i<sousa; i++) {
			int f=sc.nextInt();
			int t=sc.nextInt();
			for(int j=f; j<=f+(t-f)/2; j++) {
				String tmp=buri[j];
				buri[j]=buri[t+f-j];
				buri[t+f-j]=tmp;
			}
		}
		String moto="";

		for(int i=1; i<=unko.length();i++) {
			moto=moto+buri[i];
		}
		System.out.println(moto);
	}
}