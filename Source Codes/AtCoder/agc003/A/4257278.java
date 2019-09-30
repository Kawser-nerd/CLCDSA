import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	String a=scan.next();
	boolean fig1=false;
	boolean fig2=false;
	boolean fig3=false;
	boolean fig4=false;
	for(int i=0;i!=a.length();i++) {
		char ch=a.charAt(i);
		switch(ch) {
		case 'S':fig1=true;break;
		case 'E':fig2=true;break;
		case 'N':fig3=true;break;
		case 'W':fig4=true;break;
		}
	}
	boolean ans=false;
	if(fig3&&fig1&&fig2==false&&fig4==false){
		ans=true;
	}
	if(fig3==false&&fig1==false&&fig2&&fig4){
		ans=true;
	}
	if(fig1&&fig2&&fig3&&fig4) {
		ans=true;
	}
	System.out.println(ans?"Yes":"No");
	scan.close();
	}
}