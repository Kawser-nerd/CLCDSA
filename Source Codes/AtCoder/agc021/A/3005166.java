import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String moto=sc.next();
		if(moto.length()>1) {
			int aa=Integer.parseInt(moto.charAt(0)+"");
			int keta=moto.length()-1;

			int sonomama=0;

			for(int i=0; i<moto.length(); i++) {
				sonomama+=Integer.parseInt(moto.charAt(i)+"");
			}
			System.out.println(Math.max(keta*9+aa-1,sonomama));
		}
		else if(moto.length()==1) {
			System.out.println(moto);
		}
	}
}