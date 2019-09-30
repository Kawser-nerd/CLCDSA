import java.util.*;
import java.math.*;
import java.io.PrintStream;
import java.io.ByteArrayOutputStream;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Main{
  public Myout myout;
  public void solve(int problem_number){
    this.myout = Myout.get(problem_number);
    Scanner sc = TaskSplitter.sc;
    Lock lock = TaskSplitter.lock;
    //read phase
    int n = sc.nextInt();
		int [][] data = new int[n][3];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				data[i][j] = sc.nextInt();
			}
		}
    //read ends
    lock.unlock();
    //execution start
		int max = 0;
    for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int a = data[i][0];
				int b = data[j][1];
				int c = 10000 - a - b;
				if(c < 0){
					continue;
				}
				int sat = 0;
				for(int k = 0; k < n; k++){
					if(a >= data[k][0] && b >= data[k][1] && c >= data[k][2]){
						sat++;
					}
				}
				if(sat > max){
					max = sat;
				}
			}
		}
		myout.println(max);

  }
  public static void main(String [] argv){
    //long t1 = System.currentTimeMillis();
    Scanner sc = new Scanner(System.in);
    TaskSplitter.sc = sc;
    int n = sc.nextInt();
    TaskSplitter.tasksize = n;
    Thread [] threads = new Thread[TaskSplitter.NUM_THREADS];
    for(int i = 0; i < TaskSplitter.NUM_THREADS; i++){
      threads[i] = new Thread(new TaskSplitter());
      threads[i].start();
    }
    for(int i = 0; i < TaskSplitter.NUM_THREADS; i++){
      try{
        threads[i].join();
      }catch(InterruptedException e){
        System.err.println(e);
      }
    }  
    Myout.flushAll();
    //long t2 = System.currentTimeMillis();
    //System.err.println(((double)t2 - t1) / 1000.);
  }
}

class TaskSplitter implements Runnable{
  public final static int NUM_THREADS = 8;
  public static int tasksize;
  public static int now = 0;
  static Scanner sc;
  public static ReentrantLock lock;
  static{
    lock = new ReentrantLock();
  }
  public void run(){
    while(true){
      lock.lock();
      if(now >= tasksize)
        break;
      //exec
      int problem_num = now;
      now++;
      Main main = new Main();
      main.solve(problem_num);
      main.myout.ins_flush();
    }
    lock.unlock(); // important
  }
}



class Myout extends PrintStream implements Comparable<Myout>{
  public int num;
  private static LinkedList<Myout> list;
  private ByteArrayOutputStream out;
  static{
    list = new LinkedList<Myout>();
  }
  private Myout(ByteArrayOutputStream out, int problem_number){
    super(out);
    this.num = problem_number;
    this.out = out;
  }
  public static Myout get(int problem_number){
    Myout out = new Myout(new ByteArrayOutputStream(), problem_number);
    list.add(out);
    return out;
  }
  public void ins_flush(){
    System.err.printf("Case #%d: " + out, this.num + 1);
  }
  public static void flushAll(){
    Collections.sort(list);
    for(Myout m: list){
      System.out.printf("Case #%d: " + m.out, m.num + 1);
    }
  }
  public int compareTo(Myout m){
    return this.num - m.num;
  }
}

