import java.util.*;

class Main{

    public static void puts(char[][] str){
	for(int i=0;i<str.length;i++){
	    for(int j=0;j<str[i].length;j++){
		System.out.print(str[i][j]);
	    }
	    System.out.print('\n');
	}
	return;
    }
    
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int h=sc.nextInt();
	int w=sc.nextInt();
	char[][] a=new char[h][w];
	for(int i=0;i<h;i++){
	    a[i]=(sc.next()).toCharArray();
	}
	char[][] b=new char[h][w];
	char[][] r=new char[h][w];
	for(int i=0;i<h;i++){
	    for(int j=0;j<w;j++){
		if(j==0){
		    b[i][j]='#';
		    r[i][j]='.';
		}
		else if(j==w-1){
		    b[i][j]='.';
		    r[i][j]='#';
		}
		else{
		    if(i%2==0){
			b[i][j]='.';
			r[i][j]='#';
		    }
		    else{
			b[i][j]='#';
			r[i][j]='.';
		    }
		}
	    }
	}
	for(int i=0;i<h;i++){
	    for(int j=0;j<w;j++){
		if(a[i][j]=='#'){
		    r[i][j]='#';
		    b[i][j]='#';
		}
	    }
	}
	puts(b);
	puts(r);

	return;
    }
    
}