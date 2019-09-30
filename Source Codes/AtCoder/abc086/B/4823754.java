import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
String st=Integer.toString(b);
int suu=st.length();

int c=1;

for(int i=1;i<=suu;i++){
	c=c*10;
}
c=a*c+b;
double y=c;
double x=Math.sqrt(y);

if(x%1==0){
	System.out.println("Yes");
}else{
	System.out.println("No");
}

	}}