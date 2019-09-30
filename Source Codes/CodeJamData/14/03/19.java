import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;



public class Q0C {

	int cn;
	Child[] ch;

	public static void main(String[] args) throws ExecutionException, Throwable{
		JFileChooser jfc = new JFileChooser("./iofile");
		jfc.setFileFilter(new FileNameExtensionFilter(null, "in"));
		while(jfc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION);
		File fi = jfc.getSelectedFile();
		String fo = fi.getPath();
		fo = fo.substring(0, fo.length() - 2) + "out";
		PrintStream ps = new PrintStream(fo);
		
		Q0C q = new Q0C();
		q.ReadInput(fi);
		
		boolean large = fi.getName().contains("large");
		q.PrintOutput(ps, large);
		ps.close();
	}
	
	void ReadInput(File fi) throws IOException{
		Scanner in = new Scanner(fi);
		Scanner line = new Scanner(in.nextLine());
		cn = line.nextInt();
		line.close();
		ch = new Child[cn];
		for(int c = 0; c < cn; c++){
			ch[c] = new Child(in);
		}
		in.close();
	}
	
	
	void PrintOutput(PrintStream ps, boolean large) throws IOException, Throwable, ExecutionException{
		if(large){
			ExecutorService exec = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
			Future[] fc = new Future[cn];
			for(int c = 0; c < cn; c++){
				fc[c] = exec.submit(ch[c]);
			}
			exec.shutdown();
			for(int c = 0; c < cn; c++){
				while(!fc[c].isDone())
					Thread.sleep(10000);
				ps.format("Case #%d:\n%s", c + 1, ch[c].result);
			}
		}
		else{
			for(int c = 0; c < cn; c++){
				ch[c].run();
				ps.format("Case #%d:\n%s", c + 1, ch[c].result);
			}
		}
	}
	
	static class Child implements Runnable{
		String result = "";
		boolean t;
		int row;
		int col;
		int safe;
		int sol[];
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			row = line.nextInt();
			col = line.nextInt();
			if(row < col){
				safe = row;
				row = col;
				col = safe;
				t = true;
			}else
				t = false;
			safe = row * col - line.nextInt();
			line.close();
			sol = new int[row];
		}
		
		int singleline(int zero){
			if(zero == 0)
				return 0;
			else if(zero == col)
				return col;
			else
				return zero + 1;
		}
		
		int count(int[] zero){
			int sum = singleline(zero[0]);
			for(int i: zero)
				sum += singleline(i);
			if(zero.length == row)
				sum -= singleline(zero[row - 1]);
			return sum;
		}
		
		int[] recursive(int r, int c, int s){
			int[] res = new int[r];
			if(r == 0 || c > 1 && s == 1)
				return null;
			if(s <= c){
				res[0] = s;
				return res;
			}
			int cmin = s / r;
			if(c > 1 && cmin < 2)
				cmin = 2;
			for(int i = c; i >= cmin; --i){
				int[] temp = recursive(r - 1, i, s - i);
				if(temp != null){
					res[0] = i;
					for(int j = 0; j < r - 1; ++j)
						res[j+1] = temp[j];
					return res;
				}
			}
			return null;
		}
		
		boolean special(){
			if(safe == 1){
				sol[0] = 1;
				return true;
			}
			return false;
		}
		
		boolean Calc(){
			int r = row - 2;
			if(special())
				return true;
			int cmax = safe / 2;
			int cmin = col > 1 ? 2 : 1;
			cmax = cmax > col ? col : cmax;
			for(int i = cmax; i >= cmin; --i){
				if(safe == 2 * i){
					sol[0] = sol[1] = i;
					return true;
				}
				int[] temp = recursive(r, i, safe - 2 * i);
				if(temp != null){
					sol[0] = sol[1] = i;
					for(int j = 0; j < r; ++j)
						sol[j+2] = temp[j];
					return true;
				}
			}
			return false;
		}
		
		@Override
		public void run() {
			if(!Calc()){
				result = "Impossible\n";
				return;
			}
			char[][] mat = t ? new char[col][row] : new char[row][col];
			for(char[] a: mat)
				Arrays.fill(a, '*');
			if(t)
				for(int i = 0; i < row; ++i)
					for(int j = 0; j < sol[i]; ++j)
							mat[j][i] = '.';
			else
				for(int i = 0; i < row; ++i)
					for(int j = 0; j < sol[i]; ++j)
							mat[i][j] = '.';
			StringBuilder sb = new StringBuilder();
			mat[0][0] = 'c';
			for(char[] a: mat)
				sb.append(a).append('\n');
			result = sb.toString();
		}
		
	}
}