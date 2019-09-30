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
import java.util.HashSet;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;



public class Q0A {

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
		
		Q0A q = new Q0A();
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
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
		else{
			for(int c = 0; c < cn; c++){
				ch[c].run();
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
	}
	
	static class Child implements Runnable{
		String result = "";
		HashSet<Integer> foo, bar;
		
		HashSet<Integer> inputset(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			int first = line.nextInt();
			line.close();
			for(int i = 1; i < first; ++i)
				in.nextLine();
			line = new Scanner(in.nextLine());
			HashSet<Integer> set1 = new HashSet<Integer>();
			while(line.hasNextInt())
				set1.add(line.nextInt());
			line.close();
			for(int i = first; i < 4; ++i)
				in.nextLine();
			
			return set1;
		}
		
		Child(Scanner in){
			foo = inputset(in);
			bar = inputset(in);
		}
			
		@Override
		public void run() {
			foo.retainAll(bar);
			if(foo.size() == 0)
				result = "Volunteer cheated!";
			else if(foo.size() > 1)
				result = "Bad magician!";
			else
				result = foo.iterator().next().toString();
		}
		
	}
}